#ifndef EMPLOYEESALARYRECORD_H
#define EMPLOYEESALARYRECORD_H

#include <string>
using namespace std;

class EmployeeSalaryRecord
{
    private:
        string name;
        int socialSecurityNumber;
        int salary;
        int month;
        int year;

    public:
        EmployeeSalaryRecord();
};

#endif // EMPLOYEESALARYRECORD_H
