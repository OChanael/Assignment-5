#include <iostream>
#ifndef included
#define included

using namespace std;

class Person
{
    public:
        int ID;
        string name;
        string level;

        Person();
        ~Person();

        int getID();
        void setID(int value);

        string getName();
        string getLevel();
};
#endif
