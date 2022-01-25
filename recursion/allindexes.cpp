#include<iostream>
using namespace std;

int allIndexes(int a[], int n,int x, int op[]){
    if(n == 0) return 0;                                        // if size of comming array is 0 then simply return 0     I.E BASE CASE
    int ans = allIndexes(a+1,n-1,x,op);                            //  first CALLING RECURSION and saving size of array in ans variable
    for(int i=0; i<ans; i++){                               
        op[i]++;                                        // incrementing each index by one as recurssion got all indexes by -1 i.e.  index[1] => index[0]
    }
    if(a[0] == x){
        for(int i=ans-1; i>=0; i--){
            op[i+1] = op[i];                            // if 0th element is equal to x then shift each element of the array by one and then place 0 at 0th index
        }
        op[0] = 0;
        ans++;                                          //increment size of array by one
    }
    return ans;                                             // return size
}

int main() {
    int n= 5;
    int a[] = {2,3,2,2,4};
    int op[5];
    int x;
    cout<<"Enter x: ";
    cin>>x;
    int ans = allIndexes(a,n,x,op);
    for(int i = 0; i<ans ; i++) {
        cout<<op[i]<<" ";
    }
}