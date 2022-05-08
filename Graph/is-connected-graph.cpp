#include<iostream>
#include<queue>
using namespace std;

void isConnected(int** edges, int n, int si, bool* visited){
    queue<int> q;
    q.push(si);
    visited[si] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(int i=0; i<n; i++){
            if(edges[front][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

bool isConnected(int** edges, int n){
    bool* visited = new bool[n];
    for(int i=0; i<n; i++)
        visited[i] = false;
    
    isConnected(edges, n, 0, visited);
    for(int j=0; j<n; j++){
        if(visited[j] == false){
            return false;
        }
    }
    delete [] visited;
    return true;
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


    cout<<"Is Connected: "<<endl;
    cout<<isConnected(edges, n);


    for(int i=0; i<n; i++)
        delete [] edges[i];

    delete [] edges;
    
    return 0;
}