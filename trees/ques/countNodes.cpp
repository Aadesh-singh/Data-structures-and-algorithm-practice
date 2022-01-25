#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<int> *> children;

    TreeNode(int data){
        this->data = data;
    }
};

TreeNode<int> * takeInput(){
    int rootData;
    // cout<<"Enter the root Data: ";
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        // cout<<"Enter the number of children of "<<front->data<<": ";
        int numChild;
        cin>>numChild;

        for(int i=0; i< numChild; i++){
            // cout<<"Enter the child "<< i + 1 <<" of "<<front->data<<": ";
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
    queue<TreeNode<int>* > pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        cout<<front->data<<": ";
        pendingNodes.pop();
        for(int i=0; i< front->children.size(); i++){
            cout<<front->children[i]->data<<", ";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}

int countNodes(TreeNode<int>* root){
    int ans = 1;

    for(int i=0; i < root->children.size(); i++){
        ans += countNodes(root->children[i]);
    }
    return ans;
}

int main(){
    TreeNode<int>* root = takeInput();

    print(root);

    cout<<countNodes(root);
}