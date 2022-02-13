#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> removeDuplicate(int* arr, int size){
    vector<int> output;
    unordered_map<int, bool> seen;
    for(int i = 0; i<size; i++){
        if(seen.count(arr[i])){
            continue;
        }
        seen[arr[i]] = true;
        output.push_back(arr[i]);
    }
    return output;
}

int main(){
    int arr[] = {1,2,3,4,5,6,4,3,22,9,22,3,34,43,544,323};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int> output = removeDuplicate(arr, size);
    for(auto x: output){
        cout<<x<<endl;
    }
}