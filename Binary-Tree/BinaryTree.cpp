#include<iostream>
#include"BinaryTreeNode.h"
using namespace std;

void print(BTN<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<": ";

    if(root->left != NULL){
        cout<<"L-> "<<root->left->data<<", ";
    }
    if(root->right != NULL){
        cout<<"R-> "<<root->right->data<<endl;
    }

    print(root->left);
    print(root->right);
    cout<<endl;
}

int main() {
    BTN<int>* root = new BTN<int>(1);
    BTN<int>* node1 = new BTN<int>(2);
    BTN<int>* node2 = new BTN<int>(3);

    root->left = node1;
    root->right = node2;

    print(root);
    delete root;
}