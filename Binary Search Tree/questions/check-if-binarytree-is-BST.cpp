// Print nodes at distance k from node
// Given a binary tree, a node and an integer K, print nodes which are at K distance from the the given node.

#include<iostream>
#include"../BinarySearchTreeNode.h"
#include<queue>
#include<climits>
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
        int left;
        cout<<"Enter the left data of "<< front->data<<": ";
        cin>>left;
        if(left != -1){
            BST<int>* child = new BST<int>(left);
            front->left = child;
            pendingNodes.push(child);
        }
        int right;
        cout<<"Enter the right data of "<< front->data<<": ";
        cin>>right;
        if(right != -1){
            BST<int>* child = new BST<int>(right);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printLevelWise(BST<int>* root){
    queue<BST<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(!pendingNodes.empty()){
        BST<int>* front = pendingNodes.front();
        pendingNodes.pop();
        if(!front){
            cout<<endl;
            if(pendingNodes.empty()){ return; } 
            else pendingNodes.push(NULL);
        }
        else {
            cout<<front->data<<" ";
            if(front->left) pendingNodes.push(front->left);
            if(front->right) pendingNodes.push(front->right);
        }
    }
}

int maximum(BST<int>* root){
    if(root == NULL) return INT_MIN;
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
int minimum(BST<int>* root){
    if(root == NULL) return INT_MAX;
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBst(BST<int>* root){
    if(!root) return true;

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool ans = (root->data > leftMax) && (root->data <= rightMin) && 
                isBst(root->left) && isBst(root->right);

    return ans;
}

int main(){
    BST<int>* root = takeInput();
    printLevelWise(root);
    string s = (isBst(root)) ? "True" : "false"; 
    cout<<"IS BST: "<<s;
}