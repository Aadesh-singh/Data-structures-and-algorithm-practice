#include<iostream>
#include<climits>
using namespace std;



// without DP
int minSteps(int n){
    if(n <= 1){
        return 0;
    }

    int x = minSteps(n-1);
    int y = INT_MAX, z = INT_MAX;
    if(n % 2 == 0){
        y = minSteps(n/2);
    }
    if(n%3 == 0){
        z = minSteps(n/3);
    }

    return 1 + min(x, min(y, z));
    
}

int main()
{
    int n;
    cin>>n;
    cout<<"Min Steps: "<<minSteps(n);
    return 0;
}