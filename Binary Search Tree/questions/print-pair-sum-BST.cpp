// Pair sum in a BST
// Given a binary search tree and a integer S, find pair of nodes in the BST which sum to S. You can use extra space only O(log n).
// Assume BST contains all unique elements.
// Note : In a pair, print the smaller element first.

#include<iostream>
#include"../BinarySearchTreeNode.h"
#include<queue>
#include<stack>
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
            cout<<"Enter the child of "<<front->data<<": ";
            int childData;
            cin>>childData;
            if(childData != -1){
                BST<int>* child = new BST<int>(childData);
                if(childData > front->data) front->right = child; 
                if(childData < front->data) front->left = child; 
                pendingNodes.push(child);
            }
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

int countNodes(BST<int>* root){
    if(!root) return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void pairSumBST(BST<int>* root, int sum){
    int totalNodes = countNodes(root);
    int count = 0;

    stack<BST<int>*> inorder;
    stack<BST<int>*> revinorder;

    BST<int>* temp = root;

    while(temp){
        inorder.push(temp);
        temp = temp->left;
    }
    temp = root;
    while(temp){
        revinorder.push(temp);
        temp = temp->right;
    }

    while(count < totalNodes - 1){
        BST<int>* top1 = inorder.top();
        BST<int>* top2 = revinorder.top();

        if(top1->data + top2->data == sum){
            cout<<top1->data<<" "<<top2->data<<endl;
            BST<int>* top = top1;
            inorder.pop();
            count++;
            if(top->right){
                top =top->right;
                while(top){
                    inorder.push(top);
                    top = top->left;
                }
            }

            top = top2;
            revinorder.pop();
            count++;
            if(top->left){
                top = top->left;
                while(top){
                    revinorder.push(top);
                    top = top->right;
                }
            }
        }
        else if(top1->data + top2->data < sum){
            BST<int>* top = top1;
            inorder.pop();
            count++;
            if(top->right){
                top =top->right;
                while(top){
                    inorder.push(top);
                    top = top->left;
                }
            }
        }
        else {
            BST<int>* top = top2;
            revinorder.pop();
            count++;
            if(top->left){
                top = top->left;
                while(top){
                    revinorder.push(top);
                    top = top->right;
                }
            }
        }
    }
}

int main(){
    BST<int>* root = takeInput();
    int sum;
    cout<<"Enter the sum: ";
    cin>>sum;
    printLevelWise(root);
    cout<<"Pair sum are: "<<endl;
    pairSumBST(root, sum);
}