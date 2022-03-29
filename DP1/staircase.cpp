#include<iostream>
using namespace std;

// Recursion
int findWays1(int n){
    if(n==0 || n==1)
        return 1;
    if(n==2) 
        return 2;
    return findWays1(n-3) + findWays1(n-2) + findWays1(n-1);
}

// Memoization
int findWays2(int* dp, int n){
    if(n==0||n==1)
        return 1;
    if(n==2)
        return 2;
    if(dp[n] != -1)
        return dp[n];
    
    dp[n] = findWays2(dp, n-3) + findWays2(dp, n-2) + findWays2(dp, n-1);
    return dp[n];
}

// DP solution
int findWays3(int n){
    int* dp = new int[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<findWays1(n)<<endl;
    int* dp = new int[n+1];
    for(int i=0; i<=n; i++)
        dp[i] = -1;
    cout<<findWays2(dp,n)<<endl;
    cout<<findWays3(n)<<endl;

    delete [] dp;
    return 0;
}