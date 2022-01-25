#include<iostream>
using namespace std;

template<typename T>

class Queue{
    T* data;
    int firstIndex;
    int nextIndex;
    int capacity;
    int size;

    public:
    Queue(int s){
        data = new T[s];
        firstIndex = -1;
        nextIndex= 0;
        size = 0;
        capacity = s;
    }
    int getsize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void enqueue(T element){
        if(size == capacity){
            cout<<"Queue is full"<<endl;
            return;
        }
        data[nextIndex] = element;
        size++;
        nextIndex = (nextIndex + 1) % capacity;
        if(firstIndex == -1){
            firstIndex = 0;
        }
        return;
    }
    T dequeue(){
        if(isEmpty()){
            cout<<"queue is Empty"<<endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if(size == 0 ){
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
    T front(){
        if(isEmpty()){
            cout<<"Stack is empty!"<<endl;
            return 0;
        }
        return data[firstIndex];
    }

};

int main(){
    Queue<char> q(5);
    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);
    q.enqueue(105);
    q.enqueue(106);

    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.front()<<endl;
    cout<<q.getsize()<<endl;
    cout<<q.isEmpty()<<endl;

    return 0;
}
