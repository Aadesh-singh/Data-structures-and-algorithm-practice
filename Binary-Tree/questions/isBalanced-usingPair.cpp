#include<iostream>
#include"../BinaryTreeNode.h"
#include<queue>
using namespace std;

BTN<int>* takeInput(){
    int rootData;
    cout<<"Enter the root data: ";
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BTN<int>* root = new BTN<int>(rootData);
    queue<BTN<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter the left child of "<<front->data<<": ";
        int leftData;
        cin>>leftData;
        if(leftData != -1){
            BTN<int>* child = new BTN<int>(leftData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout<<"Enter the right child of "<<front->data<<": ";
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

void print(BTN<int>* root){
    queue<BTN<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<": ";
        if(front->left){
            cout<<front->left->data<<", ";
            pendingNodes.push(front->left);
        }
        if(front->right){
            cout<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}

int height(BTN<int>* root){
    if(root == NULL){
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

pair<bool, int> isBalancedHelper(BTN<int>* root){
    if(root == NULL){
        pair<bool, int> p;
        p.first  = true;
        p.second = 0;
        return p;
    }
    int l = height(root->left);
    int r = height(root->right);
    if(abs(l-r) < 2){
        pair<bool, int> left = isBalancedHelper(root->left);
        pair<bool, int> right = isBalancedHelper(root->right);
        if(left.first == false || right.first == false){
            pair<bool, int> p;
            p.first = false,
            p.second = height(root);
            return p;
        }
        else if(left.first == true && right.first == true){
            if(abs(left.second - right.second) < 2){
                pair<bool, int> p;
                p.first = true,
                p.second = height(root);
                return p;
            }
        }
        else {
            pair<bool, int> p;
            p.first = false,
            p.second = height(root);
            return p;
        }
    }
}

bool isBalanced(BTN<int>* root){
    pair<bool, int> p = isBalancedHelper(root);

    return p.first;
}

int main(){
    BTN<int>* root = takeInput();
    print(root);
    cout<<"Is balanced: "<<isBalanced(root);
}