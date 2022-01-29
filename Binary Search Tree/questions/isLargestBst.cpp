// Largest BST
// Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree.
// Return the height of largest BST.


#include<iostream>
#include"../BinarySearchTreeNode.h"
#include<queue>
#include<climits>
#include<cmath>
using namespace std;

class Pair{
    public:
    int maximum;
    int minimum;
    bool bst;
    int height;    
};

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
        cout<<"Enter the left data of the "<<front->data<<": ";
        cin>>left;
        if(left != -1){
            BST<int>* child = new BST<int>(left);
            front->left = child;
            pendingNodes.push(child);
        }
        int right;
        cout<<"Enter the right data of the "<<front->data<<": ";
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
            if(pendingNodes.empty()) break;
            else pendingNodes.push(NULL);
        }else {
            cout<<front->data<<" ";
            if(front->left) pendingNodes.push(front->left);
            if(front->right) pendingNodes.push(front->right);
        }
    }
}


Pair BSTN(BST<int> *root)
{
    if(root==NULL)
    {
       Pair obj;
        obj.minimum =INT_MAX;
        obj.maximum = INT_MIN;
        obj.bst = true;
        obj.height=0;
    return obj;
    }
    
    Pair left= BSTN(root->left);
    Pair right =BSTN(root->right);
    
    int minimum=min(root->data,min(left.minimum,right.minimum));
    int maximum=max(root->data,max(left.maximum,right.maximum));
    bool  isBSTfinal=(root->data >left.maximum) && (root->data < right.minimum) && left.bst && right.bst;
   
    Pair obj;
    obj.minimum=minimum;
    obj.maximum=maximum;
    obj.bst=isBSTfinal;
    if(isBSTfinal)
    {
        obj.height= 1+max(left.height,right.height);
    }
    else   obj.height= max(left.height,right.height);
    return obj;
    
}

int largestBSTSubtree(BST<int> *root) {
    return BSTN(root).height;
}

int main(){
    BST<int>* root = takeInput();
    print(root);
    cout<<largestBSTSubtree(root);
}