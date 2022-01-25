#include<iostream>
#include"BinaryTreeNode.h"
#include<queue>
using namespace std;

BTN<int>* takeInput(){
    int rootData;
    cout<<"Enter Root data: ";
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BTN<int>* root = new BTN<int>(rootData);
    queue<BTN<int>*> pendingNodes;          //queue for levelwise
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter the left child of "<<front->data<<": ";
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){            //if left child is valid
            BTN<int>* child = new BTN<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout<<"Enter the right child of "<<front->data<<": ";
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){           //if left child is valid
            BTN<int>* child= new BTN<int>(rightChildData);
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
            cout<<front->left->data<<",";
            pendingNodes.push(front->left);
        }
        if(front->right){
            cout<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}

int main(){
    BTN<int>* root = takeInput();
    print(root);
    delete root;
}
