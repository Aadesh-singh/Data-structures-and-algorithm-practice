#include<iostream>
#include<unordered_map>
using namespace std;

void arrayIntersaction(int a[], int sizea, int b[], int sizeb){
    unordered_map<int, int> map;
    for(int i = 0; i< sizea; i++)
        map[a[i]]++;
    for(int i=0; i<sizeb; i++){
        if(map[b[i]] > 0){
            cout<<b[i]<<" ";
            map[b[i]]--;
        }
    }
}

int main() {
    int t; cin>>t;  //no of text cases
    while(t--){
        int size1, size2;
        cin>>size1;
        int* arr1 = new int[size1];
        for(int i=0; i< size1; i++) cin>>arr1[i];
        cin>>size2;
        int* arr2 = new int[size2];
        for(int i=0; i< size2; i++) cin>>arr2[i];

        arrayIntersaction(arr1, size1, arr2, size2);
        cout<<endl;
    }
}