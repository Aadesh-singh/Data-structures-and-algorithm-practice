#include<iostream>
#include"../BinaryTreeNode.h"
#include<queue>
#include<vector>
using namespace std;

template<typename T>
class node{
    public:
    T data;
    node* next;
    node(T data){
        this->data = data;
        next = NULL;
    }
};

BTN<int>* takeInput(){
    int rootData;
    cout<<"Enter root data: ";
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BTN<int>* root = new BTN<int>(rootData);
    queue<BTN<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter the left child of "<<front->data<<": ";
        int leftChild;
        cin>>leftChild;
        if(leftChild != -1){
            BTN<int>* child = new BTN<int>(leftChild);
            front->left = child;
            pendingNodes.push(child);
        }
        cout<<"Enter the right child of "<<front->data<<": ";
        int rightChild;
        cin>>rightChild;
        if(rightChild != -1){
            BTN<int>* child = new BTN<int>(rightChild);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void print(BTN<int>* root){
    queue<BTN<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        if(front == NULL){
            cout<<endl;
            if(pendingNodes.empty()){
                break;
            } else {
                pendingNodes.push(NULL);
            }
        } else {
            cout<<front->data<<" ";
            if(front->left) pendingNodes.push(front->left);
            if(front->right) pendingNodes.push(front->right);
        }
    }
}

vector<node<int>* > returnList(BTN<int>* root){
    queue<BTN<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    vector<node<int>*> address;
    node<int>* head = NULL;
    node<int>* tail = NULL;
    while(!pendingNodes.empty()){
        BTN<int>* front = pendingNodes.front();
        pendingNodes.pop();
        if(front){
            node<int>* newNode = new node<int>(front->data);
            if(head == NULL){
                head = tail = newNode;
                address.push_back(head);
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            if(front->left) pendingNodes.push(front->left);
            if(front->right) pendingNodes.push(front->right);
        } else {
            if(pendingNodes.empty()){
                break;
            } else {
                pendingNodes.push(NULL);
                head = NULL;
            }
        }
    }
    return address;
}

void printList(node<int>* head){
    node<int>* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main() {
    BTN<int>* root = takeInput();
    print(root);
    vector<node<int>*> address;
    address = returnList(root);
    cout<<"Levelwise linked Lists"<<endl;
    for(auto x: address){
        printList(x);
    }
    return 0;
}