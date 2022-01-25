#include<iostream>
#include"../BinaryTreeNode.h"
#include<queue>
using namespace std;

BTN<int>* takeInput(){
    int rootData;
    cout<<"Enter the root Data: ";
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BTN<int>* root = new BTN<int>(rootData);
    queue<BTN<int>* > pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter the left child of "<<front->data<<": ";
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){
            BTN<int>* child = new BTN<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout<<"Enter the right child of "<<front->data<<": ";
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){
            BTN<int>* child = new BTN<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void print(BTN<int>* root){
    queue<BTN<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<": ";
        if(front->left){
            cout<<"L=>"<<front->left->data<<",";
            pendingNodes.push(front->left);
        }
        if(front->right){
            cout<<"R=>"<<front->right->data<<"";
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}

int height(BTN<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root-> right));
}

bool isBalanced(BTN<int>* root){
    if(root == NULL){
        return true;
    }
    int L = height(root->left);
    int R = height(root->right);

    if((L - R == 0) || (L - R == 1) || (L - R == -1)){
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        return (left && right);
    } else {
        return false;
    }
    
}

int main(){
    BTN<int>* root = takeInput();
    print(root);
    // printTree(root);
    cout<<"Is balanced: "<<isBalanced(root);
}