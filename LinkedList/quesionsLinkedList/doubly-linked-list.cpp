#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void print_rev(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}

Node* takeInput(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}

Node* insert(Node* head, int i, int data){
    Node* temp = head;
    if(head == NULL){
        return head;
    }
    if(i==0){
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }else {
        temp = head;
        head = insert(temp->next, i-1, data);
    }
    temp->next = head;
    head->prev = temp;

    return temp;
}


int main() {
    Node* head = takeInput();
    print(head);
    head = insert(head, 2, 23);
    print(head);
}