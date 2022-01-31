#include<iostream>
#include"../BinarySearchTreeNode.h"
#include<queue>
using namespace std;

BST<int>* takeInput(){
    int rootData;
    cout<<"Enter the root data: ";
    cin>>rootData;
    if(rootData == -1) return NULL;
    BST<int>* root = new BST<int>(rootData);
    queue<BST<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BST<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int i = 2;
        while(i--){
            int data;
            cout<<"Enter the child you want to insert: ";
            cin>>data;
            if(data != -1){
                BST<int>* child = new BST<int>(data);
                if(data < front->data)
                    front->left = child;
                if(data > front->data)
                    front->right = child;
                pendingNodes.push(child);
            }
        }
    }
    return root;
}

void printLevel(BST<int>* root){
    queue<BST<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(!pendingNodes.empty()){
        BST<int>* front = pendingNodes.front();
        pendingNodes.pop();
        if(!front){
            cout<<endl;
            if(pendingNodes.empty())
                return;
            else
                pendingNodes.push(NULL);
        }
        else {
            cout<<front->data<<" ";
            if(front->left) pendingNodes.push(front->left);
            if(front->right) pendingNodes.push(front->right);
        }
    }
}



int main(){
    BST<int>* root = takeInput();
    printLevel(root);
    
}