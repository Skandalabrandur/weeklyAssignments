#ifndef employeeservice_h
#define employeeservice_h

#include <vector>
#include <map>
#include <sstream>
#include "EmployeeSalaryRecord.h"
#include "EmployeeRepository.h"

#include "InvalidSSNException.h"
#include "InvalidSalaryException.h"
#include "InvalidMonthException.h"
#include "InvalidYearException.h"
#include "InvalidNameException.h"

using namespace std;

class EmployeeService {

    public:
      void addRecord(EmployeeSalaryRecord& record);
      void deleteOldRecordBeforeAdding(EmployeeSalaryRecord& record);
      void listAllRecords();
      void listRecordsBySecurityNumber(string ssn);
      void getSalaryForSSNandYear(string ssn, string year);
      void getHighestSalaryForYear(string year);
      vector<string> split(string str);

      bool isValidName(EmployeeSalaryRecord& record);
      bool isValidSSN(EmployeeSalaryRecord& record);
      bool isValidSalary(EmployeeSalaryRecord& record);
      bool isValidMonth(EmployeeSalaryRecord& record);
      bool isValidYear(EmployeeSalaryRecord& record);

      bool isSameMonth(EmployeeSalaryRecord& record);
      bool isSameYear(EmployeeSalaryRecord& record);
      bool isSameSSN(EmployeeSalaryRecord& record);

    private:
        EmployeeRepository _employeeRepo;
        vector<string> _records;
};

#endif
