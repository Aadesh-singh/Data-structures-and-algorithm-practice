#include<iostream>
#include<climits>
using namespace std;


// simple recursion
int minSquare(int n){
    if(n==1 || n==2 || n==3 || n==0)
        return n;
    int ans = INT_MAX;
    for(int i=1; i*i <=n; i++){
        ans = min(ans, 1 + minSquare(n-i*i));
    }
    return ans;
}

// memoization
int minSqueare2(int n, int* dp){
    if(n==0||n==1||n==2||n==3)
        return n;
    if(dp[n] != INT_MAX) return dp[n];
    for(int i=1; i*i <= n; i++){
        dp[n] = min(dp[n], 1 + minSqueare2(n-i*i, dp));
    }
    return dp[n];
}

// Dynamic Programming solution
int minSquare3(int n){
    int* dp = new int[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = INT_MAX;
    }

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i=1; i*i<=n; i++){
        for(int j=0; i*i+j <= n; j++){
            dp[i*i + j] = min(dp[i*i + j], 1 + dp[j]);
        }
    }
    int ans = dp[n];

    delete [] dp;

    return ans;
}


int main()
{
    int n;
    cin>>n;
    // cout<<minSquare(n)<<endl;
    int* dp = new int[1000000]; 
    for(int i=0; i<=n ; i++) dp[i] = INT_MAX;
    cout<<minSqueare2(n, dp)<<endl;
    cout<<minSquare3(n)<<endl;
    delete [] dp;
    
    return 0;
}