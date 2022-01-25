#include<iostream>
#include <string>
using namespace std;

void printAllCodes(string input, string output){
    if(input.size() == 0) {
        cout<<output<<endl;
        return;
    }
    char c1 = (input[0] - '0') + 96;
    
    printAllCodes(input.substr(1), output+c1);

    
    int d = ((input[0] - '0')*10 + (input[1] - '0'));
    if(d>=10 && d<=26 ){
        char c2 = d + 96;
        printAllCodes(input.substr(2), output+c2);
    }       
    return;
}
int main() {
    string input = "1123";
    string output = "";
    printAllCodes(input,output);
    return 0;
}