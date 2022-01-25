#include<iostream>
#include<math.h>
#include<string>
using namespace std;

string getPossibleChars(char c) {
   if(c == '2') return "abc";
   else if(c == '3') return "def";
   else if( c == '4')  return "ghi";
   else if(c == '5') return "jkl";
   else if(c == '6') return "mno";
   else if( c == '7') return "pqrs";
   else if( c== '8') return "tuv";
   else if( c == '9') return "wxyz";
   else return " ";
}

int getKeyPadCombinations(string str, string output[]){
   if(str.length() == 0) {
      output[0] == " ";
      return 1;
   }
   int smallOutputSize = getKeyPadCombinations(str.substr(1), output);
   string firstDigitPossible = getPossibleChars(str[0]);
   int tempSize = firstDigitPossible.length() * smallOutputSize;
   string temp[tempSize];
   int k = 0;

   for(int i=0; i< smallOutputSize; i++){
      for(int j=0; j< firstDigitPossible.length(); j++){
         temp[k] = firstDigitPossible[j] +  output[i];
         k++;
      }
   }
   for(int i=0; i< k; i++){
      output[i] = temp[i];
   }
   return smallOutputSize*firstDigitPossible.length();
}

int main(){
   string input;
   cin>>input;
   int n = pow(input.length(), 4);
   string output[n];
   int outputSize = getKeyPadCombinations(input, output);

   for(int i=0; i< outputSize; i++){
      cout<<output[i]<<endl;
   }
   return 0;
}