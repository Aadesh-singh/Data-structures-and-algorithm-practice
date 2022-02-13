#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;

int maxFrequency(int* arr, int size){
    unordered_map<int, int> map;
    for(int i =0 ; i<size; i++){
        map[arr[i]] += 1;
    }
    int max = INT_MIN, curMax = INT_MIN;
    for(int i = 0; i < size; i++){
        if(map[arr[i]] > max) {
            max = map[arr[i]];
            curMax = arr[i];
        }
    }
    return curMax;
}

int main() {
    int size;
    cin>>size; int i =0 ;
    int* arr = new int[size];
    while( i< size){
        cin>>arr[i];
        i++;
    }
    cout<<maxFrequency(arr, size);
    delete arr;
}