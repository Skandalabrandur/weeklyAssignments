#include <iostream>
#include <fstream>
#include "Superhero.cpp"

using namespace std;

int main() {

    char choice = 'i'; //for invalid

    while(choice != 'a' && choice != 'l') {
        cout << "Would you like to (l)ist superheroes or (a)dd your own? (l/a): ";
        cin >> choice;
    }

    if(choice == 'a') {
        Superhero hero;
        cin >> hero;

        ofstream fout;

        fout.open("superheroes.txt", ios::app);

        if(fout.is_open()) {
            fout << hero;
            fout.close();
        } else {
            cout << "Failed to open file!" << endl;
        }
    }

    if(choice == 'l') {
        ifstream fin;
        
        fin.open("superheroes.txt");

        if(fin.is_open()) {
            cout << "Listing heroes:" << endl << endl;
            int counter = 0;
            while(!fin.eof()) {
                counter++;
                string str;
                getline(fin, str);

                cout << str << endl;

                if(counter % 3 == 0) {
                    cout << endl;
                }
            }
        } else {
            cout << "Failed to open file!" << endl;
        }
       
    }
    return 0;
}
