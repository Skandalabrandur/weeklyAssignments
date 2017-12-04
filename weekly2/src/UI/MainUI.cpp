#include "MainUI.h"

MainUI::MainUI()
{

}

void MainUI::mainMenu(){

    char choice;
    do{
        cout << "Choose an action" << endl << endl;
        cout << "a - add salary record" << endl;
        cout << "b - get all salary records for a given social security number" << endl;
        cout << "c - get total salary for a given year and social security number" << endl;
        cout << "d - get the name of the employee with highest salary for a given year" << endl;
        cout << "q - quit" << endl;
        cout << endl;

        cin >> choice;
    }while(choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'q');

    validateUserInput(choice);
}


void MainUI::validateUserInput(char input){

    if(input == 'a'){
        //make new record
        EmployeeSalaryRecord employeeSRecrod(createRecord());
        //save the record
        _employeeService.addRecord(employeeSRecrod);
        mainMenu();
    }
    else if(input == 'b'){
        //get all salary records for a given social security number
        _employeeService.listRecords();
    }
    else if(input == 'c'){
        //get total salary for a given year and social security number
        //_employeeService function call
    }
    else if(input == 'd'){
        //get the name of the employee with highest salary for a given year
        //_employeeService function call
    }
}



EmployeeSalaryRecord MainUI::createRecord(){
    cout << "Name: ";
    string name;
    cin.ignore();   //if a character is left in the stream
    getline(cin, name);

    long long socialSecurityNumber;
    cout << "Social security number: ";
    cin >> socialSecurityNumber;

    int salary;
    cout << "Salary: ";
    cin >> salary;

    int month;
    cout << "Month: ";
    cin >> month;

    int year;
    cout << "Year: ";
    cin >> year;
    cout << endl;

    EmployeeSalaryRecord record(name, socialSecurityNumber, salary, month, year);

    return record;
}
