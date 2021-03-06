#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void print(Node* head){
    Node *temp = head;
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
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}
int checkLength(Node *head){
    Node* temp = head;
    int count = 0;
    if(temp == NULL) return count;
    else {
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
    }
    return count;
}

int main(){
    Node* head = takeInput();
    print(head);
   cout<< checkLength(head);
}