#ifndef MAINUI_H
#define MAINUI_H

#include "EmployeeService.h"

#include <iostream>
using namespace std;

class MainUI
{
    private:
        EmployeeService _employeeService;

    public:
        MainUI();
        void mainMenu();
        void validateUserInput(char input);
        EmployeeSalaryRecord createRecord();
};

#endif // MAINUI_H
