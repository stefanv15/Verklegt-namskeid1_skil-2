#ifndef PERSON_H
#define PERSON_H
//#include <iostream>
#include <string>
//#include <vector>
using namespace std;

class Person
{
public:
    Person();
    Person(string n, string g, int dob, int dod);
    Person(int i, string n, string g, int dob, int dod);
    int getId();
    string getName();
    string getGender();
    int getDayOfBirth();
    int getDayOfDeath();

private:
    int id;
    string name;
    string gender;
    int dayOfBirth;
    int dayOfDeath;
};

#endif // PERSON_H
