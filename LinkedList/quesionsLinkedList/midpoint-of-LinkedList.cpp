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
    while( data != -1){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}

int findMid(Node* head){
    Node* ptr1 = head;
    Node* ptr2 = head;
    while(ptr2 != NULL){
        
        ptr2 = ptr2->next->next;
        if(ptr2 == NULL) return ptr1->data;
        else if(ptr2 -> next == NULL) {
            ptr1 = ptr1->next;
            return ptr1->data;
        }
        ptr1 = ptr1->next;
    }
    return ptr1->data;
}

int main(){
    Node* head = takeInput();
    print(head);
    cout<<findMid(head)<<endl;
}