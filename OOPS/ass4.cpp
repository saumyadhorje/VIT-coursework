//rite a C++ program to create a Student class with the following: 
//Private data members: Roll Number, Name, Marks of five subjects, Percentage, 
//Result Division 
//Public members: Parameterized constructor, destructor, functions to calculate 
//percentage, determine grade/division, and display student details 
#include <iostream>
using namespace std;

class Student
{
private:
    int roll_no;
    string name;
    int marks1, marks2, marks3, marks4, marks5;
    float percentage;
    string division;

public:

    // Parameterized Constructor
    Student(int r, string n, int m1, int m2, int m3, int m4, int m5)
    {
        roll_no = r;
        name = n;
        marks1 = m1;
        marks2 = m2;
        marks3 = m3;
        marks4 = m4;
        marks5 = m5;
    }

    // Function to calculate percentage
    void calc_percentage()
    {
        percentage = (marks1 + marks2 + marks3 + marks4 + marks5) / 5.0;
    }

    // Function to determine division
    void calc_division()
    {
        if (percentage >= 75)
        {
            division = "Distinction";
        }
        else if (percentage >= 60)
        {
            division = "First Class";
        }
        else if (percentage >= 50)
        {
            division = "Second Class";
        }
        else if (percentage >= 35)
        {
            division = "Pass";
        }
        else
        {
            division = "Fail";
        }
    }

    // Function to display details
    void display()
    {
        cout << "\nStudent Details" << endl;
        cout << "Roll No: " << roll_no << endl;
        cout << "Name: " << name << endl;
        cout << "Percentage: " << percentage << "%" << endl;
        cout << "Division: " << division << endl;
    }

    // Friend function declaration
    friend void comparePercentage(Student s1, Student s2);

    // Destructor
    ~Student()
    {
        cout << "Student record deleted." << endl;
    }
};

// Friend Function Definition
void comparePercentage(Student s1, Student s2)
{
    if (s1.percentage > s2.percentage)
    {
        cout << "\n" << s1.name << " has higher percentage." << endl;
        cout << "Percentage = " << s1.percentage << "%" << endl;
    }
    else if (s2.percentage > s1.percentage)
    {
        cout << "\n" << s2.name << " has higher percentage." << endl;
        cout << "Percentage = " << s2.percentage << "%" << endl;
    }
    else
    {
        cout << "\nBoth students have same percentage." << endl;
    }
}

int main()
{
    int roll1, roll2;
    string name1, name2;
    int m1, m2, m3, m4, m5;
    int n1, n2, n3, n4, n5;

    // Input for Student 1
    cout << "Enter details of Student 1" << endl;

    cout << "Enter Roll Number: ";
    cin >> roll1;

    cout << "Enter Name: ";
    cin >> name1;

    cout << "Enter marks of 5 subjects: ";
    cin >> m1 >> m2 >> m3 >> m4 >> m5;

    // Input for Student 2
    cout << "\nEnter details of Student 2" << endl;

    cout << "Enter Roll Number: ";
    cin >> roll2;

    cout << "Enter Name: ";
    cin >> name2;

    cout << "Enter marks of 5 subjects: ";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;

    // Object Creation
    Student s1(roll1, name1, m1, m2, m3, m4, m5);
    Student s2(roll2, name2, n1, n2, n3, n4, n5);

    // Calculate percentage and division
    s1.calc_percentage();
    s1.calc_division();

    s2.calc_percentage();
    s2.calc_division();

    // Display details
    s1.display();
    s2.display();

    // Compare percentages
    comparePercentage(s1, s2);

    return 0;
}