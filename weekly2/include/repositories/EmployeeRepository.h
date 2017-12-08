#ifndef employeerepo_h
#define employeerepo_h

#include <fstream>
#include <vector>
#include "EmployeeSalaryRecord.h"

class EmployeeRepository {

public:
    void addRecord(EmployeeSalaryRecord& record);
    void overwriteRecordWithVector(vector<string> newFile);
    vector<string> readRedcordToVector();
    vector<string> readLinesToVector();

private:

};

#endif
