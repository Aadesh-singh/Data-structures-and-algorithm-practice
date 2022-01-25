#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(int data){
        this->data = data;
    }
};

TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter Root Data: ";
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter the no. of  children of "<< front->data<<": ";
        cin>>numChild;
        for(int i=0; i<numChild; i++){
            int childData;
            cout<<"Enter the "<<i<<" child data of "<<front->data<<": ";
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);

            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

void print(TreeNode<int> * root){
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<": ";
        for(int i=0; i<front->children.size(); i++){
            cout<<front->children[i]->data<<", ";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}

bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(root1->data != root2->data)
        return false;
    
    if(root1->children.size() != root2->children.size())
        return false;
    
    bool ans =true;
    for(int i=0;i<root1->children.size();i++)
    {
        bool smallans = isIdentical(root1->children[i],root2->children[i]);
        if(smallans == false)
        {   ans=smallans;
            return ans;
        }
    }
    return ans;

}

int main() {
    TreeNode<int>* root1 = takeInput();
    TreeNode<int>* root2 = takeInput();

    cout<<"Is Identical: "<<isIdentical(root1, root2);

}

