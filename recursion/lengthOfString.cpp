#include <iostream>
using namespace std;

int length(char s[]){
    if(s[0] == '\0') return 0;
    int ans = length(s+1);
    return 1 + ans;
}

int main() {
    char str[] = "asdfgsndusdhkjdhfkjhgsdfgasd";
    cout<<"length of the given string is: "<<length(str)<<endl;
    return 0;
}