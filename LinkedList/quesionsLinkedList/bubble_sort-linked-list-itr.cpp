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

int length(Node* head) {
    if(head==NULL) {
        return 0;
    }
    Node* temp=head;
    int size=1+length(temp->next);
    return size;
}
Node* bubble_sort_LinkedList_itr(Node* head) {
    for(int i=0;length(head)>i;i++) { 
        Node* prev=NULL,*curr=head;
        while(curr->next!=NULL) {
            if(curr->data>curr->next->data) {
                if(prev!=NULL) {
                    Node *temp = curr -> next -> next;
                    curr -> next -> next = curr;
                    prev -> next = curr -> next;
                    curr -> next = temp;
                    prev = prev -> next;
                } 
                else{
                    head=curr->next;
                    curr->next=head->next;
                    head->next=curr;
                    prev=head;
                }
            }
            else { 
                prev=curr;
                curr=curr->next;
            }
        }
    }
    return head;
}

int main(){
    Node* head = takeInput();
    print(head);
    head = bubble_sort_LinkedList_itr(head);
    print(head);
    return 0;
}