#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

void getPathBfs(int** edges, int n, int s, int e, vector<int> &res, bool* visited){
    
    queue<int> q;
    unordered_map<int, int> map;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        if(edges[front][e] == 1){
            res.push_back(e);
            while(front!=s)
            {
                res.push_back(front);
                front = map[front];
                
            }
            res.push_back(s); 
            return;
        }
        for(int i=0; i<n; i++){
            if(edges[front][i] == 1 && !visited[i]){
                map[i] = front;
                q.push(i);
                visited[i] = true;
            }
        }
    }
    
}
void getPathBfs(int** edges, int n, int s, int e){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }
    vector<int> v;
    getPathBfs(edges, n, s, e, v, visited);

    for(auto i: v){
        cout<<i<<" ";
    }
    cout<<endl;

    delete [] visited;
}

int main()
{
    int n,e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }

    int f, s;
    for(int i=0; i<e; i++){
        cin>>s>>f;
        edges[s][f] = 1;
        edges[f][s] = 1;
    }
    int si, ei;
    cin>>si>>ei;
    getPathBfs(edges, n, si, ei);


    for(int i=0; i<n; i++){
        delete [] edges[i];
    }
    delete [] edges;
    
    return 0;
}