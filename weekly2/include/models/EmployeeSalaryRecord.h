#ifndef EMPLOYEESALARYRECORD_H
#define EMPLOYEESALARYRECORD_H

#include <string>
using namespace std;

class EmployeeSalaryRecord
{
    private:
<<<<<<< HEAD
        string name;
        long long socialSecurityNumber;
        int salary;
        int month;
        int year;
=======
        string _name;
        long long _socialSecurityNumber;
        int _salary;
        int _month;
        int _year;
>>>>>>> 8d67c3822463636635c55cd8ecf24c0155529304

    public:
        EmployeeSalaryRecord(string name,
          long long socialSecurityNumber,
          int salary,
          int month,
          int year);
        string toString();
        EmployeeSalaryRecord();
};

#endif // EMPLOYEESALARYRECORD_H
