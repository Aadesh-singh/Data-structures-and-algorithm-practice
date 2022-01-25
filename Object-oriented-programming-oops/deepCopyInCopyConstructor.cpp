#include<iostream>
#include<cstring>
using namespace std;

class student {
    int age;
    char *name;
    public:
        student(int age, char  *name){
            this->age = age;
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }
        student(student const &s){
            this->age = s.age;
            this->name = new char[strlen(s.name) + 1];
            strcpy(this->name, s.name);
        }
        void display() {
            cout<<this->age<<" "<<this->name<<endl;
        }
};

int main() {
    char name[] = "Wood";
    student s1(10, name);
    s1.display();
    name[0] = 'H';
    student s2(s1);
    s2.display();
}