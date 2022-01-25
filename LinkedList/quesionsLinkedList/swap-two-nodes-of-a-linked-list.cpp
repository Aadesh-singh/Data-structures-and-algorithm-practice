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

Node* swap_nodes(Node *head,int i,int j) {
    Node *temp = head, *prev = NULL; 
    Node *node1 = NULL, *node2 = NULL, *node1_prev = NULL, *node2_prev = NULL;
    int pos = 0;
    
    // if i and j are equal
    if(i == j) return head; //No changes
    
    while(temp != NULL) {
        if(pos == i) {
            node1_prev = prev; 
            node1 = temp;
        }
        else if(pos == j) {
            node2_prev = prev; node2 = temp;
        }
        prev = temp;
        temp = temp -> next; pos++; 
    }
    if(node1_prev != NULL) {
        node1_prev -> next = node2;
    }
    else { 
        head = node2;
    }
    if(node2_prev != NULL) { 
        node2_prev -> next = node1; 
    }
    else {
        head = node1;
    }
    Node *temp1 = node2 -> next;
    node2 -> next = node1 -> next; 
    node1 -> next = temp1;
    return head;
}

int main(){
    Node* head = takeInput();
    print(head);
    head = swap_nodes(head, 1,0);
    print(head);
}