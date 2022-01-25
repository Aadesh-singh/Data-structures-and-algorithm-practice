#include<iostream>
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node<T> *next;
    Node(T data){
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class Stack{
    Node<T> *head;
    int size;
    public:
    Stack(){
        head = NULL;
        size = 0;
    }
    void push(T data){
        Node<T> *newNode = new Node<T>(data);
        if(head == NULL){
            head = newNode;
            size++;
        }
        newNode->next = head;
        head = newNode;
        size++;
    }
    T pop(){
        if(head == NULL){
            cout<<"StacK UnderFlow"<<endl;
            return 0;
        }
        T ans = head->data;
        head = head->next;
        size--;
        return ans;
    }
    T top(){
        if(head == NULL){
            cout<<"Stack UnderFlow"<<endl;
            return 0;
        }
        return head->data;
    }
    int getSize(){
        return size; 
    }
    bool isEmpty(){
        return head == NULL;
    }
};



int main(){
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.getSize()<<endl;
    cout<<s1.isEmpty()<<endl;



    Stack<char> s2;
    s2.push(100);
    s2.push(101);
    s2.push(102);
    s2.push(103);
    s2.push(104);
    cout<<s2.top()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.getSize()<<endl;
    cout<<s2.isEmpty()<<endl;

}