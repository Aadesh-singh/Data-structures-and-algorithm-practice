#include<iostream>
#include<string>
using namespace std;

class prop {
    public:
        string name;
        int rollNo;
        ~prop(){
            cout<<"distructor called for "<<this->name<<endl;
        }
        prop() {
            cout<<"constructor 1 called"<<endl;
        }
        prop(int roll){
            cout<<"constructro 2 called"<<endl;
            this->rollNo = roll;
        }
        prop(string name, int rollNo){
            this->name = name;
            this->rollNo = rollNo;
            cout<<"Constructor 3 called"<<endl;
        }
        void display() {
            cout<<name<<" "<<rollNo<<endl;
        }
};
int main() {
    prop w("Aadesh", 53);
    w.display();
    // prop s(w);
    prop s1("hagimaru", 44);
    s1.display();
    // s1 = w;
    // s1.display();
    prop *s2 = new prop("shinchan", 34);
    s2->display();
    // *s2 = s1;
    s2->display();
    delete s2;
}