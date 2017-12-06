#include "EmployeeRepository.h"
#include "EmployeeService.h"

void EmployeeRepository::addRecord(EmployeeSalaryRecord& record) {
    ofstream fout;
    fout.open("data/records.txt", ios::app);
    fout << record << endl;
    fout.close();
}


vector<string> EmployeeRepository::readRedcordToVector(){
    vector<string> vrecords;
    string str;
    ifstream fin;
    fin.open("data/records.txt");

    if(fin.is_open()){
        while(getline(fin, str, ',')){
            //put the information from the file into a vector
            vrecords.push_back(str);
        }
        fin.close();
    }
    return vrecords;
}
