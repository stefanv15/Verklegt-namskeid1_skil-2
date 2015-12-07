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
    int getId();            //Sækir ID.
    string getName();       //Sækir nafn viðkomandi.
    string getGender();     //Sækir kyn.
    int getDayOfBirth();    //Sækir fæðingarárið.
    int getDayOfDeath();    //Sækir dánar árið.

private:    //Private breytur fyrir upplýsingar yfir person.
    int id;
    string name;
    string gender;
    int dayOfBirth;
    int dayOfDeath;
};

#endif // PERSON_H
