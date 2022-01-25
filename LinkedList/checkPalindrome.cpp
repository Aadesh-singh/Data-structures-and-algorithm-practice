#include<iostream>
#include<stack>
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

bool check_palindrome(Node* head)
{
    Node* slow= head; 
        // Declare a stack  
        stack <int> s; 
        // Push all elements of the list  
        // to the stack  
        while(slow != NULL){ 
                s.push(slow->data); 
                // Move ahead  
                slow = slow->next;
        } 
        // Iterate in the list again and  
        // check by popping from the stack 
        while(head != NULL ){ 
            // Get the top most element  
             int i=s.top(); 
             // Pop the element  
             s.pop(); 
             // Check if data is not 
             // same as popped element  
            if(head -> data != i){ 
                return false; 
            } 
            // Move ahead  
           head=head->next;
        } 
  
    return true; 
}

int main() {
    Node* head = takeInput();
    print(head);
    cout<<check_palindrome(head);
}