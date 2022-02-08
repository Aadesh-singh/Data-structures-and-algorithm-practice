#include<iostream>
#include<vector>
#include<queue>

using namespace std;


template <typename T>
class treeNode {
    public:
    T data;
    vector<treeNode<T> *> children;

    treeNode(int data){
        this->data = data;
    }
};

treeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter the Root data: ";
    cin>>rootData;
    treeNode<int>* root = new treeNode<int>(rootData);

    queue<treeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        treeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter the number of child of "<<front->data<<": ";
        cin>>numChild;
        for(int i = 0; i<numChild; i++){
            cout<<"Enter child "<<i + 1<<" of "<<front->data<<": ";
            int childData;
            cin>>childData;
            treeNode<int>* child = new treeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void print(treeNode<int>* root){
    queue<treeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        treeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<": ";
        for(int i=0; i < front->children.size(); i++){
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}

treeNode<int>* remove(treeNode<int>* root){
    if(!root) return NULL;
    if(root->children.size() == 0){
        delete root;
        return NULL;
    }
    for(int i=0; i< root->children.size(); i++){
        root->children[i] = remove(root->children[i]);
    }
    return root;
}

int main() {
    treeNode<int>* root = takeInput();
    // print(root);
    root = remove(root);
    print(root);

    delete root;
}