#include<iostream>
#include<string>
#include"./implementation.h"
using namespace std;

int main(){
    OurMap<int> map;
    for(int i=0; i<10; i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        map.insert(key, value);
        cout<<map.getLoadFactor()<<endl;
    }
    cout<<map.size() <<endl;
    map.erase("abc3");
    map.erase("abc0");
    map.erase("abc7");
    cout<<map.size() <<endl;
    for(int i=0; i<10; i++){
        char c = '0' + i;
        string key = "abc";
        key += c;
        cout<<key<<": "<<map.getValue(key) <<endl;
    }

    cout<<map.size() <<endl;
}