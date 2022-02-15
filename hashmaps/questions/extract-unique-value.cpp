#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

string extractUniqueChar(string s){
    unordered_map<char, int> map;
    string output = "";
    for(int i=0; i<s.length(); i++){
        map[s[i]]++;
    }
    for(int i=0; i<s.length(); i++){
        if(map[s[i]] > 0){
            cout<<"s[i]: "<<s[i]<<endl;
            output += s[i];
            map[s[i]] = 0;
            cout<<"Outpus: "<<output<<endl;
        }
    }
    return output;
}

int main() {
    string str;
    cin>>str;
    str = extractUniqueChar(str);
    cout<<str<<endl;
}