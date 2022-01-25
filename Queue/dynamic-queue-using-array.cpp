#include<iostream>
using namespace std;


class Queue{
    int *data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;
    public:
    Queue(){
        data = new int[5];
        size = 0;
        capacity = 5;
        firstIndex = -1;
        nextIndex = 0;
    }
    int getSize() {
        return size;
    }
    bool isEmpty() {
        return size==0;
    }
    void enqueue(int element){
        if(size == capacity){
            int* newData = new int[2*capacity];
            int j=0; 
            for(int i= firstIndex; i<capacity; i++){
                newData[j] = data[i];
                j++;
            }
            for(int i=0; i< firstIndex; i++){
                newData[j] = data[i];
                j++;
            }
            delete [] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex+1) % capacity;
        if(firstIndex == -1){
            firstIndex = 0;
        }
        size++;
        return;
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return 0;
        }
        int ans  = data[firstIndex];
        firstIndex = (firstIndex + 1)% capacity;
        size--;
        return ans;
    }
    int front(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);

    cout<<q.front()<<endl;
    
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.front()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;


}