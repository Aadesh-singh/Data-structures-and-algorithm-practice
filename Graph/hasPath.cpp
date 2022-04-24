#include<iostream>
#include<queue>
using namespace std;

void printBFS(int** edges, int n, int sv, bool* visited){
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
        int front = q.front();
        cout<<front<<endl;
        q.pop();
        for(int i=0; i<n; i++){
            if(edges[front][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int** edges, int n){
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            printBFS(edges, n, i, visited);
        }
    }

    delete [] visited;
}


bool hasEdge(int** edges, int n, int si, int ei, bool* visited){
    if(edges[si][ei] == 1){
        return true;
    }
    // bool ans = false;
    queue<int> q;
    q.push(si);
    visited[si] = true;
    while(!q.empty()){
        int front = q.front();
        // cout<<front<<endl;
        q.pop();
        if(edges[front][ei] == 1){
            return true;
        } else {
            for(int i=0; i<n; i++){
                if(edges[front][i] == 1 && !visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    return false;
}
bool hasEdge(int** edges, int n, int si, int ei){
    bool* visited = new bool[n];

    bool ans = hasEdge(edges, n, si, ei, visited);

    delete [] visited;
    return ans;
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
    BFS(edges, n);
    cout<<"Is Path Available: "<<endl;
    cout<<hasEdge(edges, n, si, ei);


    for(int i=0; i<n; i++)
        delete [] edges[i];

    delete [] edges;

    return 0;
}