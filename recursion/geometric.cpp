#include<iostream>
#include<math.h>
using namespace std;

double geometry(int k) {
    if(k == 0) return 1;
    double ans = geometry(k-1);
    return ans + (1/pow(2,k));
}

int main() {
    int k;
    cout<<"Enter the no. to which you want sum of series: ";
    cin>>k;
    cout<<geometry(k);
}