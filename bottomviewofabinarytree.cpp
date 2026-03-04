#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

//bottom view of a binary tree
void bottomView(Node* root){
    queue<pair<Node*,int>>q; //node and its horizontal distance
    map<int,int>m; //horizontal distance and node value
    q.push({root,0});
    while(q.size()>0){
        Node* curr=q.front().first;
        int currHd=q.front().second;
        q.pop();

        m[currHd]=curr->data; //update the value at horizontal distance
        
        if(curr->left!=NULL){
            q.push({curr->left,currHd-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right,currHd+1});
        }

    }
    for(auto it:m){
        cout<<it.second<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int>data={1,2,-1,-1,3,4,-1,-1,5, -1,-1};
    Node* root=buildTree(data);
    bottomView(root);

    return 0;
}
