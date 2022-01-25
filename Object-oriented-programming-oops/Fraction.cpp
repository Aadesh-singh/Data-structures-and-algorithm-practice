#include<iostream>
#include<algorithm>
using namespace std;

class Fraction {
    private:
        int num;
        int denom;
    public:
        Fraction(int num, int denom){
            this -> num = num;
            this -> denom = denom;
        }
        void print() {
            cout<< num <<" / "<< denom<<endl;
        }

        void simplify(){
            int gcd = 1;
            int j = min(num , denom);
            for(int i = 1; i<= j; i++){
                if( num % i == 0 && denom % i == 0){
                    gcd = i;
                }
            }
            num = num / gcd;
            denom = denom / gcd;
        }

        void add(Fraction const &f2){
            int lcm = denom * f2.denom;
            int x = lcm / denom;
            int y = lcm / f2.denom;
            num = x * num + (y * f2.num);
            denom = lcm;

            simplify();
        }
        void multiply(Fraction const &f2){
            num = num * f2.num;
            denom = denom * f2.denom;
            simplify();
        }

};


int main() {
    Fraction f1(10,2);
    Fraction f2(15,4);
    cout<<"f1 and f2 are"<<endl;
    f1.print();
    f2.print();
    cout<<"before Adding f2, f1 is: ";
    f1.print();
    f1.add(f2);
    cout<<"After Adding f2, f1 is: ";
    f1.print();
    cout<<"Before multiplying f2, f1 is: ";
    f1.print();
    cout<<"After multiplying f2, f1 is: ";
    f1.multiply(f2);
    f1.print();
}