#include<iostream>
using namespace std;


class DqueNode{
    public:
    int data;
    DqueNode* prev;
    DqueNode* next;
    DqueNode(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

};

class Dqueue{
    int size;
    DqueNode* head;
    DqueNode* tail;
    public:

    Dqueue(){
        head = tail = NULL;
    }
    bool isEmpty(){
        return head == NULL;
    }
    int Size(){
        return size;
    }

    void insertFirst(int data){
        size++;
        DqueNode* newNode = new DqueNode(data);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    void insertLast(int data){
        size++;
        DqueNode* newNode = new DqueNode(data);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        return;
    }
    int removeFirst(){
        size--;
        if(isEmpty()){
            return 0;
        }
        int ans = head->data;
        DqueNode* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return ans;
    }

    int removeLast(){
        size--;
        if(isEmpty()){
            return 0;
        }
        int ans = tail->data;
        DqueNode* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        return ans;
    }

    int top(){
        if(isEmpty()){
            return 0;
        }
        return tail->data;
    }
    int front(){
        if(isEmpty()){
            return 0;
        }
        return head->data;
    }
    void display(){
        DqueNode* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

};

class stack: public Dqueue {
    public:
    void push(int data){
        insertLast(data);
    }
    int pop(){
        return removeLast();
    }
};

class Queue: public Dqueue {
    public:
    void enqueue(int data){
        insertLast(data);
    }
    int dequeue(){
        return removeFirst();
    }
};


int main(){
    stack st;
    st.push(7);
    st.push(8);
    cout<<"Stack: ";
    st.display();
    cout<<st.pop()<<endl;
    st.display();


    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    cout<<"Queue: ";
    q.display();
    cout<<q.dequeue()<<endl;
    q.display();
}