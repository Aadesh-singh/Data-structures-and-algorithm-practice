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

void printNode(BST<int>* root, int k){
    if(!root || k<0) return;
    if(k==0){
        cout<<root->data<<endl;
        return;
    }
    printNode(root->left, k-1);
    printNode(root->right, k-1);
}

int printKdistanceNode(BST<int>* root, int target, int k){
    if(!root) return -1;
    if(root->data == target){
        printNode(root, k);
        return 0;
    }
    int ld = printKdistanceNode(root->left, target, k);
    if(ld != -1){
        if(ld + 1  == k){
            cout<<root->data<<endl;
        } else {
            printNode(root->right, k-ld-2);
        }
        return 1+ld;
    }
    int rd = printKdistanceNode(root->right, target, k);
    if(rd != -1){
        if(rd + 1 == k){
            cout<<root->data<<endl;
        } else {
            printNode(root->left, k-rd-2);
        }
        return 1 + rd;
    }

    return -1;
}

void nodesAtDistanceK(BST<int> *root, int node, int k) {
    int x= printKdistanceNode(root,node,k);
}

int main(){
    BST<int>* root = takeInput();
    int k,node;
    cout<<"Enter the node: ";
    cin>>node;
    cout<<"Enter the distance: ";
    cin>>k;
    printLevelWise(root);
    cout<<"nodes are: "<<endl;
    nodesAtDistanceK(root, node, k);
}