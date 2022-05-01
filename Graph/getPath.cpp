#include<iostream>
#include<vector>
using namespace std;

bool getPath(int** edges, int n, bool* visited, int s, int e, vector<int> & res){
    if(s == e){
        res.push_back(s);
        return true;
    }
    visited[s] = true;
    bool ans = false;
    for(int i=0; i<n; i++){
        if(!visited[i] && edges[s][i] == 1){
            ans = getPath(edges, n, visited, i, e, res);
        }
        if(ans){
            res.push_back(s);
            return true;
        }
    }
    return ans;
}

void getPath(int** edges, int n, int s, int e){
    bool* visited = new bool[n];
    vector<int> res;
    bool ans = getPath(edges, n, visited, s, e, res);
    if(ans){
        for(auto it: res){
            cout<<it<<" ";
        }
    }
    delete [] visited;
}


int main()
{
     int n, e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++)
            edges[i][j] = 0;
    }

    for(int i=0; i<e; i++){
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int si; int ei;
    cin>>si>>ei;

    cout<<"BFS Traversal: "<<endl;
    getPath(edges, n, si, ei);
   


    for(int i=0; i<n; i++)
        delete [] edges[i];

    delete [] edges;

    return 0;

    
    return 0;
}