#include<iostream>
#include <queue>
#include<vector>
using namespace std;


int main(){
    priority_queue<int, vector<int>, greater<int>> pq;  //we write greater to say we want a min heap
    pq.push(167);
    pq.push(23);
    pq.push(54);
    pq.push(5);
    pq.push(2);
    pq.push(56);
    pq.push(87);
    pq.push(100);

    cout<<"Size: "<<pq.size()<<endl;
    cout<<"Top: "<<pq.top()<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
}