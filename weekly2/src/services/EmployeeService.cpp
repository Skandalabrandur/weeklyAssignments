#include "EmployeeService.h"
#include <fstream>
#include <iostream>

void EmployeeService::addRecord(EmployeeSalaryRecord& record) {
  ofstream fout;
  fout.open("data/records.txt", ios::app);
  fout << record << endl;
  fout.close();
}

void EmployeeService::listAllRecords() {
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
    //---- does not work -----
    for(unsigned int i = 0; i < _records.size(); i++){
        if(_records.at(i) == ssn){
            cout << _records.at(i) << " ";
        }
    }
}
