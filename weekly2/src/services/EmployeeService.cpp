#include "EmployeeService.h"
#include <fstream>
#include <iostream>

void EmployeeService::addRecord(EmployeeSalaryRecord& record) {
  ofstream fout;
  fout.open("data/records.txt", ios::app);
  fout << record.toString() << endl;
  fout.close();
}

void EmployeeService::listRecords() {
}
