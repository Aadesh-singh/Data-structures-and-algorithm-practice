#include<iostream>
#include<math.h>
#include<string>
using namespace std;

int length1(string s){
    int count = 0;
    for(int i=0; s[i]!='\0'; i++) count++;

    return count;
}
// way1
int stringToInt(string s) {
    if(s.length() == 1) return (s[0] - '0');
    
    double ans = stringToInt(s.substr(1));
    double num = s[0] - 48;
    num = num*(pow(10,s.length()-1)) + ans;
    return (num);

}

int main() {
    string s = "12345";
    cout<<(  stringToInt(s))<<endl;
    return 0;
}