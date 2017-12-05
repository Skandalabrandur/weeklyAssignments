#ifndef EMPLOYEESALARYRECORD_H
#define EMPLOYEESALARYRECORD_H

#include <string>
using namespace std;

class EmployeeSalaryRecord
{
    private:
        string _name;
        long long _socialSecurityNumber;
        int _salary;
        int _month;
        int _year;

    public:
        EmployeeSalaryRecord(string name, long long socialSecurityNumber, int salary, int month, int year);
        string toString();
        EmployeeSalaryRecord();
};

#endif // EMPLOYEESALARYRECORD_H
