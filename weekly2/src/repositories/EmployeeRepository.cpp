#include "EmployeeRepository.h"
#include "EmployeeService.h"

void EmployeeRepository::addRecord(EmployeeSalaryRecord& record) {
    ofstream fout;
    fout.open("data/records.txt", ios::app);
    fout << record << endl;
    fout.close();
}
