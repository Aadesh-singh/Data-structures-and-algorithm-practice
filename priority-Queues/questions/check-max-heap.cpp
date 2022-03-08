#include<iostream>
using namespace std;

bool checkMaxHeap(int* arr, int n){
    for(int i=0; i<n; i++){
        if((2*i + 1) > n){
            continue;
        }
        else if((2*i + 1) < n && (2*i + 2) >= n){
            if(arr[i] < arr[2*i + 1]){
                return false;
            }
        }
        else if((2*i + 2) < n){
            if(arr[i] > arr[2*i + 1] && arr[i] > arr[2*i + 2]){
                continue;
            }
            else{
                return  false;
            }
        }
    }

    return true;
}

int main()
{
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"Is MaxHeap: "<< checkMaxHeap(arr, n);
    
    delete [] arr;
    return 0;
}