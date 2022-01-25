#include<iostream>
#include<algorithm>
using namespace std;

class Fraction {
    private:
        int num;
        int denom;
    public :
        Fraction(int num, int denom){
            this->num = num;
            this->denom = denom;
        }
        void print(){
            cout<<num<<" / "<<denom<<endl;
        }
        void simplify(){
            int gcd = 1;
            int j = min(num , denom);
            for(int i =1; i<=j;i++){
                if(num % i == 0 && denom % i == 0){
                    gcd = i;
                }
            }
            num = num / gcd;
            denom = denom / gcd;
        }
        Fraction add(Fraction const &f2) const{
            int lcm = denom * f2.denom;
            int x = lcm / denom;
            int y = lcm / f2.denom;
            int num1 = x*num + ( y*f2.num);

            Fraction fNew(num1, lcm);
            fNew.simplify();
            return fNew; 
        }
        Fraction operator+(Fraction const &f2) const{
           int lcm = denom * f2.denom;
            int x = lcm / denom;
            int y = lcm / f2.denom;
            int num1 = x*num + ( y*f2.num);

            Fraction fNew(num1, lcm);
            fNew.simplify();
            return fNew;
        }
        Fraction multiply(Fraction const &f2) const{
            int newNum = num * f2.num;
            int newDenom = denom * f2.denom;
            Fraction fNew( newNum , newDenom );
            fNew.simplify();
            return fNew;
        }
        Fraction operator*(Fraction const &f2) const{
            int newNum = num * f2.num;
            int newDenom = denom * f2.denom;
            Fraction fNew(newNum ,newDenom);
            fNew.simplify();
            return fNew;
        }

        bool operator==(Fraction const &f2) const{
            return (num == f2.num && denom == f2.denom);
        }
        // pre increment
        Fraction& operator++(){
            this->num = this->num + this->denom;
            simplify();
            return *this;
        }
        //Post increment   - to diffentiate b/w pre and post we write int for post on paranthesis
        Fraction operator++(int){
            Fraction fNew(num, denom);
            num = num + denom;
            simplify();
            fNew.simplify();
            return fNew;
        }
        Fraction operator+=(Fraction const &f2){
            int lcm = denom * f2.denom;
            int x = lcm / denom;
            int y = lcm / f2.denom;
            int num1 = x*num + ( y*f2.num);

            num = num1;
            denom = lcm;
            simplify();
            return *this;
        }
        Fraction operator-=(Fraction const &f2){
            int lcm = denom * f2.denom;
            int x = lcm / denom;
            int y = lcm / f2.denom;
            int num1 = x*num - ( y*f2.num);

            num = num1;
            denom = lcm;
            simplify();
            return *this;
        }
};

int main() {
    Fraction f1(10, 2);
    Fraction f2(15,4);
    f1.print();
    f2.print();
    Fraction f3 = f1.add(f2);
    f3.print();
    Fraction f4 = f1 + f2;
    f4.print();
    Fraction f5 = f1.multiply(f2);
    f5.print();
    Fraction f6 = f1 * f2;
    f6.print();
    if(f1 == f2){
        cout<<"Equal"<<endl;
    }
    else {
        cout<<"Not Equal"<<endl;
    }
    cout<<"Pre increment: ";
    ++(++f1);
    f1.print();
    cout<<"Post increment: ";
    f1++;
    f1.print();
    // += operator
    cout<<" f2 += f1:   ";
    f2 += f1;
    f2.print();
    // -= operator
    cout<<" f2-=f1: ";
    f2 -= f1;
    f2.print();
}