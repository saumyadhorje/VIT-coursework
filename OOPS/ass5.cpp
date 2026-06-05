#include <iostream>
using namespace std;
class complex{
    public:
    int image;
    int real;

    complex(){
        image=0;
        real=0;
    }
    complex(int r,int i){
        real=r;
        image=i;
    }

    complex operator +(complex c){
        return complex(real+c.real, image+c.image);
    }
     complex operator -(complex c){
        return complex(real-c.real, image-c.image);
    }
     complex operator *(complex c){
        return complex(real*c.real-image*c.image,
                        real*c.image+image*c.real);
    };
    void display(){
     cout << real << " + " << image << "i" << endl;
    }
};
int main(){
    complex c1(4,5);
    complex c2(7,6);
     complex sum, diff, prod;

    // Calling overloaded operators
    sum = c1 + c2;
    diff = c1 - c2;
    prod = c1 * c2;

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    cout << "\nAddition: ";
    sum.display();

    cout << "Subtraction: ";
    diff.display();

    cout << "Multiplication: ";
    prod.display();

    return 0;
}
