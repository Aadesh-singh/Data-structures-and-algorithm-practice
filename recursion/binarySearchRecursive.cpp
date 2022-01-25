#include<iostream>
using namespace std;

int BinarySearch(int a[] , int start,  int end, int x) {
    int mid = (start + end)/2;
    if(a[mid] == x) return mid;
    
    if( a[mid] < x ){
      return  BinarySearch(a,mid+1, end,x);
    }
    else if(a[mid] > x){
        return BinarySearch(a,start, mid, x);
    }
    else{
        cout<<"Not found";
        return 0;
    }
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)  cin>>a[i];
    int x;
    cin>>x;
    cout<<BinarySearch(a,0,n-1,x);
}