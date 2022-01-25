#include<iostream>
#include<cstring>
using namespace std;

class student {
    int age;
    char *name;
    public:
        // student(int age, char *name){
        //     this->age = age;
        //     this->name = name;     //shallow copy
        // }
        student(int age, char *name){
            this->age = age;
            this->name = new char[strlen(name) + 1];        // Deep copy
            strcpy(this->name , name);
        }
        ~student(){
            delete name;
        }
        void display(){
            cout<<name<< " "<< age<<endl;
        }
};

int main() {
    char name[] = "wood";
    student s1(20, name);
    s1.display();

    name[0] = 'h';

    student s2(22, name);

    s2.display();
    s1.display();
}