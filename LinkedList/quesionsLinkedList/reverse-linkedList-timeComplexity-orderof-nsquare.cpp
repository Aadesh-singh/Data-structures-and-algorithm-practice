#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data)   {
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
    Node* temp = head;
    if(temp->next == NULL){
        return temp;                //if last node then return head
    }
    Node* fhead = reverse(temp->next);          //it will recieve the head Node only
    Node* tail = fhead;
    while(tail->next != NULL){
        tail = tail->next;                  //get tail to its actual position
    }
    tail->next = temp;                  //put reverse link
    temp->next = NULL;                  //and make next of current last node NULL;
    return fhead;                       //Return head again
}

int main(){
    Node* head = takeInput();
    print(head);
    head = reverse(head);
    print(head);
}