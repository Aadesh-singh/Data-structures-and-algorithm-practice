#include<iostream>
#include<unordered_map>
using namespace std;

void longestConsecutiveSubsequence(int a[], int size){
    unordered_map<int, bool> map;
    for(int i=0; i<size; i++){
        map[a[i]] = false;
    }
    int maxLength = 0, start = 0, end = 0, j = 1;
    int pstart, pend, pmax;
    for(int i=0; i<size; i++){
        if(map[a[i]] != true){
            pstart = a[i];
            pend = a[i];
            pmax = 1;
            map[a[i]] = true;
            while(map[a[i] + j] != 0){
                pmax += 1;
                pend = a[i] + j;
                map[a[i] + j] = true;
                j++;
            }
            j = -1;
            while(map[a[i] + j] != 0){
                pmax += 1;
                pstart = a[i] + j;
                map[pstart] = true;
                j--;
            }
            j = 1;
            if(pmax >= maxLength){
                start = pstart;
                end = pend;
                maxLength = pmax;
            }
        }
    }
    cout<<start<<" "<<end<<endl;
}



int main(){
    int n;
    cin>>n;
    int* a = new int[n];
    for(int i=0; i<n; i++) cin>>a[i];
    longestConsecutiveSubsequence(a, n);

    delete [] a;
}