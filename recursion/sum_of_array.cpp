#include<iostream>
using namespace std;

int fucn(int a[], int n){
    if(n == 1) {
        return a[n-1];
    }
    return a[0] + fucn(a+1,n-1);
}

int main() {
    int n = 5;
    cout<<"Enter size of the array: ";
    int a[5];       // => 5 will be n in this line to work completely fine.
    cout<<"Enter Elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<fucn(a,n);
    return 0;
}