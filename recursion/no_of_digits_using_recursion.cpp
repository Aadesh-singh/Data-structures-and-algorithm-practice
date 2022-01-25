#include<iostream>
using namespace std;

int digits(int num){
    if(num == 0) {
        return 0;
    }
    return 1 + digits(num/10);              //returning this helps when i want to return nothing in a int type function.
}

int main(){
    int num;
    cin>>num;
    cout<<"Number of digits is: "<<digits(num)<<endl;
}