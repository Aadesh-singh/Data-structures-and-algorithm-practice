#include<iostream>
#include<queue>
using namespace std;

queue<int> reverse_queue(queue<int> q){
    if(q.empty()) return q;

    int x = q.front();
    q.pop();

    q = reverse_queue(q);
    q.push(x);

    return q;
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<q.front()<<endl;          //intital head
    q = reverse_queue(q);
    cout<<q.front()<<endl;          //final head

    return 0;
}