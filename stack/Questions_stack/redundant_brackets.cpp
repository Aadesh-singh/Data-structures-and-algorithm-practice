#include<iostream>
#include<stack>

using namespace std;

bool redundant_bracket(stack<int> s, string str){
    int count = 0;
    for(int i=0; i< str.length(); i++){
        if(str[i] == ')'){
            while(s.top() != '('){
                s.pop();
                count++;
            }
            if( s.top() == '('){
                if(count == 0){
                    return true;
                }
                else{
                    s.pop();
                    count = 0;
                }
            }
        }
        else {
            s.push(str[i]);
        }
    }
    return false;
}

int main() {
    stack<int> s;
    // string str = "(a + (a + b))";  //give false that is 0
    string str = "((a + b))";  //give true that is 1
    cout<<redundant_bracket(s, str)<<endl;
}