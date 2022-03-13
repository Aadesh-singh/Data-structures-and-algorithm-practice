#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    
    priority_queue < int ,vector<int> , greater<int> > pq;
    for(int i=0 ; i<input.size() ; i++)
    {
        for(int j=0 ; j<input[i]->size() ;j++)
        {
            pq.push(input[i]->at(j));
        }
    }
 	
    vector<int> ans;
    
    while(!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    
    return ans;
}


int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    vector<int> v2;
    v2.push_back(0);
    v2.push_back(2);
    v2.push_back(4);

    vector<vector<int>*> v;
    v.push_back(&v1);
    v.push_back(&v2);

    vector<int> ab = mergeKSortedArrays(v);
    for(auto x: ab){
        cout<<x<<" ";
    }
    
    return 0;
}