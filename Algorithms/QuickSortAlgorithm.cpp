#include<iostream>
using namespace std;

int partition(int a[], int start, int end){
    int pivot = a[start];
    int i = start;
    int j = end;
    while(i < j){
        while(a[i] <= pivot) i++;
        while(a[j] > pivot) j--;
        if(i<j){
            swap(a[i], a[j]);
        }
    }
    swap(a[j], a[start]);
    return j;
}

void QuickSort(int a[], int start, int end){
    if(start >= end) return;
    int pi = partition(a,start,end);
    QuickSort(a, start, pi-1);
    QuickSort(a, pi + 1, end);
}

int main() {
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of array: ";
    for(int i = 0; i< n; i++)  cin>>a[i];
    int start = 0;
    int end = n-1;
    QuickSort(a, start, end);
    for(int i=0; i<=end; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}