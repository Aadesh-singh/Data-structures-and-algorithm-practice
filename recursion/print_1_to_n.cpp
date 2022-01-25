#include<iostream>
using namespace std;

int print(int n)
{
    if( n == 1 ) {
        cout<<n<<" ";
        return 1;
    }
    cout<<n<<" ";
   return print(n-1);
}

int print1(int n , int x = 1)
{
    if( x == n ) {
        cout<<x <<" ";
        return x;
    }
    cout<<x<<" ";
    return print1(n,x+1);
}
int main(){
    int n ,t;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"1 for asc & 2 for desc order: ";
    cin>>t;
    if( t == 1) print1(n);
    else print(n);
    return 0;
}