#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person
{
public:
    Person();
    Person(string n, string g, int dob, int dod);           //Smiður fyrir Person til að upphafsstilla 4 prívat breytur.
    Person(int i, string n, string g, int dob, int dod);    //Smiður fyrir Person til að upphafsstilla 5 prívat breytur.
    int getId();                                            //Sækir ID.
    string getName();                                       //Sækir nafn viðkomandi.
    string getGender();                                     //Sækir kyn.
    int getDayOfBirth();                                    //Sækir fæðingarárið.
    int getDayOfDeath();                                    //Sækir dánar árið.

private:                                                    //Private breytur fyrir upplýsingar yfir person.
    int id;
    string name;
    string gender;
    int dayOfBirth;
    int dayOfDeath;
};

#endif // PERSON_H
