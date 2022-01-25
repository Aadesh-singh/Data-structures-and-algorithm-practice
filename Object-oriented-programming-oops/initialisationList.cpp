#include<iostream>
using namespace std;

class student {
    public:
    const int age;
    int rollnumber;
    int &umar;

    student(int age, int roll): age(age), umar(age) {
        rollnumber = roll;
    }
    void print ();
};

void student :: print() {
    cout<<age<<" "<<rollnumber<<" "<<umar;
}

int main() {
    student s2(20, 53);
    s2.print();
}
