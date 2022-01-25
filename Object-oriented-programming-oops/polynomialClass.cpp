/*
Polynimial class


class Polynomial {
public :
    int *degCoeff;      // Name of your array (Don't change this)
	int capacity;			// total size
public :
 Polynomial() {
		degCoeff = new int[10];
         for(int i=0;i<10;i++)degCoeff[i]=0;
		capacity = 10;
	}

	 Polynomial(const Polynomial &d) {
		this -> degCoeff = new int[d.capacity];
		for(int i = 0; i < d.capacity; i++) {
			this -> degCoeff[i] = d.degCoeff[i];
		}
		this -> capacity = d.capacity;
	}
    
   void setCoefficient(int deg,int coeff) {
          if(deg>=capacity)
          {
              //int size = this->capacity;
             int size=deg+1;
              int *newarr = new int[size];
              for(int i=0;i<capacity;i++)newarr[i]=this->degCoeff[i];
              for(int i=capacity;i<size;i++)newarr[i]=0;
              delete[] this->degCoeff;
              this->degCoeff=newarr;
              this->capacity = size;
          }
          this->degCoeff[deg]=coeff;
    }
    // Complete the class
    void print() {
        for(int i = 0;i<capacity;i++) {
            if(degCoeff[i])
			cout << degCoeff[i] << "x" <<i << " ";
		}
		cout << endl;
    }
    
    Polynomial operator+(Polynomial &p) {
        Polynomial newP;
        newP.capacity = max(p.capacity,capacity);
        newP.degCoeff = new int[newP.capacity];
        
        if (capacity<p.capacity) {
            int k;
            for (k=0;k<capacity;k++) {
                newP.degCoeff[k]=degCoeff[k]+p.degCoeff[k];
            }
            for (;k<p.capacity;k++) {
                newP.degCoeff[k]=p.degCoeff[k];
            }
        } else {
            int k;
            for ( k=0;k<p.capacity;k++) {
                newP.degCoeff[k]=degCoeff[k]+p.degCoeff[k];
            }
            for (;k<capacity;k++) {
                newP.degCoeff[k]=degCoeff[k] ;
            }
        }
        return newP;
    }
    
    Polynomial operator-(Polynomial &p) {
        Polynomial newP;
        newP.capacity = max(capacity,p.capacity);
        newP.degCoeff = new int[newP.capacity];
        
        if (capacity<p.capacity) {
            int k;
            for (k=0;k<capacity;k++) {
                newP.degCoeff[k]=degCoeff[k]-p.degCoeff[k];
            }
            for (;k<p.capacity;k++) {
                newP.degCoeff[k]=-p.degCoeff[k];
            }
        } else {
            int k;
            for ( k=0;k<p.capacity;k++) {
                newP.degCoeff[k]=degCoeff[k]-p.degCoeff[k];
            }
            for (;k<capacity;k++) {
                newP.degCoeff[k]=degCoeff[k] ;
            }
        }
        return newP;
    }
    Polynomial operator*(Polynomial const &p) {
        Polynomial newP;
        newP.capacity = p.capacity+capacity;
        newP.degCoeff = new int[newP.capacity];
        
        for(int i=0;i<newP.capacity;i++)
            newP.degCoeff[i]=0;
        
        for (int i=0;i<capacity;i++) {
            for (int j=0;j<p.capacity;j++) {
                newP.degCoeff[i+j] += degCoeff[i]*p.degCoeff[j];
            }
        }
        return newP;
    }
    Polynomial operator=(Polynomial const &d) {
		this -> degCoeff = new int[d.capacity];
		for(int i = 0; i < d.capacity; i++) {
			this -> degCoeff[i] = d.degCoeff[i];
		}
		this -> capacity = d.capacity;
        return *this;
	}
    
};



*/

#include<iostream>
#include<algorithm>
using namespace std;

