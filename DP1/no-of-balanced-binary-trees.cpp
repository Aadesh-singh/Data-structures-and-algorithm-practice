#include<iostream>
#include<cmath>
using namespace std;

// Recurrence relation
int balancedBinaryTree(int h){
    if(h <= 1)
        return 1;
    
    int mod = (int) (pow(10, 9)) + 7;
    int x = balancedBinaryTree(h-1);
    int y = balancedBinaryTree(h-2);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x) * y) % mod);
    int ans = (temp1 + temp2) % mod;
    // int ans = x*x + 2*x*y;
    return ans;
}

// Memoization
int balancedBinaryTree1(int h, int* dp){
    if(h <= 1)
        return 1;

    if(dp[h] != -1)
        return dp[h];
    
    int mod = (int) (pow(10, 9)) + 7;
    int x = balancedBinaryTree1(h-1, dp);
    int y = balancedBinaryTree1(h-2, dp);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x) * y) % mod);
    int ans = (temp1 + temp2) % mod;
    dp[h] = ans;

    return dp[h];
}

// Dp solution
int balancedBinaryTree3(int h){
    if(h <= 1)
        return 1;
    int* dp = new int[h + 1];
    int mod = (int) (pow(10, 9)) + 7;
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=h; i++){
        int x = dp[i-1];
        int y = dp[i-2];
        int temp1 = (int)(((long)(x)*x) % mod);
        int temp2 = (int)((2 * (long)(x) * y) % mod);
        dp[i] = (temp1 + temp2) % mod;
    }
    int ans = dp[h];
    delete [] dp;
    return ans;
}

int main()
{
    int h;
    cin>>h;
    cout<<balancedBinaryTree(h)<<endl;
    int*dp = new int[h+1];
    for(int i=0; i<=h; i++) dp[i] = -1;

    cout<<balancedBinaryTree1(h, dp)<<endl;
    cout<<balancedBinaryTree3(h)<<endl;

    
    delete [] dp;
    return 0;
}