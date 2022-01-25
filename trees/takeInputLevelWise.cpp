#include<iostream>
// #include"treeNode.h"
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T> *> children; 

    TreeNode(int data){
        this->data = data;
    }
};

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter the RootData: ";
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter the Number of children of "<<front->data<<": ";
        int numChild;
        cin>>numChild;
        for(int i=0; i<numChild; i++){
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            int childData;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void print(TreeNode<int>* root){
    if(root == NULL) return;

    cout<<root->data<<": ";
    for(int i = 0; i< root->children.size(); i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0; i< root->children.size(); i++){
        print(root->children[i]);
    }
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    print(root);
}