#include "person.h"

Person::Person()            //Sjálfgefni smiðurinn fyrir Person klasann.
{
    name = "";
    gender = "";
    dayOfBirth = 0;
    dayOfDeath = 0;
}

Person::Person(string n, string g, int dob, int dod)    //Smiður fyrir Person klasann til að upphafstilla private breytur.
{
    id = 0;
    name = n;
    gender = g;
    dayOfBirth = dob;
    dayOfDeath = dod;
}

Person::Person(int i, string n, string g, int dob, int dod)
{
    id = i;
    name = n;
    gender = g;
    dayOfBirth = dob;
    dayOfDeath = dod;
}

int Person::getId()
{
    return id;
}

string Person::getName()        //Skilar "name".
{
    return name;
}

string Person::getGender()      //Skilar "gender".
{
    return gender;
}

int Person::getDayOfBirth()     //Skilar "DayOfBirth".
{
    return dayOfBirth;
}

int Person::getDayOfDeath()     //Skilar "DayOfDeath".
{
    return dayOfDeath;
}
