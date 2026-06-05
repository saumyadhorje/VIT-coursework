#include <iostream>
using namespace std;

// Interface
class Vehicle
{
public:
    virtual void gearChange(int g) = 0;
    virtual void speedUp(int s) = 0;
    virtual void applyBrakes(int b) = 0;
};

// Bicycle class
class Bicycle : public Vehicle
{
public:
    int speed, gear;

    Bicycle()
    {
        speed = 0;
        gear = 0;
    }

    void gearChange(int g)
    {
        gear = g;
    }

    void speedUp(int s)
    {
        speed = speed + s;
    }

    void applyBrakes(int b)
    {
        speed = speed - b-1;
    }

    void display()
    {
        cout << "Bicycle Speed: " << speed << endl;
        cout << "Bicycle Gear: " << gear << endl;
    }
};

// Bike class
class Bike : public Vehicle
{
public:
    int speed, gear;

    Bike()
    {
        speed = 0;
        gear = 0;
    }

    void gearChange(int g)
    {
        gear = g;
    }

    void speedUp(int s)
    {
        speed = (speed + s)*2;
    }

    void applyBrakes(int b)
    {
        speed = speed - b -2;
    }

    void display()
    {
        cout << "Bike Speed: " << speed << endl;
        cout << "Bike Gear: " << gear << endl;
    }
};

// Car class
class Car : public Vehicle
{
public:
    int speed, gear;

    Car()
    {
        speed = 0;
        gear = 0;
    }

    void gearChange(int g)
    {
        gear = g;
    }

    void speedUp(int s)
    {
        speed = (speed + s)*3;
    }

    void applyBrakes(int b)
    {
        speed = (speed - b)-4;
    }

    void display()
    {
        cout << "Car Speed: " << speed << endl;
        cout << "Car Gear: " << gear << endl;
    }
};

int main()
{
    Bicycle b1;
    Bike b2;
    Car c;

    b1.gearChange(2);
    b1.speedUp(10);
    b1.applyBrakes(3);
    b1.display();

    cout << endl;

    b2.gearChange(4);
    b2.speedUp(50);
    b2.applyBrakes(10);
    b2.display();

    cout << endl;

    c.gearChange(5);
    c.speedUp(80);
    c.applyBrakes(20);
    c.display();

    return 0;
}