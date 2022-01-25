#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
Node* takeInput(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while( data != -1){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
        } else{
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* next = head->next;
    while( head != NULL ){
        head->next = prev;
        prev = head;
        head = next;
        if(head != NULL){
            next = head->next;
        } else {
            next = NULL;
        }
    }
    head = prev;
    return head;
}

int main() {
    Node* head = takeInput();
    print(head);
    head = reverse(head);
    print(head);
}