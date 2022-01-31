// Code: Print Elements in Range
// Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).
// Print the elements in increasing order


#include<iostream>
#include"../BinarySearchTreeNode.h"
#include<queue>
#include<vector>
#include<algorithm>
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

void printHelper(BST<int>* root, int k1, int k2, vector<int>* v){
    if(!root) return;
    if(root->data == k1){
        v->push_back(root->data);
        printHelper(root->right, k1, k2, v);
    }
    else if(root->data == k2){
        v->push_back(root->data);
        printHelper(root->left, k1, k2, v);
    }
    else if(root->data >= k1 && root->data <= k2){
        v->push_back(root->data);
        printHelper(root->left, k1, k2, v);
        printHelper(root->right, k1, k2, v);
    }
    else if(root->data < k1)
        printHelper(root->right, k1, k2, v);
    else
        printHelper(root->left, k1, k2, v);

    sort(v->begin(), v->end());
    return;
}

void printElementInRange(BST<int>* root, int k1, int k2){
    vector<int> v;
    printHelper(root, k1, k2, &v);
    for(auto x: v){
        cout<<x<<" ";
    }
    return;
}



int main(){
    BST<int>* root = takeInput();
    // printLevel(root);
    int k1, k2;
    cin>>k1>>k2;
    printElementInRange(root, k1, k2);
    
}