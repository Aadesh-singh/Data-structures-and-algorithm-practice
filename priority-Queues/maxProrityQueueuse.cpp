#include<iostream>
#include"./maxPriorityQueue.h"
using namespace std;

int main() {
    MaxPriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(17);
    p.insert(3);
    p.insert(110);
    p.insert(8);

    cout<<p.getSize()<<endl;
    cout<<p.getMax()<<endl;

    while(!p.isEmpty()){
        cout<<p.remove()<<" ";
    }
}