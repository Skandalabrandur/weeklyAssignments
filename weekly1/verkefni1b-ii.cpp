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
        int howMany;
        cout << "How many heroes are you going to add? Answer: ";
        cin >> howMany;

        Superhero *heroArray = new Superhero[howMany];

        for(int i = 0; i < howMany; i++) {
            cin >> heroArray[i];
        }


        ofstream fout;

        fout.open("superheroes.dat", ios::app|ios::binary);

        if(fout.is_open()) {
            fout.write((char*) heroArray, sizeof(Superhero) * howMany);
            fout.close();
        } else {
            cout << "Failed to open file!" << endl;
        }
    }

    if(choice == 'l') {
        ifstream fin;
        
        fin.open("superheroes.dat", ios::binary);

        if(fin.is_open()) {
            cout << "Listing heroes:" << endl << endl;

            fin.seekg(0, fin.end);
            int heroCount = fin.tellg() / sizeof(Superhero);
            fin.seekg(0, fin.beg);

            Superhero *heroes = new Superhero[heroCount];
            
            fin.read((char*)(heroes), sizeof(Superhero) * heroCount);

            fin.close();

            for(int i = 0; i < heroCount; i ++) {
                cout << heroes[i] << endl;
            }

            
           
        } else {
            cout << "Failed to open file!" << endl;
        }
       
    }
    return 0;
}
