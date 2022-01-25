#include<iostream>
using namespace std;

template<typename T>
class Queue{
    T* data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;
    public:
    Queue(){
        data = new T[5];
        firstIndex = -1;
        nextIndex = 0;
        size = 0;
        capacity = 5;
    }
    int getSize() {
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void enqueue(T element){
        if(size == capacity){
            T* newData = new T[2* capacity];
            int j=0;
            for(int i= firstIndex; i<capacity; i++){
                newData[j] = data[i];
                j++;
            }
            for(int i=0; i< firstIndex; i++){
                newData[j] = data[i];
            }
            delete [] data;
            data = newData;
            nextIndex = capacity;
            firstIndex = 0;
            capacity *= 2;
        }
        data[nextIndex]= element;
        nextIndex = (nextIndex + 1) % capacity;
        if(firstIndex == -1){
            firstIndex = 0;
        }
        size++;
        return;
    }

    T dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        return ans;
    }
    T front(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
};

int main() {
    cout<<"Integet Queue"<<endl;
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);
    q.enqueue(100);

    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.front()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
    
    cout<<"Character Queue"<<endl;

    Queue<char> q1;
    q1.enqueue(100);
    q1.enqueue(101);
    q1.enqueue(102);
    q1.enqueue(103);
    q1.enqueue(104);
    q1.enqueue(105);
    q1.enqueue(106);
    q1.enqueue(107);
    q1.enqueue(108);
    q1.enqueue(109);

    cout<<q1.front()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;

    cout<<q1.front()<<endl;
    cout<<q1.getSize()<<endl;
    cout<<q1.isEmpty()<<endl;
}