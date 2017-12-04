#include "EmployeeService.h"
#include <fstream>
#include <iostream>

void EmployeeService::addRecord(EmployeeSalaryRecord& record) {
  ofstream fout;
  fout.open("data/records.txt");
  fout << record.toString() << endl;
  fout.close();
}
