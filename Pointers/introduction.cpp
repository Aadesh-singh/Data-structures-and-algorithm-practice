#include<iostream>
using namespace std;

int main(){
    int i = 10;
    int *p = &i;
    cout<<i<<endl;
    cout<<addressof(i)<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;
    i++;
    cout<<i<<endl;
    cout<<*p<<endl;
    (*p)++;
    cout<<i<<endl;
    cout<<*p<<endl;



    return 0;
}