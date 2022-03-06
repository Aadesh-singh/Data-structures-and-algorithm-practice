#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Approach nlogk
void kSmallest(int* input, int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<k; i++){
        pq.push(input[i]);
    }
    for(int i = k; i<n; i++){
        if(input[i] > pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
    }
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
}

int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) cin>>arr[i];
    int k;
    cin>>k;
    cout<<"Answere: "<<endl;
    kSmallest(arr, n, k);
}