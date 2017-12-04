#include <iostream>
#include "EmployeeSalaryRecord.h"
#include "EmployeeService.h"

#include "MainUI.h"

using namespace std;

int main()
{
  EmployeeSalaryRecord record("Dusi", 1234567890,
1200, 5, 1992);
  EmployeeService service;
  service.addRecord(record);

    MainUI mainui;
    mainui.mainMenu();

    return 0;
}
