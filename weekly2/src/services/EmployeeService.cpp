#include "EmployeeService.h"
#include <iostream>

void EmployeeService::addRecord(EmployeeSalaryRecord& record){
    if(isValidName(record) && isValidSSN(record) && isValidSalary(record) && isValidMonth(record) && isValidYear(record)){
       _employeeRepo.addRecord(record);
    }
}

void EmployeeService::listAllRecords(){
    _records = _employeeRepo.readRedcordToVector();

    for(unsigned int i = 0; i < _records.size() - 1; i++){
        cout << _records.at(i) << ", ";
    }
}

void EmployeeService::listRecordsBySecurityNumber(string ssn){
    _records = _employeeRepo.readLinesToVector();

    for(unsigned int i = 0; i < _records.size(); i++){
        string line = _records.at(i);
        vector<string> words = split(line);
        for(unsigned int i = 0; i < words.size(); i++){
            //ssn is at index 1
            if(words.at(1) == ssn){
                cout << words.at(i) << " ";
                //end line between records
                if((i % 4 == 0) && i != 0){
                    cout << endl;
                }
            }
        }
    }

}

void EmployeeService::getSalaryForSSNandYear(string ssn, string year){
    _records = _employeeRepo.readLinesToVector();

    int totalSalary = 0;
    for(unsigned int i = 0; i < _records.size(); i++){
        string line = _records.at(i);
        vector<string> words = split(line);
        for(unsigned int i = 0; i < words.size(); i++){
            //ssn is at index 1 and year is at index 4
            if((words.at(1) == ssn) && words.at(4) == year){
                //salary is at index 2
                //string to int
                if(i == 2){
                    int salary = 0;
                    istringstream ss(words.at(2));
                    ss >> salary;
                    totalSalary += salary;
                }
            }
        }
    }
    cout << totalSalary << endl;

}

void EmployeeService::getHighestSalaryForYear(string year){
//only works correctly if social security number are ordered in the file
    vector<string> _records = _employeeRepo.readLinesToVector();
    string employeeHighestSalary = "";
    int salary = 0;
    int highestSalary = 0;

    string employeeSSN = "";

    for(unsigned int i = 0; i < _records.size(); i++){
        string line = _records.at(i);
        vector<string> words = split(line);

        //checks if last ssn is the same as the current
        bool same = false;
        if(employeeSSN == words.at(1)){
            same = true;
        }
        employeeSSN = words.at(1);

        if(words.at(4) == year){
            int tempsalary;
            istringstream ss(words.at(2));
            ss >> tempsalary;
            if(same){
                salary += tempsalary;
            }
            else{
                salary = tempsalary;
            }
            //for debugging
            cout << endl << "comparison: " << endl;
            cout << "salary: " << salary << endl;
            cout << "highest salary: " << highestSalary << endl;

            if(highestSalary < salary){
                highestSalary = salary;
                employeeHighestSalary = words.at(0);
                //for debugging
                cout << "highest salary name: " << words.at(0) << endl;
            }
        }

    }
    cout << "Employee with the highest salary " << year << " was " << employeeHighestSalary << endl;
}

vector<string> EmployeeService::split(string str){
    vector<string> words;               //initialize vector
    string builder;                     //initialize string for building words
      for(unsigned int i = 0; i < str.size(); i++) {
        if(str[i] != ',') {
          builder = builder + str[i];  //until delimiter, add character to builder

          //We do this if instead of being crazy and accessing the '\0' out of bounds
          if( i == (str.size() - 1) ) {
            words.push_back(builder);
          }
        } else {
          //we have
          words.push_back(builder);
          builder = "";
        }
  }
  return words;
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
