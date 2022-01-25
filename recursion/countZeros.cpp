#include<iostream>
using namespace std;

int countZeros( int n, int count = 0) {
    if(n<=9 ) {
        if(n == 0) return 1;
        else return 0;
    }
    if(n%10 == 0) count =  1;
    return count + countZeros(n/10, count);
}

int main() {
    int n;
    
    cout<<"Enter the Number: ";
    cin>>n;
    cout<<"count of zeroes is: "<<countZeros(n );
}