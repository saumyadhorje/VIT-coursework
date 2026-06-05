#include <iostream>
using namespace std;

class Employee
{
protected:
    string emp_name;
    int emp_id;
    string address;
    string mail_id;
    long long mobile_no;

    float DA, HRA, PF, staff_club;
    float gross_salary, net_salary;

public:
    void getData()
    {
        cout << "Enter Employee Name: ";
        cin >> emp_name;

        cout << "Enter Employee ID: ";
        cin >> emp_id;

        cout << "Enter Address: ";
        cin >> address;

        cout << "Enter Mail ID: ";
        cin >> mail_id;

        cout << "Enter Mobile Number: ";
        cin >> mobile_no;
    }

    void calculateSalary(float BP)
    {
        DA = 0.52 * BP;
        HRA = 0.27 * BP;
        PF = 0.12 * BP;
        staff_club = 0.001 * BP;

        gross_salary = BP + DA + HRA;
        net_salary = gross_salary - PF - staff_club;
    }

    void displayPayslip()
    {
        cout << "\n------ PAY SLIP ------\n";

        cout << "Employee Name : " << emp_name << endl;
        cout << "Employee ID   : " << emp_id << endl;
        cout << "Address       : " << address << endl;
        cout << "Mail ID       : " << mail_id << endl;
        cout << "Mobile Number : " << mobile_no << endl;

        cout << "\nSalary Details\n";

        cout << "DA            : " << DA << endl;
        cout << "HRA           : " << HRA << endl;
        cout << "PF            : " << PF << endl;
        cout << "Staff Club    : " << staff_club << endl;

        cout << "Gross Salary  : " << gross_salary << endl;
        cout << "Net Salary    : " << net_salary << endl;
    }
};

class Programmer : public Employee
{
    float BP;

public:
    void getProgrammerData()
    {
        getData();

        cout << "Enter Basic Pay: ";
        cin >> BP;

        calculateSalary(BP);
    }
};

class TeamLead : public Employee
{
    float BP;

public:
    void getTeamLeadData()
    {
        getData();

        cout << "Enter Basic Pay: ";
        cin >> BP;

        calculateSalary(BP);
    }
};

class AssistantProjectManager : public Employee
{
    float BP;

public:
    void getAPMData()
    {
        getData();

        cout << "Enter Basic Pay: ";
        cin >> BP;

        calculateSalary(BP);
    }
};

class ProjectManager : public Employee
{
    float BP;

public:
    void getPMData()
    {
        getData();

        cout << "Enter Basic Pay: ";
        cin >> BP;

        calculateSalary(BP);
    }
};

int main()
{
    Programmer p;
    TeamLead t;
    AssistantProjectManager a;
    ProjectManager pm;

    cout << "\nEnter Programmer Details\n";
    p.getProgrammerData();

    cout << "\nEnter Team Lead Details\n";
    t.getTeamLeadData();

    cout << "\nEnter Assistant Project Manager Details\n";
    a.getAPMData();

    cout << "\nEnter Project Manager Details\n";
    pm.getPMData();

    p.displayPayslip();
    t.displayPayslip();
    a.displayPayslip();
    pm.displayPayslip();

    return 0;
}