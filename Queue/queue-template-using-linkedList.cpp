#include<iostream>
using namespace std;

template<typename T>
class Node{
    public:
    T data;
    Node<T>* next;

    Node(T data){
        this->data = data;
        this->next = NULL;
    } 
};

template <typename T>
class Queue{
    Node<T>* head;
    Node<T>* tail;
    int size;

    public:

    Queue(){
        head = tail = NULL;
        size = 0;
    }
    int Size() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(T data){
        size++;
        Node<T>* newNode = new Node<T>(data);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        return ;
    }

    T dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        T ans = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }

    T front() {
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        return head->data;
    }
};

int main() {
    cout<<"Queue of integer"<<endl;
    Queue<int> q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);
    q1.enqueue(70);

    cout<<q1.front()<<endl;
    
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;

    cout<<q1.front()<<endl;

    cout<<q1.Size()<<endl;
    cout<<q1.isEmpty()<<endl;

    cout<<"Queue Of character"<<endl;

    Queue<char> q2;
    q2.enqueue(97);
    q2.enqueue(98);
    q2.enqueue(99);
    q2.enqueue(100);
    q2.enqueue(101);
    q2.enqueue(102);
    q2.enqueue(103);

    cout<<q2.front()<<endl;

    cout<<q2.dequeue()<<endl;
    cout<<q2.dequeue()<<endl;
    cout<<q2.dequeue()<<endl;
    cout<<q2.dequeue()<<endl;
    cout<<q2.dequeue()<<endl;

    cout<<q2.front()<<endl;

    cout<<q2.Size()<<endl;
    cout<<q2.isEmpty()<<endl;
}