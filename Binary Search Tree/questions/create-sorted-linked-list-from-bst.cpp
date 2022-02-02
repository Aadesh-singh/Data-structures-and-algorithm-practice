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
};


void printLL(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

// method 2
class Pair{
    public:
    node* head;
    node* tail;
};

Pair createLL_helper(BST<int>* root){
    if(!root){
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }
    Pair left = createLL_helper(root->left);
    Pair right = createLL_helper(root->right);
    node* curr = new node(root->data);
    if(left.head != NULL && right.head != NULL){
        left.tail->next = curr;
        left.tail = right.tail;
        curr->next = right.head;
        return left;
    } 
    else if(!left.head && right.head){
        curr->next = right.head;
        Pair ans;
        ans.head = curr;
        ans.tail = right.tail;
        return ans;
    }
    else if(left.head && !right.head){
        left.tail->next = curr;
        left.tail = curr;
        return left;
    } 
    else {
        Pair ans;
        ans.head = curr;
        ans.tail = curr;

        return ans;
    }
}

node* createLL(BST<int>* root){
    return createLL_helper(root).head;
}

// Method: 1
node* createSortedLL(BST<int>* root){
    if(!root) return NULL;

    node* left = createSortedLL(root->left);
    node* right = createSortedLL(root->right);

    node* temp = left;
    if(left != NULL){
        while(temp->next != NULL) temp = temp->next;
    }

    node* cur = new node(root->data);
    if(temp != NULL) temp->next = cur;
    cur->next = right;

    return (left == NULL) ? cur : left;
}

int main(){
    BST<int>* root = takeInput();
    printLevel(root);
    node* head = createSortedLL(root);
    // 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    cout<<"Linked list: ";
    printLL(head);
    cout<<endl;
    cout<<"Linked list from pair: ";
    node*head2 = createLL(root);
    printLL(head2);
    delete root;
    delete head;
    delete head2;
}