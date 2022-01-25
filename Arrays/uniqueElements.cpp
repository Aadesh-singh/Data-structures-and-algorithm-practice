#include<iostream>
using namespace std;

int main(){
    int a[] = {1,4,2,3,3,2,1};
    int n = sizeof(a)/sizeof(a[0]);

    int uniqueEle = a[0];
    for(int i=0; i<n-1; i++){
        uniqueEle =  uniqueEle ^ a[i+1];
    }
    cout<<uniqueEle<<endl;
    return 0;
}