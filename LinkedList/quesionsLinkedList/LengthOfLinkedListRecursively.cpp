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
            head = newNode;
            tail = newNode;
        }else{
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

int length(Node* head){
    Node* temp = head;
    if(temp == NULL){
        return 0;
    }
    return 1 + length(temp->next);
}



int main(){
    Node* head = takeInput();
    print(head);
    cout<<"Length of the Given Linked List is: "<<length(head);

}