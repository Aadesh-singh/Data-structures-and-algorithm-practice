#include<iostream>
#include"../BinaryTreeNode.h"
#include<queue>
using namespace std;

BTN<int>* takeInput(){
    int rootData;
    cout<<"Enter Root data: ";
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BTN<int>* root = new BTN<int>(rootData);
    queue<BTN<int>*> pendingNodes;          //queue for levelwise
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter the left child of "<<front->data<<": ";
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){            //if left child is valid
            BTN<int>* child = new BTN<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout<<"Enter the right child of "<<front->data<<": ";
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){           //if left child is valid
            BTN<int>* child= new BTN<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void print(BTN<int>* root){
    queue<BTN<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<": ";
        if(front->left){
            cout<<"L->"<<front->left->data<<",";
            pendingNodes.push(front->left);
        }
        if(front->right){
            cout<<"L->"<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}

BTN<int>* mirror(BTN<int>* root){
    if(root == NULL){
        return root;
    }
    BTN<int>* temp;

    temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);

    return root;
}

//   1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
    BTN<int>* root = takeInput();
    print(root);
    cout<<endl;
    root = mirror(root);
    print(root);
    delete root;
}
