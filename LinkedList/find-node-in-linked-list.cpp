#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node( int data){
        this->data = data;
        this->next = NULL;
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

int find(Node* head,int data){
    int i = -1;
    Node* temp = head;
    if(temp == NULL){
        return i;
    }
    if(temp->data == data){
        i++;                        //if data exist then make i  = 0;
        return i;                   //and return i
    }
    else{
        i = find(head->next, data);
        if(i != -1){                        //if i is not -1 then return 1 + i
            return 1 + i;
        }
        else {
            return i;                   //and if i is -1 then return i
        }
    }
}

int main(){
    Node* head = takeInput();
    print(head);
    cout<<find(head,4);
}