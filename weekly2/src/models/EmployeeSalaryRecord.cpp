#include "EmployeeSalaryRecord.h"
#include <string>
#include <iostream>
using namespace std;

EmployeeSalaryRecord::EmployeeSalaryRecord(string name, string socialSecurityNumber, int salary, int month, int year) {
      _name = name;
      _socialSecurityNumber = socialSecurityNumber;
      _salary = salary;
      _month = month;
      _year = year;
}

ostream& operator << (ostream& out, const EmployeeSalaryRecord& employeeSR){
    out << employeeSR._name << ", " << employeeSR._socialSecurityNumber << ", " << employeeSR._salary << ", "
        << employeeSR._month << ", " << employeeSR._year;

        return out;
}

istream& operator >> (istream& in, EmployeeSalaryRecord& employeeSR){
    //in >> employeeSR._name >> ", " >> employeeSR._socialSecurityNumber >> ", " >> employeeSR._salary >> ", "
    //    >> employeeSR._month >> ", " >> employeeSR._year;

    return in;
}
