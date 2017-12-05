#ifndef employeeservice_h
#define employeeservice_h

#include <vector>
#include "EmployeeSalaryRecord.h"

class EmployeeService {
    public:
      void addRecord(EmployeeSalaryRecord& record);
      void listAllRecords();
      void listRecordsBySecurityNumber(string ssn);

    private:
        vector<string> _records;

};

#endif
