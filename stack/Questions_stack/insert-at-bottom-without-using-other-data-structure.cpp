#include<iostream>
using namespace std;

template<typename T>
class Node {
    public:
    T data;
    Node<T>* next;
    Node(T data){
        this->data = data;
        this->next = NULL;
    }
};

template<typename T>
class stack{
  Node<T>* head;
  Node<T>* tail;
  int size;
  public:
    stack()  {
        head = tail = NULL;
        size = 0;
    }
    bool isEmpty(){
        return size == 0;
    }
    int Size() {
        return size;
    }
    void push(T data){
        Node<T>* newNode = new Node<T>(data);
        size++;
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
        return;
    }

    T pop(){
        if(isEmpty()){
            return 0;
        }
        T ans = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
    T top() {
        if(isEmpty()){
            return 0;
        }
        return head->data;
    }
    void push_bottom(T data){
        if(isEmpty()){          //if empty pysh the data
            push(data);
            return;
        }
        T item = pop();         //save the top data and pop()
        push_bottom(data);      //call for remaining stack till eraches basecase

        push(item);               //when returning push inside stack
    }
};

int main() {
    stack<int> s;
    s.push_bottom(10);
    s.push_bottom(20);
    s.push_bottom(30);

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

}