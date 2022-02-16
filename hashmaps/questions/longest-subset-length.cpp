#include<iostream>
#include<unordered_map>
using namespace std;

int longestSubsetLength(int* a, int size){
    unordered_map<int, int> m;
    int sum = 0, maxlen = 0;

    for(int i=0; i<size; i++){
        sum += a[i];
        if(sum == 0){
            if(maxlen < i+1){
                int length = i-m[sum];
                 
                if(length > maxlen){
                    maxlen = length;
                }
            }
        }
        else if(m.count(sum) >= 1){
            int length = i-m[sum];
            if(length > maxlen){
                maxlen = length;
            }
        }
        else if(m.count(sum) == 0){
            m[sum] = i;
        }
    }
    return maxlen;
}

int main() {
    int size;
    cin>>size;
    int* arr = new int[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<"MaxLength: "<<longestSubsetLength(arr, size);
    delete [] arr;
}
