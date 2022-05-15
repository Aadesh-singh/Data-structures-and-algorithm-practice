#include<iostream>
#include<climits>
using namespace std;

void prims(int** edges, int* parent, int* weight, bool* visited, int n, int e){
    weight[0] = 0;
    parent[0] = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(edges[i][j] != -1 && !visited[j]){
                if(weight[j] > edges[i][j]){
                    weight[j] = edges[i][j];
                    parent[j] = i;
                }
            }
        }
        visited[i] = true;
    }

    for(int i=1; i<n; i++){
        cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
    }
}



int main()
{
    int n, e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = -1;
        }
    }
    int* parent = new int[n];
    int* weight = new int[n];
    bool* visited = new bool[n];

    for(int i=0; i<n; i++){
        weight[i] = INT_MAX;
        parent[i] = NULL;
        visited[i] = false;
    }

    
    for(int i=0; i<e; i++){
        int s, f, weight;
        cin>>s>>f>>weight;
        edges[s][f] = weight;
        edges[f][s] = weight;
    }
    cout<<"Your Output"<<endl;
    prims(edges, parent, weight, visited, n, e);







    delete [] parent;
    delete [] visited;
    delete [] weight;

    for(int i=0; i<n; i++){
        delete [] edges[i];
    }
    delete [] edges;
    
    return 0;
}