#include<iostream>
using namespace std;

int knapsack(int* weight, int* values, int n, int maxWeight){
    if(n==0 || maxWeight == 0){
        return 0;
    }

    if(weight[0] > maxWeight){
        return knapsack(weight + 1, values + 1, n-1, maxWeight);
    }

    // Recusive calls
    int x = knapsack(weight + 1, values + 1, n-1, maxWeight - weight[0]) + values[0];
    int y = knapsack(weight + 1, values + 1, n-1, maxWeight);

    return max(x, y);
}

int knapsack_memo(int* weight, int* values, int n, int maxWeight, int* output){
    if(n==0 || maxWeight == 0){
        return 0;
    }
    if(output[n] != -1){
        return output[n];
    }

    if(weight[0] > maxWeight){
        return knapsack_memo(weight + 1, values + 1, n-1, maxWeight, output);
    }

    // Recusive calls
    int x = knapsack_memo(weight + 1, values + 1, n-1, maxWeight - weight[0], output) + values[0];
    int y = knapsack_memo(weight + 1, values + 1, n-1, maxWeight, output);
    output[n] = max(x, y);
    return output[n];
}

int knapsack_memo(int* weight, int* values, int n, int maxWeight){
    int* output = new int[n+1];
    for(int i=0; i<=n; i++){
        output[i] = -1;
    }
    int ans = knapsack_memo(weight, values, n, maxWeight, output);
    delete [] output;
    return ans;
}


int knapsack_dp(int* weight, int* values, int n, int maxWeight){
    //  int dp[n+1][maxWeight+1];
     int** dp = new int*[n+1];
     for(int i=0; i<=n; i++){
         dp[i] = new int[maxWeight+1];
     }
	 for(int i =0 ; i<=n ;i++)
		 { for(int j=0 ;j<=maxWeight ;j++)
			 {
 			    if( i==0 || j== 0)
 			        dp[i][j]=0;
 			    else
 			    {  if(weight[i-1]>j)
 		  	         dp[i][j]  = dp[i-1][j];
 			        else
 			         dp[i][j]= max( values[i-1] + dp[i-1][j-weight[i-1]], dp[i-1][j]) ; 
 			    }
			 }
		 }
    int ans =  dp[n][maxWeight];
    for(int i=0; i<=n; i++){
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}


int main()
{
    int n; cin>>n;
    int* weight = new int[n];
    int* values = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>values[i];
    }
    int maxWeight;
    cin>>maxWeight;
    cout<<knapsack(weight, values, n, maxWeight)<<endl;
    cout<<knapsack_memo(weight, values, n, maxWeight)<<endl;
    cout<<knapsack_dp(weight, values, n, maxWeight)<<endl;

    delete [] weight;
    delete [] values;
    return 0;
}