// Replace with Sum of greater nodes
// Given a binary search tree, replace each nodes' data with the sum of all nodes' which are greater or equal than it. You need to include the current node's data also.
// That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.


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
        cout<<"Enter the left node of "<<front->data<<": ";
        cin>>left;
        if(left != -1){
            BST<int>* child = new BST<int>(left);
            front->left = child;
            pendingNodes.push(child);
        }
        int right;
        cout<<"Enter the right node of "<<front->data<<": ";
        cin>>right;
        if(right != -1){
            BST<int>* child = new BST<int>(right);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void print(BST<int>* root){
    queue<BST<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(!pendingNodes.empty()){
        BST<int>* front = pendingNodes.front();
        pendingNodes.pop();
        if(!front){
            cout<<endl;
            if(pendingNodes.empty()){
                return;
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

int replace(BST<int>* root, int sum){
    if(root == NULL) return sum;

    sum = replace(root->right,sum);
    sum = sum + root->data;
    root->data=sum;
    sum =replace(root->left,sum);

    return sum;
}

void replaceWithGreater(BST<int>* root){
    if(root == NULL) return;
    int ans = replace(root, 0);

    return;
}


int main(){
    BST<int>* root = takeInput();
    print(root);
    cout<<"After operation"<<endl;
    replaceWithGreater(root);
    print(root);
}