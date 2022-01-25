#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n;i++) cin>>a[i];
    int count = 0;
    for(int i=0; i<n; i++){
        count += a[i];
    }
    int newCount = ((n-2)*(n-1))/2;
    cout<< count - newCount<<endl;
    return 0;
}