#include<iostream>
#include<string>
using namespace std;

bool validString(string s){
    if(s[0] == NULL) return 1;
    
    if(s[0] == 'a'){
        if(s[1] == 'a'){
            return validString(s.substr(1));
        } else if(s[1] == 'b'){
            return validString(s.substr(1));
        }
        else if(s[1] == NULL)  return 1;
        else return 0;
    }
    else if( s[0] == 'b'){
        if(s[1] == 'b' && s[2] == 'a'){
            return validString(s.substr(2));
        }
        else if(s[1] == 'b' && s[2] == NULL){
            return 1;
        }
        else return 0;
    }
}

int main(){
    string s;
    cin>>s;
    if(s[0] == 'a'){
        if(validString(s.substr(1))){
            cout<<"valid String";
            return 1;
        }
        else {
            cout<<"Not a Valid String";
            return 0;
        }
    }

}