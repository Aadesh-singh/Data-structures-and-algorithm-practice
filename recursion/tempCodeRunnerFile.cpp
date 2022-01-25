#include<iostream>
#include<math.h>
using namespace std;

int size(int n){
    int count = 0;
    while(n != 0){
        n /= 10;
        count++;
    }
    return count;
}
int subSequence(int input, string output[]){
    if(input == 0 ){
        output[0] = " ";
        return 1;
    }
    int smallOutputSize = subSequence(input/10, output);
    int tg = input%10;
    char chartg = 3*tg + 92;
    int j= 0;
    while( j< tg){
        for(int i=0; i <= smallOutputSize; i++){
            output[i + smallOutputSize] = output[j] + chartg;
            chartg++;
        }
        j++;
    }
    return 3*smallOutputSize;
}

int main(){
    int input;
    cin>>input;
    int inpSize= size(input);
    int n = pow(inpSize,3);
    string output[n];
    int count = subSequence(input,output);
    for(int i=0; i< count; i++){
        cout<<output[i]<<endl;
    }
    
}