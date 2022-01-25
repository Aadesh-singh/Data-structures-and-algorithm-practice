// Given two arrays, check if one array is
// stack permutation of other.
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

// function to check if input queue is
// permutable to output queue
bool checkStackPermutation(int ip[], int op[], int n)
{
	// Input queue
	queue<int> input;
	for (int i=0;i<n;i++)
		input.push(ip[i]);

	// output queue
	queue<int> output;
	for (int i=0;i<n;i++)
		output.push(op[i]);

	// stack to be used for permutation
	stack <int> tempStack;
	while (!input.empty())
	{
		int ele = input.front();
		input.pop();
		if (ele == output.front())
		{
			output.pop();
			while (!tempStack.empty())
			{
				if (tempStack.top() == output.front())
				{
					tempStack.pop();
					output.pop();
				}
				else
					break;
			}
		}
		else
			tempStack.push(ele);
	}

	// If after processing, both input queue and
	// stack are empty then the input queue is
	// permutable otherwise not.
	return (input.empty()&&tempStack.empty());
}

// Driver program to test above function
int main()
{
	// Input Queue
	int input[] = {1, 2, 3};

	// Output Queue
	int output[] = {2, 1, 3};

	int n = 3;

	if (checkStackPermutation(input, output, n))
		cout << "Yes";
	else
		cout << "Not Possible";
	return 0;
}
