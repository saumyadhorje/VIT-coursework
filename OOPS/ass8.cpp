#include <iostream>
using namespace std;

class Shape
{
protected:
    int dim1, dim2;

public:
    void getdata()
    {
        cout << "Enter dim1: ";
        cin >> dim1;

        cout << "Enter dim2: ";
        cin >> dim2;
    }

    virtual void compute_area() = 0;
};

// Triangle class
class Triangle : public Shape
{
public:
    void compute_area()
    {
        float area = 0.5 * dim1 * dim2;

        cout << "Area of Triangle: " << area << endl;
    }
};

// Rectangle class
class Rectangle : public Shape
{
public:
    void compute_area()
    {
        int area = dim1 * dim2;

        cout << "Area of Rectangle: " << area << endl;
    }
};

int main()
{
    Shape *s;   // pointer
    Triangle t;
    Rectangle r;

    int choice;

    cout << "Enter choice:" << endl;
    cout << "1. Triangle" << endl;
    cout << "2. Rectangle" << endl;

    cin >> choice;

    if (choice == 1)
    {
        s = &t;
    }
    else
    {
        s = &r;
    }

    s->getdata();
    s->compute_area();

    return 0;
}