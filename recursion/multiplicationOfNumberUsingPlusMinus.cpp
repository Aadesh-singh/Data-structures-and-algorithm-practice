#include<iostream>
using namespace std;

int multyByPlusAndMinus (int m, int n) {
    if(n==0) return 0;
    int ans ;
    if( n >0 ) {
        ans = multyByPlusAndMinus(m,n-1);
        return m + ans;
    }
    else {
        ans = multyByPlusAndMinus(m,n+1);
        return ans - m;
    }

}

int main() {
    int m,n;
    cout<<"Enter the value of M: ";
    cin>>m;
    cout<<"Enter the value of N: ";
    cin>>n;
    cout<<multyByPlusAndMinus(m,n);
    return 0;
}