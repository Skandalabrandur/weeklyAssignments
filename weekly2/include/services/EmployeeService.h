#ifndef employeeservice_h
#define employeeservice_h

#include <vector>
#include "EmployeeSalaryRecord.h"
#include "EmployeeRepository.h"

class EmployeeService {
    public:
      void addRecord(EmployeeSalaryRecord& record);
      void listAllRecords();
      void listRecordsBySecurityNumber(string ssn);
      bool isValidRecord(EmployeeSalaryRecord& record);

    private:
        EmployeeRepository _employeeRepo;
        vector<string> _records;

};

#endif
