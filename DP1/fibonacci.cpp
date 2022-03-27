#include<iostream>
#include<climits>
using namespace std;

// simple recursion
int fibo1(int n){
    if(n <= 1){
        return n;
    }
    int a = fibo1(n-1);
    int b = fibo1(n-2);

    return a + b;
}

// memoization
int fibo2helper(int* ans, int n){
    if(n <= 1){
        return n;
    }

    if(ans[n] != -1){
        return ans[n];
    }

    int a = fibo2helper(ans, n-1);
    int b = fibo2helper(ans, n-2);

    ans[n] = a + b;
    return ans[n];
}

int fibo2(int n){
    int* ans = new int[n + 1];
    for(int i=0; i<=n; i++){
        ans[i] = -1;
    }
    return fibo2helper(ans, n);
}

// Dynamic Programming
int fibo3(int n){
    int* ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;

    for(int i = 2; i<=n; i++){
        ans[i] = ans[i-1] + ans[i-2];
    }

    return ans[n];
}


int main()
{
    int n;
    cin>>n;
    cout<<fibo1(n)<<endl;
    cout<<fibo2(n)<<endl;
    cout<<fibo3(n)<<endl;
    
    return 0;
}