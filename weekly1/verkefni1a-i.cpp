#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream fin;
    fin.open("testFile.txt");

    if(fin.is_open()) {

        char input;
        string str;
        do {
            input = 'u';
            for(int i = 0; i < 10; i++) {
                getline(fin, str);
                if(fin.eof()) {
                    break;
                }
                cout << str << endl;
            }

            if(fin.eof()) {
                break;
            }

            while(input != 'y' && input != 'Y' && input != 'n' && input != 'N') {
                cout << endl << "Do you want the next 10 lines of the program? (y/n): ";
                cin >> input;
            }


        } while(!fin.eof() && input == 'y');
    } else {
        cout << "Failed to open file!" << endl;
    }
}
