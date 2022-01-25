#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
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

TreeNode<int>* takeInput(){
    int rootData;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int numChild;
        cin>> numChild;

        for(int i=0; i< numChild; i++){
            int childData;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

void print(TreeNode<int>* root){
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<", ";
        for(int i=0; i< front->children.size(); i++){
            cout<<front->children[i]->data<<", ";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}

void printAtLevelK(TreeNode<int>* root, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout<<root->data<<" ";
        return;
    }
    for(int i=0; i< root->children.size(); i++){
        printAtLevelK(root->children[i], k-1);
    }
}

int main(){
    TreeNode<int>* root = takeInput();

    print(root);

    printAtLevelK(root, 2);
}