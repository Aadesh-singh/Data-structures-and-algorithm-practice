// LCA of Binary Tree
// Given a binary tree and two nodes, find LCA (Lowest Common Ancestor) of the given two nodes in Binary Tree. Read about LCA if you are having doubts about the definition.


#include<iostream>
#include"../../Binary-Tree/BinaryTreeNode.h"
#include<queue>
using namespace std;

BTN<int>* takeInput(){
    int rootData;
    cout<<"Enter the root data: ";
    cin>>rootData;
    if(rootData ==  -1) return NULL;
    BTN<int>* root = new BTN<int>(rootData);
    queue<BTN<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter the left node of "<<front->data<<":";
        int left;
        cin>>left;
        if(left != -1){
            BTN<int>* child = new BTN<int>(left);
            front->left = child;
            pendingNodes.push(child);
        }
        cout<<"Enter the right node of "<<front->data<<":";
        int right;
        cin>>right;
        if(right != -1){
            BTN<int>* child = new BTN<int>(right);
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


//  function
int findLCA(BTN<int>* root, int n1, int n2){
    if(!root) return -1;
    if(root->data == n1 || root->data == n2){
        return root->data;
    }else {
        int res1 = findLCA(root->left, n1, n2);
        int res2 = findLCA(root->right, n1, n2);

        if(res1 == -1) return res2;
        if(res2 == -1) return res1;
        if(res1 != -1 && res2 != -1) return root->data;
        else return -1;
    }
}

int main(){
    BTN<int>* root = takeInput();
    printLevelWise(root);
    int n1, n2;
    cout<<"Enter the node: ";
    cin>>n1>>n2;
    cout<<"LCA is: "<<findLCA(root, n1, n2);
}