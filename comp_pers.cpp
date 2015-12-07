#include "comp_pers.h"

Comp_pers::Comp_pers()
{

}

Comp_pers::Comp_pers(int pID, int cID)
{
    personID = pID;
    computerID = cID;
}

int Comp_pers::getPersonID()
{
    return personID;
}

int Comp_pers::getComputerID()
{
    return computerID;
}
