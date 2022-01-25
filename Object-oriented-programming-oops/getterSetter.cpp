#include<iostream>
#include "student.cpp"
using namespace std;


int main(){
     student s1;
     cout<<s1.getAge()<<endl;
     s1.setAge(11);
     s1.rollNumber = 53;
     s1.display();

    //  dynamic case

    student *s2  = new student;
    cout<< (*s2).getAge()<<endl;     /// way 1 of accessisng using dot syntax.
    (*s2).setAge(23); 
    (*s2).rollNumber = 71;
    (*s2).display();


    student *s3 = new student;          // way 2 of accessing using arrow syntax.
    cout<< s3 -> getAge()<<endl;
    s3->setAge(30);
    s3->rollNumber = 76;
    s3->display();


}