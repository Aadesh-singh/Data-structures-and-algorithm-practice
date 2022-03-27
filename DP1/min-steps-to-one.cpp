#include<iostream>
#include<climits>
using namespace std;

// with DP
int minSteps3(int* arr, int n){
    arr[1] = 0;
    for(int i=2; i<=n; i++){
        int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;
        if(i % 3 == 0){
            if(arr[i/3] != -1){
                ans1 = 1 + arr[i/3];   //if value pre-exist then add one to that operation
            } else {
                ans1 = 1 + 1 + arr[i/3];  //if value doest not exist add 0 to one i.e {1 + arr[i/3] --> 0}
            }
        }
        if(i % 2 == 0){
            if(arr[i/2] != -1){
                ans2 = 1 + arr[i/2];
            } else {
                ans2 = 1 + 1 + arr[i/2];
            }
        }
        if(arr[i-1] == -1) ans3 = 1 + 1 + arr[i-1];
        else ans3 = 1 + arr[i - 1];

        arr[i] = min(ans1, min(ans2, ans3));
    }
    return arr[n];
}
                                                                                                
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
    int* arr = new int[n + 1];
    for(int i=0; i<=n; i++) arr[i] = -1;
    cout<<"Min Steps: "<<minSteps2(arr,n)<<endl;
    for(int i=0; i<=n; i++) arr[i] = -1;
    cout<<"Min Steps: "<<minSteps3(arr,n)<<endl;

    delete [] arr;
    return 0;
}