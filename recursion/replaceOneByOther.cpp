#include<iostream>
using namespace std;

void replaceOneByOther(char s[], char c1, char c2) {
    if(s[0] == '\0') return  ;

        replaceOneByOther(s+1, c1, c2);
        
        if(s[0] == c1) {
            s[0] = c2;
        }
    return ;
}


int main() {
    char s[10];
    char c1,c2;
    cin>>s;
    cin>>c1>>c2;
    replaceOneByOther(s, c1, c2);
    cout<<s;
    return 0;
}