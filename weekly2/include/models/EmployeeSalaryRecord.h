#ifndef EMPLOYEESALARYRECORD_H
#define EMPLOYEESALARYRECORD_H

#include <iostream>
#include <string>
using namespace std;

class EmployeeSalaryRecord
{
    private:
        string _name;
        string _socialSecurityNumber;
        int _salary;
        int _month;
        int _year;

    public:
        EmployeeSalaryRecord(string name, string socialSecurityNumber, int salary, int month, int year);
        EmployeeSalaryRecord();
        string getName();
        string getSSN();
        int getSalary();
        int getMonth();
        int getYear();
        friend ostream& operator << (ostream& out, const EmployeeSalaryRecord& employeeSR);
        friend istream& operator << (istream& in, EmployeeSalaryRecord& employeeSR);
};

#endif // EMPLOYEESALARYRECORD_H
