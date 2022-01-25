#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BTN{
    public:
    T data;
    BTN<T>* left;
    BTN<T>* right;

    BTN(int data){
        this->data = data;
        left = right = NULL;
    }

    ~BTN(){
        delete left;
        delete right;
    }
};

void printTree(BTN<int>* root){
    if(root ==  NULL){
        return;
    }
    cout<<root->data<<": ";
    if(root->left) cout<<"L->"<<root->left->data<<", ";
    if(root->right) cout<<"R->"<<root->right->data<<", ";
    cout<<endl;

    printTree(root->left);
    printTree(root->right);
}

BTN<int>* takeInput(){
    int rootData;
    cout<<"Enter Root Data: ";
    cin>>rootData;
    BTN<int>* root = new BTN<int>(rootData);

    queue<BTN<int>* > pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter the Left child of "<<front->data<<": ";
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){
            BTN<int>* child = new BTN<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout<<"Enter the Right child of "<<front->data<<": ";
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){
            BTN<int>* child = new BTN<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

int main(){
    BTN<int>* root = takeInput();
    printTree(root);
    delete root;
}