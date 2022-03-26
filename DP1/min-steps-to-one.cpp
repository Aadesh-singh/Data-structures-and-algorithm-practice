#include<iostream>
#include<climits>
using namespace std;

// without DP --> Memoization
int minSteps2(int* arr, int n){
    if(n <= 1){
        return 0;
    }
    int x = (arr[n-1] != -1) ? arr[n-1] : minSteps2(arr,n-1);
    int y = INT_MAX, z = INT_MAX;
    if(n % 2 == 0){
        y = (arr[n/2] != -1) ? arr[n/2] : minSteps2(arr,n/2);
    }
    if(n%3 == 0){
        z = (arr[n/3] != -1) ? arr[n/3] : minSteps2(arr,n/3);
    }
    arr[n] = 1 + min(x, min(y, z));

    return arr[n];   
}

// without DP -->BruteForce
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
    cout<<"Min Steps: "<<minSteps(n)<<endl;
    int* arr = new int[n];
    for(int i=0; i<n; i++) arr[i] = -1;
    cout<<"Min Steps: "<<minSteps2(arr,n)<<endl;

    delete [] arr;
    return 0;
}