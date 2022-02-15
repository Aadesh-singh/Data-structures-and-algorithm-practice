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




    // Traversing of Unordered map: 
    unordered_map<string, int> m1;
    m1.insert({"sss", 1});
    m1.insert({"sss1", 2});
    m1.insert({"sss2", 3});
    m1.insert({"sss3", 4});
    m1.insert({"sss4", 15});
    unordered_map<string, int>:: iterator i = m1.begin();
    while(i != m1.end()){
        cout<<"Key: "<<i->first<<": "<<i->second<<endl;
        i++;
    }
    m1.erase(m1.begin(), m1.end());
    unordered_map<string, int>:: iterator it = m1.begin();
    while(it != m1.end()){
        cout<<"Key: "<<it->first<<": "<<it->second<<endl;
        it++;
    }
}