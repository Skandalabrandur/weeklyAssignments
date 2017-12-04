#ifndef MAINUI_H
#define MAINUI_H

#include "EmployeeService.h"

#include <iostream>
using namespace std;

class MainUI
{
    private:


    public:
        MainUI();
        void mainMenu();
        void validateUserInput(char input);
        void createReacord();
};

#endif // MAINUI_H
