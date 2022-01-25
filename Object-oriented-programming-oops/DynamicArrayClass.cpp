#include<iostream>
using namespace std;

class DynamicArray {
    int *data;
    int capacity;
    int nextIndex;
    public:
    DynamicArray(){
        data = new int[5];
        capacity = 5;
        nextIndex = 0;
    }
    DynamicArray(DynamicArray const &d){
        this->data = new int[d.capacity];
        for(int i=0; i<d.nextIndex; i++){
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }
    void operator=(DynamicArray const &d){
        this->data = new int[d.capacity];
        for(int i=0; i<d.nextIndex; i++){
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    void add(int element){
        if(nextIndex == capacity){
            int *newData = new int[2 * capacity];
            for(int i=0; i< capacity; i++){
                newData[i] = data[i];
            }
            delete data;
            data = newData;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int get(int i) const{
        if(i < capacity){
            return data[i];
        }
        else {
            cout<<"Error";
            return -1;
        }
    }
    void add(int i, int element){
        if( i< nextIndex) {
            data[i] = element;
        }
        else if( i == nextIndex) {
            add(element);
        }
        else {
            return;
        }
    }
    void print() const{
        for(int i=0; i< nextIndex; i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

};

int main() {
    DynamicArray d1;
    d1.add(2);
    d1.add(3);
    d1.add(4);
    d1.add(5);
    d1.add(6);
    d1.add(7);
    d1.print();
    d1.add(5, 10);
    d1.print();
    DynamicArray d2(d1);
    d2.print();
    DynamicArray d3;
    d3 = d2;
    d3.print();


}