#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cout<<"Enter the input: ";
    getline(cin, str);
    cout<<"initial string: "<<str<<"\n";
    str.push_back('o');
    cout<<"String after push_back('O') : "<<str<<"\n";
    str.pop_back();
    cout<<"String after pop_back() operation: "<<str<<"\n";
    cout<<"Capacity of the String: "<<str.capacity()<<"\n";
    cout<<"Length of the String: "<<str.length()<<"\n";
    str.resize(2);
    cout<<"Length after resise: "<<str.length()<<"\n";
    cout<<"String after resise: "<<str<<"\n";
    cout<<"Capacity after resise: "<<str.capacity()<<"\n";
    str.shrink_to_fit();
    cout<<"Capacity after shrink_to_fit(): "<<str.capacity()<<"\n";
    // new string
    string str1     = "hello brother";
    cout<<"Iteration using begin and end:\n";
    for(string::iterator it = str1.begin(); it<str1.end() ; it++){
        cout<<*it;
    }cout<<"\n";
    cout<<"Iteration using rbegin and rend: \n";
    for(auto it = str1.rbegin(); it != str1.rend(); ++it){
        cout<<*it;
    }cout<<"\n";


    return 0;
}