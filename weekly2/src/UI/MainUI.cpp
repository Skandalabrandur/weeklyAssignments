#include "MainUI.h"

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
}

/*
void MainUI::validateUserInput(char input){

}
*/
