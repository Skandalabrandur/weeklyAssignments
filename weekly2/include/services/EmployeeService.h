#ifndef employeeservice_h
#define employeeservice_h
#include "EmployeeSalaryRecord.h"

class EmployeeService {
public:
  void addRecord(EmployeeSalaryRecord& record);
  void listRecords();
private:
};

#endif
