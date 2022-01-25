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
        cin>> data;
    }
    return head;
}
void print(Node* head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* Delete(Node* head, int i){
    Node* temp = head;
    Node* temp2 = NULL;
    if(temp == NULL){
        return temp;
    }
    if(i==0){
        Node* a = temp;
        temp = temp->next;
        delete a;
        return temp;
    }
    else {
        temp2 = temp;
        temp = Delete(temp->next, i-1);
    }
    temp2->next = temp;
    return temp2;
}

int main() {
    Node* head = takeInput();
    print(head);
    int i;
    cout<<"Enter the index to delete: ";
    cin>>i;
    head = Delete(head, i);
    print(head);

    return 0;
}