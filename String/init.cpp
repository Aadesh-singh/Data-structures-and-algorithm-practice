#include<iostream>
#include<string>
using namespace std;

int main() {
    string s , v;
    cout<<"Enter the string you want to print: ";
    getline(cin,s);
    cout<<s<<"\n";
    cout<<"Rewrite the same name as before: ";
    cin>>v;
    cout<<v<<"\n";
    return 0;
}