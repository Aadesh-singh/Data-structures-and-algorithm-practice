#include<iostream>
using namespace std;

void removeDuplicate(char s[]){
    if(s[0] == '\0') return ;

    removeDuplicate(s+1);

    if(s[0]==s[1]){
        int i=1;
        for(;s[i]!='\0';i++){
            s[i] = s[i+1];
        }
            s[i] = s[i+1];
    }
    return;
}

int main() {
    char s[] = "CCooddiinnggNNiinnnnjjjjaaaassss";
    removeDuplicate(s);
    cout<<s;
    return 0;
}