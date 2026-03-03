#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
static int idx=-1;
Node* buildTree(vector<int>data){
    idx++;
    if(data[idx]==-1){
        return NULL;
    }
    Node* root=new Node(data[idx]);
    root->left=buildTree(data);
    root->right=buildTree(data);
    return root;
}

//height of tree
int height(Node*root){
    if(root==NULL){
        return 0;
    }
    int leftHt=height(root->left);
    int rightHt=height(root->right);
    return max(leftHt, rightHt)+1;
}

//count of nodes
int count(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftCount=count(root->left);
    int rightCount=count(root->right);
    return leftCount+rightCount+1;
}

//sum of nodes
int sum(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftSum=sum(root->left);
    int rightSum=sum(root->right);
    return leftSum+rightSum+root->data;
}
int main(){
    vector<int>data={1,2,-1,-1,3,4,-1,-1,5, -1,-1};
    Node* root=buildTree(data);
    //cout<<"Height: "<<height(root);
    //cout<<"Count: "<<count(root);
    cout<<"Sum: "<<sum(root);
    cout<<endl;

    return 0;
}
