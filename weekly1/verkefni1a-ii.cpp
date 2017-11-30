#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
        ofstream fout;
        fout.open("writeFile.txt");


        if(fout.is_open()) {
            string str = "";

            bool legit = true;
            while(legit) {
                getline(cin, str);

                if(str[0] == '\\') {
                    legit = false;
                } else {
                    fout << str << endl;
                }
            }


            fout.close();
        } else {
            cout << "Failed to open file!" << endl;
        }

        return 0;
}
