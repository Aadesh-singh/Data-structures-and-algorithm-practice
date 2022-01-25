#include<iostream>
using namespace std;

bool find(int a[], int n, int x) {
    if(n==0) return false;
    else if(n == 1 && a[0] == x) return true;

    if(a[0] == x){
        return true;
    }
    else {
        find(a+1,n-1,x);
    }
    
}

int main() {
    int n = 5;
    int a[5], x;
    cout<<"Enter the array elements: ";
    for(int i=0; i<n ; i++) {
        cin>>a[i];
    }
    cout<<"Enter the no. to be searched: "<<endl;
    cin>>x;
    cout<<"Number present: "<<find(a,n,x)<<endl;
    return 0;
}