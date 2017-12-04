#include "MainUI.h"
#include "EmployeeService.h"

#include <iostream>
using namespace std;

MainUI::MainUI()
{

}

void MainUI::mainMenu(){

    char choice;
    do{
        cout << "Choose and action" << endl << endl;
        cout << "a - add salary record" << endl;
        cout << "b - get all salary records" << endl;
        cout << "c - get total salary for a given year" << endl;
        cout << "d - get the name of the employee with highest salary" << endl;
        cout << "q - quit" << endl;
        cout << endl;

        cin >> choice;
    }while(choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'q');

    if(choice == 'a'){

        //make new record
        string name;
        cin >> name;

        long long socialSecurityNumber;
        cin >> socialSecurityNumber;

        int salary;
        cin >> salary;

        int month;
        cin >> month;

        int year;
        cin >> year;

        EmployeeSalaryRecord employeeSRecrod(name, socialSecurityNumber, salary, month, year);

        EmployeeService employeeService;
        employeeService.addRecord(employeeSRecrod);
    }
    else if(choice == 'b'){

    }
    else if(choice == 'c'){

    }
    else if(choice == 'd'){

    }
}

/*
void MainUI::validateUserInput(char input){


}
*/

/*
void MainUI::createRecord(){

}
*/
