// Create & Insert Duplicate Node
// Given a Binary Tree with N number of nodes, for each node create a new duplicate node, and insert that duplicate as left child of the original node.


#include<iostream>
#include<queue>
#include"../BinaryTreeNode.h"
using namespace std;

BTN<int>* takeInput(){
    int rootData;
    cout<<"Enter root data: ";
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
        if(front){
            cout<<front->data<<" ";
            if(front->left) pendingNodes.push(front->left);
            if(front->right) pendingNodes.push(front->right);
        } else {
            cout<<endl;
            if(pendingNodes.empty()){
                break;
            } else {
                pendingNodes.push(NULL);
            }
        }
    }
}

void createDuplicateNode(BTN<int>* root){
    if(!root) return;

    BTN<int>* newNode = new BTN<int>(root->data);
    BTN<int>* temp = root->left;
    root->left = newNode;
    if(temp) newNode->left = temp;

    createDuplicateNode(temp);
    createDuplicateNode(root->right);
}

int main() {
    BTN<int>* root = takeInput();
    printLevelWise(root);
    cout<<"After root manipulation: "<<endl;
    createDuplicateNode(root);
    printLevelWise(root);

    return 0;
}