class Polynomial {
    int *degreeCoff;
    int capacity;
    public:
    void fillzero(int *a){
        for(int i= 0; i< this->capacity; i++){
            a[i] = 0;
        }
    }
    Polynomial(){
        degreeCoff = new int [5];
        capacity = 5;
        fillzero(degreeCoff);
    }
    Polynomial(Polynomial const &p){
        this->degreeCoff = new int[p.capacity];
        
        for(int i=0 ; i<p.capacity; i++){
            this->degreeCoff[i] = p.degreeCoff[i];
        
        }
        this->capacity = p.capacity;
    }
    Polynomial operator=(Polynomial const &p){
        this->capacity = p.capacity;
        this->degreeCoff = new int[p.capacity];
        for(int i=0; i<p.capacity; i++){
            this->degreeCoff[i] = p.degreeCoff[i];
        }
        return *this;
    }
    void setCofficient( int deg, int coff){
        if(deg >= capacity){
            int size = deg + 1;
            int *newarr = new int[size];
            for(int i = 0; i< capacity; i++){
                newarr[i] = this->degreeCoff[i];
            }
            for(int i=capacity; i<size; i++) newarr[i] = 0;
            delete [] this->degreeCoff;
            this->degreeCoff = newarr;
            this->capacity = size;
        }
        this->degreeCoff[deg] = coff;
    }
    
    Polynomial operator+(Polynomial p){
        Polynomial p3;
        p3.capacity = max(capacity, p.capacity);
        p3.degreeCoff = new int[p3.capacity];

        if( capacity < p.capacity){
            int k;
            for( k=0; k< capacity; k++){
                p3.degreeCoff[k] = degreeCoff[k] + p.degreeCoff[k];
            }
            for(; k<p.capacity; k++){
                p3.degreeCoff[k] = p.degreeCoff[k];
            }
        } else {
            int k;
            for(k =0;k<p.capacity;k++){
                p3.degreeCoff[k] = degreeCoff[k] + p.degreeCoff[k];
            }
            for(; k<capacity; k++){
                p3.degreeCoff[k] = degreeCoff[k];
            }
        }
        return p3;
    }
    Polynomial operator-(Polynomial &p) {
        Polynomial newP;
        newP.capacity = max(capacity,p.capacity);
        newP.degreeCoff = new int[newP.capacity];
        
        if (capacity<p.capacity) {
            int k;
            for (k=0;k<capacity;k++) {
                newP.degreeCoff[k]=degreeCoff[k]-p.degreeCoff[k];
            }
            for (;k<p.capacity;k++) {
                newP.degreeCoff[k]=-p.degreeCoff[k];
            }
        } else {
            int k;
            for ( k=0;k<p.capacity;k++) {
                newP.degreeCoff[k]=degreeCoff[k]-p.degreeCoff[k];
            }
            for (;k<capacity;k++) {
                newP.degreeCoff[k]=degreeCoff[k] ;
            }
        }
        return newP;
    }
    Polynomial operator*(Polynomial const &p) {
        Polynomial newP;
        newP.capacity = p.capacity+capacity;
        newP.degreeCoff = new int[newP.capacity];
        
        for(int i=0;i<newP.capacity;i++)
            newP.degreeCoff[i]=0;
        
        for (int i=0;i<capacity;i++) {
            for (int j=0;j<p.capacity;j++) {
                newP.degreeCoff[i+j] += degreeCoff[i]*p.degreeCoff[j];
            }
        }
        return newP;
    }
    void print() {
        for(int i=0; i< capacity; i++){
            cout<<degreeCoff[i]<<"X"<<i<<" + ";
        }
        cout<<endl;
    }
    
};

int main() {
    // int *degreeCoff; 
    int n=3;
    int arr1[3], arr2[3];
    for(int i=0; i<n; i++) cin>>arr1[i];
    for(int i=0; i<n; i++) cin>>arr2[i];

    Polynomial p1;
    // p1.setPolynomial(arr1,arr2,n);
    for(int i = 0; i<n; i++){
        p1.setCofficient(arr1[i], arr2[i]);
    }
    p1.print();
    int m=3;
    int arr3[3], arr4[3];
    for(int i=0; i<n; i++) cin>>arr3[i];
    for(int i=0; i<n; i++) cin>>arr4[i];

    Polynomial p2;
    // p2.setPolynomial(arr3, arr4, m);
    for(int i = 0; i<m; i++){
        p2.setCofficient(arr3[i], arr4[i]);
    }
    p2.print();
    // Operator +
    Polynomial p3 = p1 + p2;
    p3.print();
    // Operator -
    Polynomial p4 = p1 - p2;
    p4.print();
    // Operator *
    Polynomial p5 = p1 * p2;
    p5.print();
    // Operator =
    Polynomial p6 = p5;
    p6.print();

}