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
    while(data != NULL){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
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
Node* insert( Node* head, int i, int data){
    Node* temp = head;
    Node* temp2 = NULL;
    if(temp == NULL){
        return temp;
    }
    if(i == 0){
        Node* newNode = new Node(data);
        newNode->next = temp;
        return newNode;
    }
    else{
        temp2 = temp;
        temp = insert(temp->next, i-1, data);
    }
    temp2->next = temp;
    return temp2;
}

int main(){
    Node* head = takeInput();
    print(head);
    head = insert(head, 10, 22);
    print(head);
    return 0;
}