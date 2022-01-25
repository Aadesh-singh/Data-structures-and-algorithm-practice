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

class Queue{
    int Size;
    Node* head;
    Node* tail;

    public:
    Queue(){
        head = NULL;
        tail = NULL;
        Size = 0;
    }
    int size() {
        return Size;
    }
    bool isEmpty(){
        return Size==0;
    }
    void enqueue(int data){
        Size++;
        Node* newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        return;
    }
    int dequeue() {
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        int ans = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        Size--;
        return ans;
    }
    int front() {
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        return head->data;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);

    cout<<q.front()<<endl;

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.front()<<endl;

    cout<<q.size()<<endl;
    cout<<q.isEmpty()<<endl;

    return 0;
}