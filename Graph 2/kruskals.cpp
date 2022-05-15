#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Edge {
    public:
    int source;
    int dest;
    int weight;

    Edge(int source, int dest, int weight){
        this->source = source;
        this->dest = dest;
        this->weight = weight;
    }
};

// third argument taken by sort function in case we have to sort
// a array/vector of pair by its component, in out case Edge class.
bool sortbysec(const Edge &a, const Edge &b){
    return (a.weight < b.weight);
}

void takeInput(int e, vector<Edge > &input){
    int source, dest, weight, i = 0;
    while(e > 0){
        cin>>source>>dest>>weight;
        Edge ne(source, dest, weight);
        input.push_back(ne);
        i++;
        e--;
    }
}

int topMostParent(int s, int* parent){
    if(parent[s] == s){
        return s;
    }
    return topMostParent(parent[s], parent);
}

bool checkEdge(int s, int d, int* parent){
    int ps = topMostParent(s, parent);
    int pd = topMostParent(d, parent);
    if(ps == pd){
        return false;
    } else {
        parent[d] = ps;
        return true;
    }
}


void kruskals(vector<Edge> &input, int n, vector<Edge> &output, int* parent){
    sort(input.begin(), input.end(), sortbysec);
    int count = 0;
    bool ans = false;
    int i=0;
    while(count < n-1){
        ans = checkEdge(input[i].source, input[i].dest, parent);
        if(ans){
            output.push_back(input[i]);
        }
        i++;
        count++;
    }
}


int main()
{
    int n,e;
    cin>>n>>e;

    int* parent = new int[n];
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    vector<Edge > input;
    vector<Edge > output;
    takeInput(e, input);
    cout<<"Your Input"<<endl;
    for(auto i: input){
        cout<<i.source<<" "<<i.dest<<" "<<i.weight<<endl;
    }
    
    kruskals(input, n, output, parent);



    cout<<"Your Output"<<endl;
    for(auto i: output){
        cout<<i.source<<" "<<i.dest<<" "<<i.weight<<endl;
    }
    
    return 0;
}