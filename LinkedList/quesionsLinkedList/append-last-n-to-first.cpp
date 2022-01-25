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

Node* takeInput(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
        }else {
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
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
Node* list(Node* head, int n){
    int len = length(head);
    int i = 1;
    int count = len - n;
    Node* cur = head;
    while(i < count){
        cur = cur->next;
        i++;
    }
    Node* head2 = cur->next;
    cur->next = NULL;
    Node* cur2 = head2;
    while(cur2->next != NULL){
        cur2 = cur2->next;
    }
    cur2->next = head;
    return head2;
}



int main(){
    Node* head = takeInput();
    print(head);
    head = list(head, 3);
    print(head);
}