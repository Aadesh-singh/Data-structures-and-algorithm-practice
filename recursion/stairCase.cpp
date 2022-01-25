#include<iostream>
using namespace std;

int findStep(int n) {
    
        if (n == 1 || n == 0)
            return 1;
        else if (n == 2)
            return 2;
 
        else
            return findStep(n - 3) + findStep(n - 2) + findStep(n - 1);
}

int main() {
    int n;
    cin>>n;
    int ans = findStep(n);
    
    cout<<ans;
}