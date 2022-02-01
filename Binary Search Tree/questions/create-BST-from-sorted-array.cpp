// Code: Construct BST from a Sorted Array
// Given a sorted integer array A of size n which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.

#include<iostream>
#include"../BinarySearchTreeNode.h"
#include<queue>
#include<vector>
using namespace std;


BST<int>* createBst(vector<int> v, int start, int end){
    if(start>end) return NULL;
    int mid = (start + end)/2;
    BST<int>* root = new BST<int>(v[mid]);
    root->left = createBst(v, start, mid - 1);
    root->right = createBst(v, mid+1, end);

    return root;
}

BST<int>* createBst(vector<int> v){
    BST<int>* root = createBst(v, 0, v.size()-1);

    return root;
}

void print(BST<int>* root){
    if(!root) return;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

int main() {
    vector<int> v;
    int n;
    cout<<"Enter the no. of elements in the array: ";
    cin>>n;
    int data;
    for(int i = 0; i<n; i++) {
        cin>>data;
        v.push_back(data);
    }
    cout<<"Array is: ";
    for(auto x: v){
        cout<<x<<" ";
    }
    cout<<endl;
    BST<int>* root = createBst(v);
    print(root);
    delete root;
}