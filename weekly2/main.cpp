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

<<<<<<< HEAD
    MainUI mainui;
    mainui.mainMenu();

    return 0;
=======
  return 0;
>>>>>>> 8d67c3822463636635c55cd8ecf24c0155529304
}
