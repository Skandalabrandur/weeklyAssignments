#include "MainUI.h"
#include "stdlib.h"

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
        try{
            _employeeService.addRecord(employeeSRecrod);
        }
        //exceptions
        catch(InvalidNameException){
            cout << "Invalid name." << endl << endl;;
        }
        catch(InvalidSSNException){
            cout << "Invalid social security number." << endl << endl;;
        }
        catch(InvalidSalaryException){
            cout << "Invalid salary." << endl << endl;;
        }
        catch(InvalidMonthException){
            cout << "Invalid month." << endl << endl;;
        }
        catch(InvalidYearException){
            cout << "Invalid year." << endl << endl;;
        }

        mainMenu();
    }
    else if(input == 'b'){
        //get all salary records for a given social security number
        cout << "Social security number: ";
        string ssn;
        cin >> ssn;
        cout << endl;
        //all records for ssn
        cout << "Records: " << endl;
        _employeeService.listRecordsBySecurityNumber(ssn);
        cout << endl << endl;
        mainMenu();
    }
    else if(input == 'c'){
        //get total salary for a given year and social security number
        //get input
        cout << "Social security number: ";
        string ssn;
        cin >> ssn;
        cout << "Year: ";
        string year;
        cin >> year;
        cout << endl;

        cout << "Total salary: " << endl;
        _employeeService.getSalaryForSSNandYear(ssn, year);
        cout << endl;
        mainMenu();
    }
    else if(input == 'd'){
        //get the name of the employee with highest salary for a given year
        cout << "Year: ";
        string year;
        cin >> year;
        cout << endl;
        _employeeService.getHighestSalaryForYear(year);
        mainMenu();
    }
    else if(input == 'q'){
        exit(0);
    }
}

EmployeeSalaryRecord MainUI::createRecord(){
    string name;
    cout << "Name: ";
    cin.ignore();   //if a character is left in the stream
    getline(cin, name);

    string socialSecurityNumber;
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
