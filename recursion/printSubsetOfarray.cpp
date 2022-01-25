#include<iostream>
using namespace std;
void printSubset(int a[], int n, int output[], int m){
    
    if(n == 0) {
        for(int i=0; i<m; i++){
            cout<<output[i]<<" ";
        }
    cout<<endl;
    return;
    }
    printSubset(a+1,n-1,output,m);
    int newOutput[m+1];
    int i;
    for(i=0; i<m; i++)
    {
        newOutput[i] = output[i];
    }   
    newOutput[i] = a[0];
    printSubset(a+1,n-1,newOutput, m+1);

return;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    int output[n];
    int m= 0;
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    printSubset(a,n,output,m);
}