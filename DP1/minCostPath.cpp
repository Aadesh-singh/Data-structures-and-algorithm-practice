#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

// Recurrance relation
int minCostPath(int** arr, int i, int j, int m, int n){
    if(i == m-1 && j == n-1){
        return arr[i][j];
    }
    
    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    if(i < m-1){
        x = minCostPath(arr, i + 1, j, m, n);
    }
    if(j < n-1)
        y = minCostPath(arr, i, j+1, m, n);
    if(i< m-1 && j< n-1){
        z = minCostPath(arr, i+1, j+1, m, n);
    }
    

    return arr[i][j] + min(x, min(y,z));
}

int minCostPath(int** arr, int m, int n){
    return minCostPath(arr, 0, 0, m, n);
}

// Memoization
int minCostPath_memo(int** arr, int i, int j, int m, int n, int** output){
    if(i == m-1 && j == n-1){
        return arr[i][j];
    }
    
    if(output[i][j] != -1){
        return output[i][j];
    }

    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    if(i < m-1){
        x = minCostPath_memo(arr, i + 1, j, m, n, output);
    }
    if(j < n-1)
        y = minCostPath_memo(arr, i, j+1, m, n, output);
    if(i< m-1 && j< n-1){
        z = minCostPath_memo(arr, i+1, j+1, m, n, output);
    }
    
    output[i][j] = arr[i][j] + min(x, min(y,z));

    return output[i][j];
}

int minCostPath_memo(int** arr, int m, int n){
    int **output = new int*[m];
    for(int i = 0; i<m; i++)
        output[i] = new int[n];

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            output[i][j] = -1;

    int ans = minCostPath_memo(arr, 0, 0, m, n, output);


    for(int i = 0 ; i < m; i++)
    delete[] output[i];	// delete array within matrix
    delete[] output;
    return ans;
}

// Dynamic Programming
int minCostPath_dp(int** input, int m, int n){
    int **output = new int*[m];
    for(int i = 0; i<m; i++)
        output[i] = new int[n];
    
    // Fill the last cell i.e. Destination
    output[m-1][n-1] = input[m-1][n-1];

    // Fill last row (right to left)
    for(int j = n-2; j>=0; j--){
        output[m-1][j] = output[m-1][j+1] + input[m-1][j];
    }

    // Fill Last Column (bottom to top)
    for(int i = m-2; i>=0; i--){
        output[i][n-1] = output[i+1][n-1] + input[i][n-1];
    }

    // Fill the remaing cells
    for(int i= m-2; i >= 0; i--){
        for(int j= n-2; j >= 0; j--){
            output[i][j] = min(output[i][j+1], min(output[i+1][j+1], output[i+1][j])) + input[i][j];
        }
    }

    int ans = output[0][0];

    for(int i = 0 ; i < m; i++)
    delete[] output[i];	// delete array within matrix
    delete[] output;

    return ans;
}


int main()
{
    int m;
    cin>>m;
    int n;
    cin>>n;
    
    int** arr = new int*[m];
    for(int i = 0; i < m; i++)
        arr[i] = new int[n];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    int* pos = &(arr[0][0]);
    cout<<minCostPath(arr, m, n)<<endl;
    cout<<minCostPath_memo(arr, m, n)<<endl;
    cout<<minCostPath_dp(arr, m, n)<<endl;

    // free
    for(int i = 0 ; i < m; i++)
    delete[] arr[i];	// delete array within matrix
    delete[] arr;

    return 0;
}