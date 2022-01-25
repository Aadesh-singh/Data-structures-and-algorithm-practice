#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

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
        else{
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

int find(Node* head, int toFind){
    int index = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == toFind){
            return index;
        }
        index++;
        temp = temp->next;
    }
    return -1;
}

int main() {
    Node* head = takeInput();
    print(head);
    int toFind;
    cin>>toFind;
    cout<<find(head, toFind);
    return 0;
}