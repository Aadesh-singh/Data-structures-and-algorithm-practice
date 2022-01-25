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
    while(temp != NULL){
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
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
  return head;
}
void printIthNode(Node* head, int i){
    int j=0;
    Node* temp = head;
    while(j<i){
        temp = temp->next;
        j++;
    }
    if(temp == NULL){
        return;
    }
    cout<<temp->data<<endl;
    return;
}

int main(){
    Node* head = takeInput();
    int i;
    cin>>i;
    printIthNode(head, i);
    // print(head);

    return 0;
}