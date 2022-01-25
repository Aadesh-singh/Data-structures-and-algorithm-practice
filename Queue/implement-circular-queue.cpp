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

class CircularQueue {
    Node* front;
    Node* rear;
    int size;
    public:
    CircularQueue(){
        front = rear = NULL;
        size = 0;
    }


    int Size() {
        return size;
    }
     
    bool isEmpty(){
        return front == NULL;
    }

    void enqueue(int data){
        size++;
        Node* newNode = new Node(data);
        if(front == NULL){
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty "<<endl;
            return INT_MIN;
        }
        int ans = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
        return ans;
    }

    int Front(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return INT_MIN;
        }
        return front->data;
    }
    void display(){
        Node* temp = front;
        for(int i=0; i<2*size; i++){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};



int main()
{
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    cout<<"Popper element is: "<<q.dequeue()<<endl;
    cout<<"Popper element is: "<<q.dequeue()<<endl;

    cout<<"Front element is: "<<q.Front()<<endl;
    cout<<"size element is: "<<q.Size()<<endl;
    q.display();
    return 0;
}