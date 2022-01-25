#include<iostream>
#include<stack>
using namespace std;

stack<int> reverseStack(stack<int> s1, stack<int> s2){
    if(s1.empty()) return s1;          //base case

    int x = s1.top();
    s1.pop();

    s1 = reverseStack(s1,s2);           //recursive call

    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    return s1;
}


int main() {
    stack <int> s1;
    stack <int> s2;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    cout<<s1.top()<<endl;
    s1 = reverseStack(s1,s2);
    cout<<s1.top()<<endl;

    return 0;
}