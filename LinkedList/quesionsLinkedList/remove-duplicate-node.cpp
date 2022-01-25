//Constraint that the list must be in ascending order
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
    cout<<"print chala: ";
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void eleminate(Node* head){
    Node* cur1 = head;
    Node* cur2 = head->next;
    while( cur2 != NULL ){
        if(cur1->data == cur2->data){
            cur1->next = cur2->next;
            delete cur2;
            cur2 = cur1->next;
        }else{
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }
}

int main() {
    Node* head = takeInput();
    print(head);
    eleminate(head);
    print(head);
}