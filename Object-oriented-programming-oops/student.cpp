#include<iostream>
using namespace std;
class student {
    int age;
    public:
    int rollNumber;

    void display() {
        cout<<"Age is: "<<age<<" Rollnumber: "<<rollNumber<<endl;
    }
    int getAge() {
        return age;
    }
    void setAge(int newAge);
};

void student :: setAge(int newAge) {
        if(newAge < 0) {
            cout<<"False age Asshole: "<<endl;
            return;
        }
        age = newAge;
    }