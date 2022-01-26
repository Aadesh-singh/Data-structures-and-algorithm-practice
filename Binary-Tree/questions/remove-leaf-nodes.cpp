#include<iostream>
#include"../BinaryTreeNode.h"
#include<queue>
using namespace std;

BTN<int>* takeInput(){
    int rootData;
    cout<<"Enter the root data: ";
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
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
            front->left= child;
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
void print(BTN<int>* root){
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

BTN<int>* removeLeafNode(BTN<int>* root){
    if(root == NULL){
        return NULL;
    }
    if(root->left){
        if(!root->left->left && !root->left->right){
            BTN<int>* temp = root->left;
            root->left= NULL;
            delete temp;
        }
    }
    if(root->right){
        if(!root->right->left && !root->right->right){
            BTN<int>* temp = root->right;
            root->right = NULL;
            delete temp;
        }
    }

    if(root->left) root->left = removeLeafNode(root->left);
    if(root->right) root->right = removeLeafNode(root->right);

    return root;
}

int main(){
    BTN<int>* root = takeInput();
    cout<<"Before removing lead node: "<<endl;
    print(root);
    cout<<"After Removing leaf node: "<<endl;
    root = removeLeafNode(root);
    print(root);
}