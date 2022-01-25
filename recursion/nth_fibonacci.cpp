#include<iostream>
using namespace std;

int fibo(int n) {
    if(n==0 || n==1){
        return n;
    }
    int smallOutput1 = fibo(n-1);
    int smallOutput2 = fibo(n-2);

    return smallOutput1 + smallOutput2;
}

int main(){
    int num;
    cout<<"Enter the number";
    cin>>num;
    cout<<"Number is: "<<fibo(num-1);
    return 0;
}