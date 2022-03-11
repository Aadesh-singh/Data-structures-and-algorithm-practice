#include<iostream>
#include<queue>
using namespace std;

int kthLargestElement(int* arr, int n, int k){
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        pq.push(arr[i]);
    }
    int ans;
    while(k > 0){
        ans = pq.top();
        pq.pop();
        k--;
    }
    return ans;
}

int main()
{
    int size;
    cin>>size;
    int* arr = new int[size];
    for(int i=0; i<size; i++) cin>>arr[i];
    int k;
    cin>>k;
    cout<<kthLargestElement(arr, size, k);
    delete [] arr;
    return 0;
}