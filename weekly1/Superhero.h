#include <iostream>

using namespace std;

class Superhero {
    public:
        Superhero();    //constructor
        void fixString();
        void setVerbose(bool set);

        friend ostream& operator << (ostream& out, Superhero &sh);
        friend istream& operator >> (istream& in, Superhero &sh);

    private:
        char _name[38];
        int _age;
        char _superpower;
        bool vbose;
};
