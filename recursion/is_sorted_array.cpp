#include<iostream>
using namespace std;

bool is_sorted(int a[], int n){
    if(n==0 || n==1) {
        return true;
    }

    if(a[0] > a[1]) return false;

    return is_sorted(a+1, n-1);
}

int main(){
    int n;
    cout<<"Enter size of the array: ";
    cin>>n;
    int a[n];
    cout<<"Enter elements of the array: ";
    for(int i=0;i<n; i++) {
        cin>>a[i];
    }
    cout<<"Is sorted: "<<is_sorted(a,n);
}