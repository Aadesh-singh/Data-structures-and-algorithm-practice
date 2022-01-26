#include<iostream>
#include"../BinaryTreeNode.h"
#include<stack>
#include<queue>
using namespace std;

BTN<int>* takeInput(){
    int rootData;
    cout<<"Enter the root data: ";
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

void zigzagOrder(BTN<int>* root){
    if(!root) return;

    stack<BTN<int>*> s1;
    stack<BTN<int>*> s2;
    s1.push(root);
    while(!s1.empty()){
        while(!s1.empty()){
            BTN<int>* top = s1.top();
            s1.pop();
            cout<<top->data<<" ";
            if(top->left) s2.push(top->left);
            if(top->right) s2.push(top->right);
        }
        cout<<endl;
        while(!s2.empty()){
            BTN<int>* top = s2.top();
            s2.pop();
            cout<<top->data<<" ";
            if(top->right) s1.push(top->right);
            if(top->left) s1.push(top->left);
        }
        cout<<endl;
    }
}


void printLevelWise(BTN<int>* root){
    queue<BTN<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        if(front == NULL){
            cout<<endl;
            if(pendingNodes.empty()){
                break;
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

int main() {
    BTN<int>* root = takeInput();
    cout<<"level wise"<<endl;
    printLevelWise(root);
    cout<<"zigzag"<<endl;
    zigzagOrder(root);
}