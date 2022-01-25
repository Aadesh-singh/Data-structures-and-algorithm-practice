#include<iostream>
using namespace std;



int find(int a[], int n, int x) {
    if(n==0) return -1;
    if(n==1 && a[0] != x) return -1;
    int ans;
    if(a[0] == x) return 0;
    else{
      ans = find(a+1, n-1, x);
    }
    if(ans == -1) return ans;
    else return ans+1;
        
}
int main() {
    int n = 5;
    int a[] = {1,2,3,4,3};
    cout<<"Found: "<<find(a,n,3);

    return 0;
}