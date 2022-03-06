#include<iostream>
#include<queue>
using namespace std;

void kSortedArray(int input[], int n, int k){
    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        pq.push(input[i]);
    }
    int j=0;
    for(int i = k; i < n ; i++){
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }
    while(!pq.empty()){
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}

int main(){
    int n = 5;
    int k = 3;
    int input[] = {10, 12, 6, 7, 9};
    
    for(int i=0; i<n; i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    kSortedArray(input, n, k);
    for(int i=0; i<n; i++){
        cout<<input[i]<<" ";
    }

}