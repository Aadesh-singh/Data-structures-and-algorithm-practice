#include<iostream>
#include<string>
using namespace std;

string returnString( char c ){
    if(c == '2') return "abc";
    else if (c == '3') return "def";
    else if (c == '4') return "ghi";
    else if (c == '5') return "jkl";
    else if (c == '6') return "mno";
    else if( c == '7') return "pqrs";
    else if ( c== '8') return "tuv";
    else if ( c == '9') return "wxyz";
    else return " ";
}

void keyboardSequence ( string input, string output){
    if(input.length() == 0){
        cout<<output<<endl;
        return;
    }
    string str = returnString(input[0]);
    for(int i=0; i<str.length(); i++){
        keyboardSequence(input.substr(1), output + str[i]);
    }
    return;
}

int main() {
    string input, output;
    cin>>input;
    keyboardSequence(input, output);
    return 0;
}