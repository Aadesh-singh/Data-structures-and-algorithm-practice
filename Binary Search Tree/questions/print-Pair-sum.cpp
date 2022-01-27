#include<iostream>
#include"../../Binary-Tree/BinaryTreeNode.h"
#include<queue>
#include<algorithm>
#include<vector>
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
            BTN<int>* newNode = new BTN<int>(leftData);
            front->left = newNode;
            pendingNodes.push(newNode);
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

void printLevelWise(BTN<int>* root){
    queue<BTN<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        if(front){
            cout<<front->data<<" ";
            if(front->left) pendingNodes.push(front->left);
            if(front->right) pendingNodes.push(front->right);
        } else {
            cout<<endl;
            if(pendingNodes.empty()){
                break;
            } else {
                pendingNodes.push(NULL);
            }
        }
    }
}


// method 1:  find by replacing the no. by -1

bool find(BTN<int>* root, int n){
    if(!root) return false;

    if(root->data == n){
        root->data = -1;
        return true;
    }
    bool res1 = false, res2 = false;
    if(root->left)  res1 = find(root->left, n);
    if(root->right) res2 = find(root->right,n);
    
    return res1 || res2;
}

void findPair(BTN<int>* cn, int sum, BTN<int>*root){
    if(!root) return;
    // cout<<"current node data: "<<cn->data<<endl;
    if(cn->data != -1){
        int num = sum - cn->data;
        bool res = find(root, num);
        if(res){
            cout<<cn->data<<" "<<num<<endl;
        }
    }
        if(cn->left) findPair(cn->left, sum, root);
        if(cn->right) findPair(cn->right, sum, root);
}

// Method 2: By Transforming an array by given binary tree

void printPairSum(BTN<int>* root, int sum){
    vector<int> v;
    queue<BTN<int>* > pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        v.push_back(front->data);
        if(front->left) pendingNodes.push(front->left);
        if(front->right) pendingNodes.push(front->right);
    }
    sort(v.begin(), v.end());
    int i = 0, j = v.size() - 1;
    while(i < v.size()){
        while(j>0){
            if(v[i] + v[j] == sum){
                cout<<v[i]<<" "<<v[j]<<endl;
                v[i] = -1;
                v[j] = -1;
                j--;
                i++;
            }
            else if(v[i] + v[j] < sum){
                i++;
            }
            else{
                j--;
            }
        }
    }
}


int main(){
    BTN<int>* root = takeInput();
    printLevelWise(root);
    cout<<"Enter the sum: ";
    int sum;
    cin>>sum;
    // findPair(root, sum, root);
    // printLevelWise(root);
    printPairSum(root, sum);
}