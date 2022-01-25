#include<iostream>
using namespace std;


int* stock_span(int* arr, int n ,int* span){
    int count = 1;

    for(int i=0; i<n; i++){
        for(int j = i-1; j>=0; j--){
            if(arr[j] >= arr[i]){
                break;
            }
            else{
                count++;
            }
        }
        span[i] = count;
        count = 1;
    }

    return span;
}


int main() {
    int n;
    cin>>n;
    int* arr = new int[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<endl;

    int* span  = new int[n];

    span = stock_span(arr, n , span);
    for(int i=0; i<n; i++){
        cout<<span[i]<<" ";
    }


}
