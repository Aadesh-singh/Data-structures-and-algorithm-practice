#include<iostream>
#include<queue>
using namespace std;

void kSmallest(int* input, int n, int k){
    priority_queue<int> pq;

    for(int i=0; i<n; i++){
        pq.push(input[i]);
    }
    while(pq.size() != k){
        pq.pop();
    }
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
}

int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) cin>>arr[i];

    kSmallest(arr, n, k);
}