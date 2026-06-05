// AI-Based Smart Student Grading System

#include <iostream>
using namespace std;

// Base Class
class Student {
protected:
    string name;
    int marks;

public:

    // Input Function
    void getData() {
        cout << "Enter Student Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;
    }

    // Display Function
    void display() {
        cout << "\nStudent Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }

    // Pure Virtual Function
    virtual void result() = 0;
};

// Derived Class
class GradeSystem : public Student {

public:

    // AI-Based Rule Logic
    void result() {

        display();

        if (marks >= 75)
            cout << "AI Prediction: Excellent Student" << endl;

        else if (marks >= 50)
            cout << "AI Prediction: Average Student" << endl;

        else
            cout << "AI Prediction: Needs Improvement" << endl;
    }
};

int main() {

    GradeSystem s;

    s.getData();
    s.result();

    return 0;
}