#include "EmployeeSalaryRecord.h"
#include <string>
#include <iostream>
using namespace std;

EmployeeSalaryRecord::EmployeeSalaryRecord(string name, long long socialSecurityNumber, int salary, int month, int year) {
      _name = name;
      _socialSecurityNumber = socialSecurityNumber;
      _salary = salary;
      _month = month;
      _year = year;
}

string EmployeeSalaryRecord::toString() {

}
