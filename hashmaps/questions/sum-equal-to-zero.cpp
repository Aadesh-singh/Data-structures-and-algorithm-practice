// Problem Description:
// Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
// Note: Array A can contain duplicate elements as well.

#include<iostream>
#include<unordered_map>
using namespace std;

int pairSumToZero(int* a, int size){
    unordered_map<int, int> map;
    int count = 0;
    for(int i=0; i<size; i++) 
        map[a[i]]++;
    
    for(int i=0; i<size; i++){
        if(map[-a[i]] > 0){
            count++;
            map[a[i]]--;
        }
    }
    return count;
}

int main() {
    int t; //no of test cases
    cin>>t;
    while(t--){
        int size;
        cin>>size;
        int* a = new int[size];
        for(int i=0; i<size; i++) cin>>a[i];

        cout<<"No. of pairs are: "<<pairSumToZero(a, size)<<endl;
        delete a;
    }
}