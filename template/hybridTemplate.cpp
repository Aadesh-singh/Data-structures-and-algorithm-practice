#include<iostream>
using namespace std;

template <typename T, typename V>

class Pair{
    T x;
    V y;
    public:
    void setX(T x){
        this->x = x;
    }
    T getX(){
        return this->x;
    }
    void setY(V y){
        this->y = y;
    }
    V getY(){
        return this->y;
    }

};


int main(){
    Pair<int, double> p1;
    p1.setX(20);
    p1.setY(100.23);
    cout<<p1.getX()<<" "<<p1.getY()<<endl;

    Pair<int, double> p2;
    p2.setX(30);
    p2.setY(20.34);
    cout<<p2.getX()<<" "<<p2.getY()<<endl;
}