#include<iostream>
using namespace std;

int find2(int a[],int n,int x){
  if(n == 0) return -1;
  if(a[n-1] == x) return n-1;
  int ans = find2(a+1, n-1,x);

  if(ans == -1) {
    if(a[0] != x) return -1;
    else return 0;
  }
  else {
    return 1 + ans;
  }

}

int main() {
    int n = 6;
    int a[] = {1,2,3,4,3,4};
    cout<<"last Index is: "<<find2(a,n,3)<<endl;
}