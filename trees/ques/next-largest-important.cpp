
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

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {
    
    if(root==NULL)
        return NULL;		///edge case
  
    TreeNode<int>*max =NULL;
    
    if(root->data > n)
        max=root;
    
    for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int>*childmax= nextLargerElement(root->children[i], n);
        
        if(childmax==NULL)
        {continue;}
        
        else
        {
            if(max==NULL)
                max=childmax;
            else if(childmax->data > n  && childmax->data < max->data)
                max= childmax;
        }
    }
    
    return max;

}


int main() {
    TreeNode<int>* root1 = takeInput();
    int x;
    cout<<"X: ";
    cin>>x;
    cout<<"Second Largest: "<<nextLargerElement(root1, x)->data;

}

