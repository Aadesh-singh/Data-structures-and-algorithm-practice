#include<iostream>
#include "treeNode.h"
#include<vector>
using namespace std;

// template<typename T>
// class treeNode{
//     public:
//     T data;
//     vector<treeNode<T> *> children;

//     treeNode(T data){
//         this->data = data;
//     }
// };

treeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter the data: ";
    cin>>rootData;
    treeNode<int>* root = new treeNode<int>(rootData);

    int n;
    cout<<"Enter num of children of "<< rootData << endl;
    cin>>n;

    for(int i=0; i< n; i++){
        treeNode<int>* child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

void printTree(treeNode<int> *root){

    // if root is null return
    if(root == NULL){
        return;
    }

    cout<<root->data <<": ";        //this is working as a base case

    for(int i = 0; i< root->children.size(); i++){
        cout<<root->children[i]->data<<",";     //printing the children
    }
    cout<<endl;

    for(int i=0; i< root->children.size(); i++){
        printTree(root->children[i]);           //calling for net children
    }
}


int main(){
    treeNode<int>* root = takeInput();

    printTree(root);
}