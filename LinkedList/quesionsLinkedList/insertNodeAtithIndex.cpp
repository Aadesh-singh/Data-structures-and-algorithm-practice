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
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}
Node* insert(Node* head, int i, int data){
    Node* newNode = new Node(data);               //step1 create a newNode.
    Node* temp = head;
    int count =0;
    if(i == 0){                          //check if we have to insert as first Node.
        newNode->next = head;            //Simply connect head and newNode and updatehead
        head = newNode;
        return head;                    //return head
    }
    while(temp != NULL && count < i-1){      //iterate to 1 less then the position we
        temp =temp->next;                    //have to insert
        count++;
    }
    if(temp != NULL){                       //check if current position is not greater
        newNode->next = temp->next;         //than size of linked List connect the Links
        temp->next = newNode;
    }
    return head;                            //return the head.
}

int main(){
    Node* head = takeInput();
    print(head);
    
    // insert(head, 1, 23);
    int index, data;
    cin>>index>>data;
    insert(head, index, data);
    print(head);
    
}