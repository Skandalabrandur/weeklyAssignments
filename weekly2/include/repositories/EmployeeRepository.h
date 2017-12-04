#ifndef employeerepo_h
#define employeerepo_h

#include "EmployeeSalaryRecord.h"

class EmployeeRepository {

public:
    void addRecord(EmployeeSalaryRecord& record);
    bool isValidRecord(EmployeeSalaryRecord& record);

private:

};

#endif
