#include "EmployeeRepository.h"
#include "EmployeeService.h"

void EmployeeRepository::addRecord(EmployeeSalaryRecord& record) {
  EmployeeService service;
  if isValidRecord(record) {
    service.addRecord(record);
  }
}

bool EmployeeRepository::isValidRecord() {
  return true;
}
