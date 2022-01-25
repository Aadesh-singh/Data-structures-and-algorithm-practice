
#include <iostream>
using namespace std;

// Returns number of pairs in arr[0..n-1]
// with sum equal to 'sum'
int printPairs(int arr[], int n, int sum)
{
	int count = 0; // Initialize result

	// Consider all possible pairs and check
	// their sums
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
            for(int k = j+1; k<n; k++)
                if (arr[i] + arr[j] + arr[k] == sum)
				    cout<< arr[i] << " " << arr[j] <<" "<< arr[k] << endl;
}


int main()
{
	int arr[] = { 1, 4, 1, -1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 6;
	printPairs(arr, n, sum);
	return 0;
}
