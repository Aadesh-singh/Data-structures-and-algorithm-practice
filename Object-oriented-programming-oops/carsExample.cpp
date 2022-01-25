#include<iostream>
using namespace std;

class cars {
    public:
        int price;
};

int main() {
    cars c;
    c.price = 10000;
    cout<<c.price;
}