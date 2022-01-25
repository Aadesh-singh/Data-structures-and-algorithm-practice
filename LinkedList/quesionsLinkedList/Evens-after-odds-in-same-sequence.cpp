#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while( temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
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
        if( head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}

Node* evenAfterOdd(Node* head){
    Node* oddH = NULL;
    Node* oddT = NULL;
    Node* evenH = NULL;
    Node* evenT = NULL;

    while(head != NULL){
        if(head->data%2 == 1){
            if(oddH == NULL){
                oddH = oddT = head;
            }
            else {
                oddT->next = head;
                oddT = head;
            }
        } else{
            if(evenH == NULL){
                evenH = evenT = head;
            } else {
                evenT->next = head;
                evenT = head;
            }
        }
        head =head->next;
    }
    oddT->next = evenT->next = NULL;
    if(oddH == NULL){
        return evenH;
    } else{
        oddT->next = evenH;
        return oddH;
    }
}

int main() {
    Node* head = takeInput();
    print(head);
    head = evenAfterOdd(head);
    print(head);
    
}