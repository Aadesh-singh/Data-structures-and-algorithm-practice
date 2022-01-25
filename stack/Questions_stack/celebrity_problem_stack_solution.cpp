#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int findCelebrity(vector<vector<int>> &v, int n){
    stack<int> s1;

    for(int i=0; i<n; i++){
        s1.push(i);
    }
    
    while(s1.size() > 1){
        int a = s1.top();
        s1.pop();
        int b = s1.top();
        s1.pop();
        if(v[a][b] == 0){
            s1.push(a);
        }
        else{
            s1.push(b);
        }
    }
    int pot_celeb = s1.top();

    for(int i=0; i<n; i++){
        if(i == s1.top())
            continue;
        if(v[pot_celeb][i]==1){
            return -1;
        }
        if(v[i][pot_celeb] != 1){
            return -1;
        }
    }
    return pot_celeb;

}



int main() {
    vector<vector<int>> v{ {0,1,0},
                            {0,0,0},
                            {0,1,0}};
    int n = 3;
    int celebrity = findCelebrity(v, n);
    if(celebrity == -1) cout<<"No such celebrity exist in party"<<endl;
    else cout<<celebrity<<" was the celebrity in the party.."<<endl;
    
}