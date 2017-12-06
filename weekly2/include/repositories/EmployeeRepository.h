#ifndef employeerepo_h
#define employeerepo_h

#include <fstream>
#include <vector>
#include "EmployeeSalaryRecord.h"

class EmployeeRepository {

public:
    void addRecord(EmployeeSalaryRecord& record);
    vector<string> readRedcordToVector();

private:

};

#endif
