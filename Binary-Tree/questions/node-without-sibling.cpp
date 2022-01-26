#include<iostream>
#include"../BinaryTreeNode.h"
#include<stack>
#include<queue>
using namespace std;

BTN<int>* takeInput(){
    int rootData;
    cout<<"Enter the root data: ";
    cin>>rootData;
    if(rootData == -1) return NULL;
    BTN<int>* root = new BTN<int>(rootData);
    queue<BTN<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter the left node of "<<front->data<<": ";
        int leftData;
        cin>>leftData;
        if(leftData != -1){
            BTN<int>* child = new BTN<int>(leftData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout<<"Enter the right node of "<<front->data<<": ";
        int rightData;
        cin>>rightData;
        if(rightData != -1){
            BTN<int>* child = new BTN<int>(rightData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}


void printLevelWise(BTN<int>* root){
    queue<BTN<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        if(front == NULL){
            cout<<endl;
            if(pendingNodes.empty()){
                break;
            } else {
                pendingNodes.push(NULL);
            }
        } else {
            cout<<front->data<<" ";
            if(front->left) pendingNodes.push(front->left);
            if(front->right) pendingNodes.push(front->right);
        }
    }
}

void nodeWithSibling(BTN<int>* root){
    if(!root) return;

    if(root->left && !root->right) cout<<root->left->data<<" ";
    if(root->right && !root->left) cout<<root->right->data<<" ";

    if(root->left) nodeWithSibling(root->left);
    if(root->right) nodeWithSibling(root->right);
    return;
}

int main() {
    BTN<int>* root = takeInput();
    cout<<"level wise"<<endl;
    printLevelWise(root);
    cout<<"Node withoutSubling: ";
    nodeWithSibling(root);
}