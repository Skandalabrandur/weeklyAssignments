#include "EmployeeService.h"
#include <iostream>

void EmployeeService::addRecord(EmployeeSalaryRecord& record){
    if(isValidName(record) && isValidSSN(record) && isValidSalary(record) && isValidMonth(record) && isValidYear(record)){
       _employeeRepo.addRecord(record);
    }
}

void EmployeeService::deleteOldRecordBeforeAdding(EmployeeSalaryRecord& record) {
  vector<string> records = _employeeRepo.readLinesToVector();
  stringstream ss;
  string name = record.getName();

  int year = record.getYear();
  ss << year;
  string sYear = ss.str();

  ss.str("");
  ss.clear();

  int month = record.getMonth();
  ss << month;
  string sMonth = ss.str();


  for(unsigned int i = 0; i < records.size(); i++) {
    vector<string> oldRecord = split(records.at(i));
    if(name == oldRecord.at(0) && sMonth == oldRecord.at(3) && sYear == oldRecord.at(4)) {
      records.erase(records.begin() + i);
      break;
    }
  }

  _employeeRepo.overwriteRecordWithVector(records);
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
  int highestSalary = 0;
  string highestSalaryEmployee = "";
  vector<string> records = _employeeRepo.readLinesToVector();
  vector<string> names;       //keep names in vector for iteration purposes
                              //this is because map::at() is C++11
  //maps allow things like
  //    salaries["jonas"] = 0;
  //    salaries["jonas"] += 5000;
  //    cout << salaries["jonas"] << endl;
  map<string, int> salaries;  //each name will have a salary record

  //if salary is set to an arbitrarily chosen number it means we
  //have alread encountered the name and will not add it to
  //the string vector
  for(unsigned int i = 0; i < records.size(); i++) {
    vector<string> record = split(records.at(i));
    if(salaries[record.at(0)] != 1337) {
        names.push_back(record.at(0));
        salaries[record.at(0)] = 1337;
    }
  }

  //reset. The reason we don't make a check for 0 initially is
  //because of NULL concerns
  for(unsigned int i = 0; i < salaries.size(); i++) {
    salaries[names.at(i)] = 0;
  }

  //now let's accumulate salaries for the employees;
  for(unsigned int i = 0; i < records.size(); i++) {
    vector<string> record = split(records.at(i));
    if(record.at(4) == year) {
      string salaryRecord = record.at(2);
      istringstream iss(salaryRecord);
      int salary;
      iss >> salary;

      salaries[record.at(0)] += salary;
    }
  }


  for(unsigned int i = 0; i < names.size(); i++) {
    if(salaries[names.at(i)] > highestSalary) {
      highestSalaryEmployee = names.at(i);
      highestSalary = salaries[names.at(i)];
    }
  }
  cout << endl << endl;
  cout << highestSalaryEmployee << " has the highest salary at: " << highestSalary << endl;

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
    if(record.getSalary() < 0 || record.getSalary() > 2147483647){
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
    //we trigger a deletion of the old record before adding the new one
    if(isSameMonth(record) && isSameYear(record) && isSameSSN(record)){
        deleteOldRecordBeforeAdding(record);
        cout << "Updating duplicate record..." << endl;
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
