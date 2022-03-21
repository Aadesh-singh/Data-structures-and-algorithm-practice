#include<iostream>
#include"./trieNode.h"
using namespace std;

int main(){
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");

    cout<<t.search("are")<<endl;

    t.removeWord("are");
    cout<<t.search("are");

}
