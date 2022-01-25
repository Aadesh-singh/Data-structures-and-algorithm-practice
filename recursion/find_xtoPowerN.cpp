#include<iostream>
using namespace std;

int pow(int x, int n)
{
    if( n == 0) return 1;

    return x * pow(x , n - 1);
}

int main(){
    int x,n;
    cin>>x>>n;
    int output = pow(x , n);
    cout<<output<<endl;

    return 0;
}