#include<iostream>
using namespace std;

int retSum (int n) {
    if(n == 0) return 0;
    int ans = n%10;
    return ans + retSum(n/10);
}

int main() {
    int n;
    cout<<"Enter a number of your choice: ";
    cin>>n;
    cout<<"Sum of digits of this number is: "<<retSum(n);

}