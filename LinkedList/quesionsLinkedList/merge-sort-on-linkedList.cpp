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
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

Node* merge(Node* l1, Node* l2){
    Node* h1 = l1;
    Node* h2 = l2;
    Node* fhead = NULL;
    Node* fTail = NULL;

    if(h1->data < h2->data){
        fhead = fTail = h1;
        h1 = h1->next;
    } else {
        fhead = fTail = h2;
        h2 = h2->next;
    }
    while(h1 != NULL && h2!= NULL){
        if(h1->data < h2->data){
            fTail->next = h1;
            fTail = h1;
            h1 = h1->next;
        } else {
            fTail->next = h2;
            fTail = h2;
            h2 = h2->next;
        }
    }
    if( h1 == NULL){
        fTail->next = h2;
    }
    else if(h2 == NULL){
        fTail->next = h1;
    }
    return fhead;
}

Node* mergeSort(Node* head){
    int len = length(head);
    Node* temp = head;
    if( len == 1){
        return temp;
    }
    Node* temp2 = head;
    int half = (len -1)/2;
    while(half > 0){
        temp2 = temp2->next;
        half--;
    }
    Node* temp3 = temp2->next;
    temp2->next = NULL;
    Node* h1 = mergeSort(temp);
    Node* h2 = mergeSort(temp3);
    Node* finalHead = merge(h1, h2);
    return finalHead;
}



int main() {
    Node* head = takeInput();
    print(head);
    head = mergeSort(head);
    print(head);
}