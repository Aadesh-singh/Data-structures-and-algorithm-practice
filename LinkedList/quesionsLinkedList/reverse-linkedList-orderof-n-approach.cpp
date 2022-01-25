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
    while( temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

class Pair {
    public:
    Node* head;
    Node* tail;
};
Pair reverseLL_helper(Node* head){
    if(head == NULL || head->next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair Smallans = reverseLL_helper(head->next);
    Smallans.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = Smallans.head;
    ans.tail = head;
    return ans;
}
Node* reverse(Node* head){
    return reverseLL_helper(head).head;
}

int main() {
    Node* head = takeInput();
    print(head);
    head = reverse(head);
    print(head);
}