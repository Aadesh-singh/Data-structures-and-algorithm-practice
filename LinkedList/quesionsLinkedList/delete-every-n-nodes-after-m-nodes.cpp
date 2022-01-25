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

Node *skipMdeleteN(Node *head, int M, int N)
{
	if(!head || N == 0) return head;
    else if(M == 0) return NULL;
    
    Node* curr = head;
    
    while(curr){
    
        for(int i=0; i<M-1 && curr; i++){
            curr = curr->next;
        }

        Node * temp = NULL;
        if(curr) temp = curr->next;

        for(int i=0; i<N && temp; i++){
            temp = temp->next;
        }

        if(curr) {
            curr->next = temp;
            curr = curr->next;
        }
    }
    
    return head;
}


int main(){
    Node* head = takeInput();
    print(head);
    head = skipMdeleteN(head, 2, 3);
    print(head);
}