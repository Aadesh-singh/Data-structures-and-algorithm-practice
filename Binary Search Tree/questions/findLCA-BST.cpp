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
            cout<<"Enter the child node of "<<front->data<<": ";
            int childNode;
            cin>>childNode;
            if(childNode != -1){
                BST<int>* child= new BST<int>(childNode);
                if(childNode > front->data) front->right = child;
                if(childNode <= front->data) front->left = child;
                pendingNodes.push(child);
            }
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

//  function
int findLCA(BST<int>* root, int n1, int n2){
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


int main() {
    BST<int>* root = takeInput();
    int n1, n2;
    cout<<"Enter the nodes spareated by space: ";
    cin>>n1>>n2;
    print(root);
    cout<<"LCA of BST is: "<<findLCA(root, n1, n2);
}