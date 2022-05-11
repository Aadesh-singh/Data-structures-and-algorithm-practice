#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// vector<vector<int>> getAllConnected(int** edges, int n, int s, bool* visited, vector<vector<int>> &vec){
void getAllConnected(int** edges, int n, int s, bool* visited, vector<vector<int>> &vec){
    queue<int> q;
    vector<int> v;
    q.push(s);
    visited[s] = true;
    v.push_back(s);
    while(!q.empty()){
        int fv = q.front();
        q.pop();
        for(int i=0; i<n; i++){
            if(edges[fv][i] && !visited[i]){
                v.push_back(i);
                q.push(i);
                visited[i] = true;
            }
        }
    }
    vec.push_back(v);
}

void printAllComponents(vector<vector<int>> v){
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

void getAllConnected(int** edges, int n){
    bool* visited = new bool[n];
    for(int i=0; i<n; i++)
        visited[i] = false;
    vector<vector<int>> v;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            getAllConnected(edges, n, i, visited, v);
        }
    }

    printAllComponents(v);
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


    cout<<"All Connected Components: "<<endl;
    getAllConnected(edges, n);


    for(int i=0; i<n; i++)
        delete [] edges[i];

    delete [] edges;
    
    return 0;
}