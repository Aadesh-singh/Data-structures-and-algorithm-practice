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
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}

Node* Delete(Node* head, int i){
    int count = 0;                       //to figure out current working index
    Node* temp1 = head;                  //This works as new head here
    if( i==1){                           //Checking if we have to delete at 0th index
        temp1 = head->next;              
        head = temp1;
        delete temp1;
        return head;
    }
    Node* temp2 = NULL;
    while(temp1 != NULL && count < i-1){        // to iterate to correct index
        temp2 = temp1;
        temp1 = temp1->next;
        count++;
    }
    temp2->next = temp1->next;                  // rearranging Links
    delete temp1;
    return head;
}

int main(){
    Node* head = takeInput();
    print(head);
    head = Delete(head, 2);
    print(head);
    
}