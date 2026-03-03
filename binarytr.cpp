#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node*right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
static int idx=-1;
Node* buildTree(vector<int>Data){
    idx++;
    if(Data[idx]==-1){
        return NULL;
    }
    Node* root=new Node(Data[idx]);
    root->left=buildTree(Data);
    root->right=buildTree(Data);
    return root;
}
//preoder
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//inorder
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//postorder
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

//level order
void levelOrder(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL); //level seperator
    while(q.size()>0){
        Node* curr=q.front();
        q.pop();

        if(curr==NULL){
            if(q.size()>0){
                cout<<endl;
                q.push(NULL);
                continue;;
            }else{
                break;
            }
        }
        
        cout<<curr->data<<" ";

        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;
}
int main(){
    vector<int>Data={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildTree(Data);
    levelOrder(root);
    cout<<endl;


    return 0;
}
