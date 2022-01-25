#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data){
        this->data= data;
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
        Node* newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}

Node* merge(Node* l1, Node*l2){
    Node* h1 = l1;              // h1 pointing to list1
    Node* h2 = l2;              // h2 pointing to list2
    Node* fhead = NULL;             //final head
    Node* ftail = NULL;             //final tail
    //Only head updation
    if(h1->data < h2->data){               
        fhead = ftail = h1;
        h1 = h1->next;
    } else {
        fhead = ftail = h2;
        h2 = h2->next;
    }
    // check which one is smaller and push in linkedlist
    while(h1 != NULL && h2 != NULL){
        if(h1->data < h2->data){
            ftail->next = h1;
            ftail = h1;
            h1 = h1->next;
        } else {
            ftail->next = h2;
            ftail = h2;
            h2 = h2->next;
        }
    }
    // check which one is left over connect it to tail
    if(h1 == NULL){
        ftail->next = h2;
    }
    else {
        ftail->next = h1;
    }
    // return final head
    return fhead;
}

int main() {
    Node* head1 = takeInput();
    print(head1);
    Node* head2 = takeInput();
    print(head2);
    Node* head = merge(head1, head2);
    print(head);
}