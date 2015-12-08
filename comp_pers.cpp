#include "comp_pers.h"

//Sjálfgefinn smiður.
Comp_pers::Comp_pers()
{

}

//Smiður sem upphafsstillir prívat breyturnar.
Comp_pers::Comp_pers(int cID, int pID)
{
    personID = pID;
    computerID = cID;
}

//Skilar personID.
int Comp_pers::getPersonID()
{
    return personID;
}

//Skilar computerID.
int Comp_pers::getComputerID()
{
    return computerID;
}
