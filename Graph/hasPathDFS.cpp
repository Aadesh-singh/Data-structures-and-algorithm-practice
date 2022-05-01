#include<iostream>
using namespace std;

void print(int** edges, int n, int sv, bool* visited){
    cout<<sv<<endl;
    visited[sv] = true;
    for(int i=0; i<n; i++){
        if(i == sv){
            continue;
        }
        if(edges[sv][i] == 1){
            if(visited[i]){
                continue;
            }
            print(edges, n, i, visited);
        }
    }
}

bool haspath(int**graph ,int v ,bool* visited,int s ,int e)
{
   if(graph[s][e]==1) return true;
    
    visited[s]=true;
    
    bool res =false;
    
    for(int i=0 ;i<v ;i++)
    {		
        if(!visited[i] && graph[s][i]==1)
		 res=haspath(graph,v,visited,i,e);
        if( res== true)
            return true;
    }
    
    return res;
    
}

int main()
{
     int V, E;
    cin >> V >> E;

    int* * graph = new int * [V];
    
    for(int i=0 ;i <V ;i++)
    {
        graph[i]=new int[V];
        for( int j=0 ;j<V ;j++)
           graph[i][j]=0; 
    }
    
    for(int i=0 ;i< E ;i++)
    {
        int x,y; 
        cin>>x>>y;
        graph[x][y]=1;
        graph[y][x]=1;
    }
     bool * arr=new bool[V];
        for(int i=0 ;i< V;i++)
            arr[V]= false;
    int s,e;
    
    cin>> s>>e;
    
    if(haspath(graph,V,arr,s,e))
        cout<< "true";
    else 
        cout<<"false";
    
    
      delete []  arr;
    for(int i = 0 ;i <V ;i++)
        delete [] graph[i];
  
    delete[] graph;
    
    return 0;
}