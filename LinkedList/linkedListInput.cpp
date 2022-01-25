#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void print(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
// Node* takeInput(){
//     int data;
//     cout<<"Enter the value to be Inserted: ";
//     cin>>data;
//     Node *head = NULL;
//     while(data != -1){
//         Node *newNode = new Node(data);
//         if(head == NULL){
//             head = newNode;
//         }
//         else{
//             Node *temp = head;
//             while(temp->next != NULL){
//                 temp = temp->next;
//             }
//             temp->next = newNode;
//         }
//         cout<<"if you want to set data then give value else give -1: ";
//         cin>>data;
//     }
//     return head;
// }

Node* takeInputBetter(){
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
        else {
            tail->next = newNode;
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}

int main() {
    // Node *head = takeInput();
    Node *head = takeInputBetter();
    print(head);
}