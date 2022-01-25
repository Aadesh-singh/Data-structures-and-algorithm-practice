#include<iostream>
#include<climits>
using namespace std;

class Stack{
    int *data;
    int nextIndex;
    int capacity;
    public:
    Stack(int totalIndex){
        data = new int[totalIndex];
        capacity = totalIndex;
        nextIndex = 0;
    }
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex == 0;
    }
    void push(int element){
        if(nextIndex == capacity){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack UnderFlow"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
    int top(){
        if(isEmpty()){
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};



int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;    
    cout<<s.pop()<<endl;    
    cout<<s.pop()<<endl;        
    

    cout<<s.top()<<endl;
    cout<<s.isEmpty()<<endl;
}