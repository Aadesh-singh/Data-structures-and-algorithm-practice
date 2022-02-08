#include <iostream>
#include "../BinaryTreeNode.h"
#include <queue>
#include<vector>
#include<string>
#include<climits>
#include<stack>
using namespace std;

BTN<int> *takeInput()
{
    int rootdata;
    cin >> rootdata;
    if (rootdata == -1)
        return NULL;
    BTN<int> *root = new BTN<int>(rootdata);
    queue<BTN<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BTN<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            BTN<int> *left = new BTN<int>(leftData);
            front->left = left;
            pendingNodes.push(left);
        }
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            BTN<int> *right = new BTN<int>(rightData);
            front->right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}

void print(BTN<int> *root)
{
    queue<BTN<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while (!pendingNodes.empty())
    {
        BTN<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if (!front)
        {
            cout << endl;
            if (pendingNodes.empty())
            {
                return;
            }
            else
                pendingNodes.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
                pendingNodes.push(front->left);
            if (front->right)
                pendingNodes.push(front->right);
        }
    }
}

void root_to_leaf(BTN<int>* root, vector<stack<int>>* v, stack<int> s){
    if(!root) return;
    s.push(root->data);
    if(!root->left && !root->right){
        v->push_back(s);
        return;
    } else {
        if(root->left) 
            root_to_leaf(root->left, v, s);
        if(root->right)
            root_to_leaf(root->right, v, s);
    }
}

void printStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

void maxRootToLeaf(BTN<int>* root){
    vector<stack<int>> v;
    stack<int> s;
    root_to_leaf(root, &v, s);
    int max = 0;
    for(int i = 0; i< v.size(); i++){
        if(max < v[i].size()){
            max = v[i].size();
        }
    }
    
    for(int i = 0; i< v.size(); i++){
        if(max == v[i].size()){
            printStack(v[i]);
        }
    }
    
}


int main()
{
    BTN<int> *root = takeInput();
    maxRootToLeaf(root);
    delete root;
}
