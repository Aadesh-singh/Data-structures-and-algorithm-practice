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

int getSum(TreeNode<int>* root){
    int sum = root->data;
    for(int i=0; i<root->children.size(); i++){
        sum += root->children[i]->data;
    }
    return sum;
}

TreeNode<int>* maxNode(TreeNode<int>* root){
    TreeNode<int>* ans = root;
    int sum = getSum(ans);

    for(int i=0; i<root->children.size();i++){
        TreeNode<int>* ans1 = maxNode(root->children[i]);
        int sum1 = getSum(ans1);

        if(sum < sum1){
            ans = ans1;
        }
    }
    return ans;
}

int main() {
    TreeNode<int>* root = takeInput();
    print(root);
    cout<<"level 2"<<endl;
    TreeNode<int>* maxiNode = maxNode(root);
    cout<<"maxNode is: "<<maxiNode->data;
}