#include "EmployeeService.h"
#include <fstream>
#include <iostream>

void EmployeeService::addRecord(EmployeeSalaryRecord& record){
    if(isValidSSN(record)){
       _employeeRepo.addRecord(record);
    }
}

void EmployeeService::listAllRecords(){
    string str;

    ifstream fin;
    fin.open("data/records.txt");

    if(fin.is_open()){
        while(fin >> str){
            cout << str << " ";
        }
        cout << endl;
        fin.close();
    }
}

void EmployeeService::listRecordsBySecurityNumber(string ssn){
    string str;
    ifstream fin;
    fin.open("data/records.txt");

    if(fin.is_open()){
        while(getline(fin, str, ',')){
            //put the information from the file into a vector
            _records.push_back(str);
        }
        fin.close();
    }

    cout << "Records: " << endl;
    //finding the lines with chosen number needs to be implemented
    //--------- find a way to only check the social security number --------
    for(unsigned int i = 0; i < _records.size(); i++){
        if(_records.at(i) == " " + ssn){
            for(unsigned int k = i - 1; k < i + 4; k++){
                //if sentence to not print a comma at the end
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

bool EmployeeService::isValidName(EmployeeSalaryRecord& record) {
    //TO DO: validate name

        //throw InvalidNameException();

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
    //TO DO: employee may not have multiple record for the same month, the new records should be overwritten
    if(record.getMonth() < 1 || record.getMonth() > 12){
        throw InvalidMonthException();
    }
    return true;
}

bool EmployeeService::isValidYear(EmployeeSalaryRecord& record){
    //validate year
    if(record.getYear() < 1900 || record.getYear() > 2017){
        throw InvalidYearException();
    }
    return true;
}
