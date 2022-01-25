#include<iostream>
#include<string>
using namespace std;



int main(){
    string s;
    getline(cin,s);
    int c = 0;
    for(int i = 0; i<s.length() ; i++)
    {
        c = count(s.begin() , s.end() , s[i]);
        cout<<"The no. of "<<s[i]<<"in the string is: "<<c<<"\n";
    }

    return 0;
}