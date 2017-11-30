#include "Superhero.h"

Superhero::Superhero() {
    _name[0] = '\0';
    _age = 0;
    _superpower = 'n';
    vbose = true;
}

void Superhero::fixString() {
    _name[37] = '\0';
}

void Superhero::setVerbose(bool set) {
    vbose = set;
}


ostream& operator << (ostream& out, Superhero &sh) {
    if(sh.vbose) {
        out << "Name:  ";
    }

    out << sh._name << endl;
    
    if(sh.vbose) {
        out << "Age:   ";
    }
    out << sh._age << endl;
    
    if(sh.vbose) {
        out << "Power: ";
    }
    
    if(sh.vbose) {
    switch(sh._superpower) {
            case 'f':
                out << "Flying";
                break;

            case 'g':
                out << "Giant";
                break;

            case 'h':
                out << "Hacker";
                break;
            case 'n':
                out << "None";
                break;
            default:
                out << "Weakling";
        }
    } else {
        out << sh._superpower;
    }
    out << endl;

    return out;
}

istream& operator >> (istream& in, Superhero &sh) {
    if(sh.vbose) {
        cout << "Enter superhero name:  ";
    }
    
    in >> sh._name;
    sh.fixString();

    
    if(sh.vbose) {
        cout << "Enter superhero age:   ";
    }
    in >> sh._age;

    if(sh.vbose) {
        cout << "Enter superhero power: ";
    } 
    in >> sh._superpower;
    
    return in;
}
