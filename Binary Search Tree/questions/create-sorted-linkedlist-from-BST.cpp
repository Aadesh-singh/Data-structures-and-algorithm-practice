// Code: BST to Sorted LL
// Given a BST, convert it into a sorted linked list. Return the head of LL.


#include<iostream>
#include"../BinarySearchTreeNode.h"
#include<queue>
#include<climits>
using namespace std;

BST<int>* takeInput(){
    int rootData;
    cout<<"Enter the root data: ";
    cin>>rootData;
    if(rootData == -1) return NULL;
    BST<int>* root = new BST<int>(rootData);
    queue<BST<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BST<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int i = 2;
        while(i--){
            int data;
            cout<<"Enter the child you want to insert: ";
            cin>>data;
            if(data != -1){
                BST<int>* child = new BST<int>(data);
                if(data < front->data)
                    front->left = child;
                if(data > front->data)
                    front->right = child;
                pendingNodes.push(child);
            }
        }
    }
    return root;
}

void printLevel(BST<int>* root){
    queue<BST<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(!pendingNodes.empty()){
        BST<int>* front = pendingNodes.front();
        pendingNodes.pop();
        if(!front){
            cout<<endl;
            if(pendingNodes.empty())
                return;
            else
                pendingNodes.push(NULL);
        }
        else {
            cout<<front->data<<" ";
            if(front->left) pendingNodes.push(front->left);
            if(front->right) pendingNodes.push(front->right);
        }
    }
}

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~node(){
        delete next;
    }
};

void findNode(BST<int>* root, int k){
    if(!root) return;
    if(root->data == k){
        root->data = INT_MAX;
        return;
    }
     if(root->left) findNode(root->left, k);
     if(root->right) findNode(root->right, k);
}


int minimum(BST<int>* root){
    if(!root) return INT_MAX;
    int left = minimum(root->left);
    int right = minimum(root->right);
    int minimum1 = min(root->data, min(left, right));
    
    return minimum1;
}

int countNode(BST<int>* root){
    if(!root) return 0;
    return 1 + countNode(root->left) + countNode(root->right);
}

node* createSortedLL(BST<int>* root){
    if(!root) return NULL;
    node* head = new node(minimum(root));
    findNode(root, head->data);
    node* tail = head;
    int min = minimum(root);
    findNode(root, min);
    int i = 1;
    int count = countNode(root);
    while(i< count){
        node* newNode = new node(min);
        tail->next = newNode;
        tail = tail->next;
        min = minimum(root);
        findNode(root, min);
        i++;
    }
    return head;
}
void printLL(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    BST<int>* root = takeInput();
    printLevel(root);
    node* head = createSortedLL(root);
    cout<<"Linked list: ";
    printLL(head);
    delete root;
    delete head;
}