#include <iostream>
using namespace std;

class student
{
private:
    int roll_no;
    string name;
    int marks1, marks2, marks3, marks4, marks5;
    float percentage;

public:

    student(int r, string n, int m1, int m2, int m3, int m4, int m5)
    {
        roll_no = r;
        name = n;
        marks1 = m1;
        marks2 = m2;
        marks3 = m3;
        marks4 = m4;
        marks5 = m5;
    }

    void calc_percentage()
    {
        percentage = (marks1 + marks2 + marks3 + marks4 + marks5) / 5.0;
    }

    void calc_grade()
    {
        if (percentage > 75)
        {
            cout << "Distinction" << endl;
        }
        else if (percentage > 45)
        {
            cout << "Pass" << endl;
        }
        else
        {
            cout << "Fail" << endl;
        }
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << roll_no << endl;
        cout << "Percentage: " << percentage << endl;
    }

    ~student()
    {
        cout << "student records cleared" << endl;
    }
};

int main()
{
    int roll, m1, m2, m3, m4, m5;
    string name;

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter roll no: ";
    cin >> roll;

    cout << "Enter marks of 5 subjects: ";
    cin >> m1 >> m2 >> m3 >> m4 >> m5;

    student s(roll, name, m1, m2, m3, m4, m5);

    s.calc_percentage();
    s.calc_grade();
    s.display();

    return 0;
}