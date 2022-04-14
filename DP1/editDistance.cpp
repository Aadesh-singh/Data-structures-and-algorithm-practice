#include<iostream>
#include<string>
using namespace std;

int editDistance(string s, string t){
    int m = s.size();
    int n = t.size();
    if(m == 0 || n== 0){
        return 0;
    }

    if(s[0] == t[0]){
        return editDistance(s.substr(1), t.substr(1));
    } else {
        int a = 1 + editDistance(s.substr(1), t);
        int b = 1 + editDistance(s, t.substr(1));
        int c = 1 + editDistance(s.substr(1), t.substr(1));

        return min(a, min(b,c));
    }
}

int editDistance_memo(string s, string t, int** output){
    int m = s.size();
    int n = t.size();
    if(m == 0 || n==0){
        return 0;
    }
    int ans;
    if(output[m][n] != -1){
        return output[m][n];
    }
    else {
        int a = 1 + editDistance_memo(s.substr(1), t, output);
        int c = 1 + editDistance_memo(s, t.substr(1), output);
        int b = 1 + editDistance_memo(s.substr(1), t.substr(1), output);

        ans = min(a, min(b, c));
    }
    output[m][n] = ans;
    return ans;
}

int editDistance_memo(string s, string t){
    int m = s.size();
    int n = t.size();
    int** output = new int*[m+1];
    for(int i=0; i<=m; i++){
        output[i] = new int[n+1];
        for(int j=0; j<=n; j++){
            output[i][j] = -1;
        }
    }

    int ans = editDistance_memo(s, t, output);
    for(int i = 0; i<=m; i++){
        delete [] output[i];
    }
    delete [] output;
    return ans;
}


int editDistance_dp(string s, string t){
    int m = s.size();
    int n = t.size();

    int **output = new int*[m+1];
    for(int i=0; i<=m; i++){
        output[i] = new int[n+1];
    }

    for(int j=0; j<=n; j++){
        output[0][j] = 0;
    }
    for(int i=0; i<=m; i++){
        output[i][0] = 0;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[m-i] != t[n-j]){
                int a = 1 + output[i-1][j];
                int b = 1 + output[i][j-1];
                int c = 1 + output[i-1][j-1];

                output[i][j] = min(a, min(b,c));
            }
        }
    }
    int ans = output[m][n];
    for(int i=0; i<=m; i++){
        delete [] output[i];
    }
    delete [] output;

    return ans;
}


int main()
{
    string s;
    string t;
    cin>>s>>t;
    cout<<editDistance(s, t)<<endl;
    cout<<editDistance_memo(s, t)<<endl;
    cout<<editDistance_dp(s, t)<<endl;
    return 0;
}