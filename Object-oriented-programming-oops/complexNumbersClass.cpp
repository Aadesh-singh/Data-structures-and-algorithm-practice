#include<iostream>
using namespace std;

class ComplexNumbers {
    int real;
    int image;
    public:
        ComplexNumbers(int real, int image){
            this -> real = real;
            this -> image = image;
        }
        void print() {
            cout << this -> real << " + " << "i" << this -> image << endl;
        }
        void add (ComplexNumbers const &c2) {
            real = real + c2.real;
            image = image + c2.image;
        }
        void multiply(ComplexNumbers const &c2){
            real = real* c2.real + ( -1 * (image * c2.image));
            image = (real* c2.image) + (c2.real * image);
        }
};

int main() {
    int real1, image1, real2, image2, choice;
    cout<<"Enter the real and imaginary part of c1: ";
    cin>>real1>>image1;
    cout<<"Enter the real and imaginary part of c2: ";
    cin>>real2>>image2;

    ComplexNumbers c1(real1 , image1);
    ComplexNumbers c2(real2 , image2);

    cout<<"Enter 1 for add and 2 for multiply: ";
    cin>>choice;
    if(choice == 1){
        cout<<"Before addition c1 is: ";
        c1.print();
        c1.add(c2);
        cout<<"After Addition c1 is: ";
        c1.print();
        cout<<"c2 is: ";
        c2.print();
    }
    else if(choice == 2) {
        cout<<"Before Multiplication c1 is: ";
        c1.print();
        c1.multiply(c2);
        cout<<"After Multiplication c1 is: ";
        c1.print();
        cout<<"c2 is: ";
        c2.print();
    }

}