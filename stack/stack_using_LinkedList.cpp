#include<iostream>
#include<climits>
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

class Stack {
    Node* head;
    int size;
    public:
    Stack(){
        head = NULL;
        size = 0;
    }
    void push(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            size++;
            return;
        }
        newNode->next = head;
        head = newNode;
        size++;
    }

    int pop(){
        if(head == NULL){
            cout<<"stack UnderFlow"<<endl;
            return INT_MIN;
        }
        int ans = head->data;
        head = head->next;
        size--;
        return ans;
    }

    int top(){
        if(head == NULL){
            cout<<"Stack UnderFlow"<<endl;
            return INT_MIN;
        }
        return head->data;
    }

    int getsize(){
        return size;
    }

    bool isEmpty(){
        return head == NULL;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<"top: "<<s.top()<<endl;
    cout<<"pop: "<<s.pop()<<endl;
    cout<<"pop: "<<s.pop()<<endl;
    cout<<"pop: "<<s.pop()<<endl;
    cout<<"Size: "<<s.getsize()<<endl;
    cout<<"is empty: "<<s.isEmpty()<<endl;
}