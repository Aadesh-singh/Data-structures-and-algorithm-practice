#include<iostream>
// #include"../BinaryTreeNode.h"
#include<queue>
using namespace std;

template<typename T>
class BTN{
  public:
  T data;
  BTN* left;
  BTN* right;

  BTN(T data){
    this->data = data;
    left = NULL;
    right = NULL;
  } 
  ~BTN(){
      delete left;
      delete right;
  }  
};

BTN<int>* takeInputLevelwise(){
    int rootData;
    cout<<"Enter the root: ";
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BTN<int>* root = new BTN<int>(rootData);
    queue<BTN<int>* > pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter the left child of the "<<front->data<<": ";
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){
            BTN<int>* child = new BTN<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout<<"Enter the right child of the "<<front->data<<": ";
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){
            BTN<int>* child = new BTN<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(BTN<int>* root){
    queue<BTN<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<": ";
        if(front->left){
            cout<<"L =>"<<front->left->data<<",";
            pendingNodes.push(front->left);
        }
        if(front->right){
            cout<<"R =>"<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}


int sum(BTN<int>* root){
    int L = 0, R = 0;
    if(root == NULL){
        return 0;
    }
    if(root->left){
        L = sum(root->left);
    }
    if(root->right){
        R = sum(root->right);
    }
    return root->data + L + R;
}

// 1 2 3 4 5 6 7 -1 -1 8 -1 -1 -1 -1 -1 -1 -1
int main() {
    BTN<int>* root = takeInputLevelwise();
    printTree(root);
    cout<<"Sum of all Nodes is: "<<sum(root)<<endl;
}