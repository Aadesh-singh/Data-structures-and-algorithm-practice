// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <iostream>
#include<string>
#include<stack>
#include<climits>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> s;
        int a,b,ans;
        for(int i=0; i < S.length() ; i++){
            if(( S[i] != '*' ) && ( S[i] != '/' ) && ( S[i] != '+' ) && ( S[i] != '-' ) ){
                s.push(S[i] - '0');
            }
            else {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                if(S[i] == '*'){
                    ans = b * a;
                }
                else if(S[i] == '/'){
                    ans = b / a;
                }
                else if(S[i] =='+'){
                    ans = b + a;
                }
                else if(S[i] == '-'){
                    ans = b - a;
                }
                s.push(ans);
            }
        }
            return s.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}