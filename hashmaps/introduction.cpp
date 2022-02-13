#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
    unordered_map<string, int> map;
    pair<string, int> p("abc", 1);
    map.insert(p);
    map["def"] = 2;
    map["efg"];
    cout<<"size: "<<map.size()<<endl;
    map["def"] = 3;
    // cout<<map.at("rr")<<endl;

    cout<<map["abc"]<<endl;
    cout<<map["def"]<<endl;
    cout<<map["efg"]<<endl;
    cout<<"size: "<<map.size()<<endl;


    if(map.count("abc") > 0){
        cout<<"Is Present"<<endl;
    } else {
        cout<<"Not Present"<<endl;
    }

    map.erase("efg");

    if(map.count("efg") > 0){
        cout<<"Is Present"<<endl;
    } else {
        cout<<"Not Present"<<endl;
    }
}