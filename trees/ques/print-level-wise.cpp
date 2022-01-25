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

    cin>>rootData;
    treeNode<int>* root = new treeNode<int>(rootData);

    queue<treeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        treeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        
        cin>>numChild;
        for(int i = 0; i<numChild; i++){
            
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
            cout<<front->children[i]->data<<", ";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}


int main() {
    treeNode<int>* root = takeInput();
    print(root);
}