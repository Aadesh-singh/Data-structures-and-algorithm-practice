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


int knapsack_memo(int* weight, int* values, int n, int maxHeight){
    // 
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

    delete [] weight;
    delete [] values;
    return 0;
}