#include "EmployeeService.h"
#include <iostream>

void EmployeeService::addRecord(EmployeeSalaryRecord& record){
    if(isValidName(record) && isValidSSN(record) && isValidSalary(record) && isValidMonth(record) && isValidYear(record)){
       _employeeRepo.addRecord(record);
    }
}

void EmployeeService::listAllRecords(){
    /*string str;

    ifstream fin;
    fin.open("data/records.txt");

    if(fin.is_open()){
        while(fin >> str){
            cout << str << " ";
        }
        cout << endl;
        fin.close();
    }*/

    _records = _employeeRepo.readRedcordToVector();

    for(unsigned int i = 0; i < _records.size() - 1; i++){
        cout << _records.at(i) << ", ";
    }
}

void EmployeeService::listRecordsBySecurityNumber(string ssn){
    _records = _employeeRepo.readRedcordToVector();

    cout << "Records: " << endl;

    for(unsigned int i = 1; i < _records.size(); i += 5){
        if(_records.at(i) == ssn){
            for(unsigned int k = i - 1; k < i + 4; k++){
                //to not print a comma at the end
                if(!(k == i + 3)){
                    cout << _records.at(k) << ", ";
                }
                else{
                    cout << _records.at(k);
                }
            }
        }
    }
}

void EmployeeService::getSalaryForSSNandYear(string ssn, int year){
    _records = _employeeRepo.readRedcordToVector();

    cout << "Salary: " << endl;

}




//functions for validation of a record
bool EmployeeService::isValidName(EmployeeSalaryRecord& record) {
    //TO DO: validate name
    string name = record.getName();
    for(unsigned int i = 0; i < name.length(); i++){
        if(!((name[i] <= 'z' && name[i] >= 'a') || (name[i] <= 'Z' && name[i] >= 'A') || (name[i] == ' '))){
            throw InvalidNameException();
        }
    }
    return true;
}

bool EmployeeService::isValidSSN(EmployeeSalaryRecord& record){
    //validate social security number
    string SSN = record.getSSN();
    if(SSN.length() != 10){
        throw InvalidSSNException();
    }
    return true;
}

bool EmployeeService::isValidSalary(EmployeeSalaryRecord& record){
    //validate salary
    if(record.getSalary() < 0){
        throw InvalidSalaryException();
    }
    return true;
}

bool EmployeeService::isValidMonth(EmployeeSalaryRecord& record){
    //validate month
    if(record.getMonth() < 1 || record.getMonth() > 12){
        throw InvalidMonthException();
    }
    //TO DO: employee may not have multiple records for the same month, the new records should be overwritten
    cout << "Records: " << endl;

    //if these functions return true then record for that month already exists
    if(isSameMonth(record) && isSameYear(record) && isSameSSN(record)){
        throw InvalidMonthException();
    }
    return true;
}

bool EmployeeService::isSameMonth(EmployeeSalaryRecord& record){
    _records = _employeeRepo.readRedcordToVector();

    //change int month to string
    stringstream ss;
    int month = record.getMonth();
    ss << month;
    string sMonth = ss.str();

    //check if month is the same
    for(unsigned int i = 3; i < _records.size(); i += 5){
        if(_records.at(i) == sMonth){
            return true;
        }
    }
    return false;
}

bool EmployeeService::isSameYear(EmployeeSalaryRecord& record){
    _records = _employeeRepo.readRedcordToVector();

    //change int year to string
    stringstream ss;
    int year = record.getYear();
    ss << year;
    string sYear = ss.str();

    //check if year is the same
    for(unsigned int i = 4; i < _records.size(); i += 5){
        if(_records.at(i) == sYear){
            return true;
        }
    }
    return false;
}

bool EmployeeService::isSameSSN(EmployeeSalaryRecord& record){
    _records = _employeeRepo.readRedcordToVector();

    //get social security number
    string ssn = record.getSSN();

    //check if security number is the same
    for(unsigned int i = 1; i < _records.size(); i += 5){
        if(_records.at(i) == ssn){
            return true;
        }
    }
    return false;
}

bool EmployeeService::isValidYear(EmployeeSalaryRecord& record){
    //validate year
    if(record.getYear() < 1900 || record.getYear() > 2017){
        throw InvalidYearException();
    }
    return true;
}
