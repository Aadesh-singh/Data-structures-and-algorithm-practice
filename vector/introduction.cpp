#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &vec)
{
    for(int i=0 ; i < vec.size() ; i++) cout<<vec[i]<<" ";
    cout<<endl;

}

int main()
{
    vector<int> vec1;
    int element , size;
    cout<<" User Enter the Size of the VECTOR: ";
    cin>>size;
    for( int i=0; i< size; i++)
    {
        cout<<"User enter the element to be inserted ";
        cin>>element;
        vec1.push_back(element);       
    }
    display(vec1);
    vector<int> :: iterator iter = vec1.begin();
    // vec1.insert(iter + 3 , 3, 566);
    // display(vec1);
    vec1.erase(vec1.begin(), vec1.begin()+3);
    display(vec1);
    vec1.pop_back();
    display(vec1);
    vec1.clear();
    display(vec1);
    return 0;
}