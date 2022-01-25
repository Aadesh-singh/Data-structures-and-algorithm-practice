#include<iostream>
using namespace std;

float power(float x, int e){
    if(e == 1) return x;

    return x * power(x,e-1);
}

int main () {
    int e;
    float x;
    cout<<"Enter the Number: ";
    cin>>x;
    cout<<"Enter the Power: ";
    cin>>e;
    cout<<power(x,e);
}