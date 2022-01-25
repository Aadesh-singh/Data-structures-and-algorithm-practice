#include<iostream>
using namespace std;

class shape {
    public:
    int height;
    int width;
};



int main() {
    shape *s = new shape;
    s->height = 1;
    cout<<s->height;    
}