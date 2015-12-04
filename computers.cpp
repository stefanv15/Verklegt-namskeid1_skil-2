#include "computers.h"
Computers::Computers()
{
    nameOfCpu = "";
    id = 0;
    yearBuilt = "";
    typeOfCpu = "";
    wasBuilt = "";
}

Computers::Computers(string nameOC, int idee, string yearB, string typeOC, string wasB)
{
    nameOfCpu = nameOC;
    id = idee;
    yearBuilt = yearB;
    typeOfCpu = typeOC;
    wasBuilt = wasB;
}

string Computers::getNameOfCpu()
{
    return nameOfCpu;
}

int Computers::getId()
{
    return id;
}

string Computers::getYearBuilt()
{
    return yearBuilt;
}

string Computers::getTypeOfCpu()
{
    return typeOfCpu;
}

string Computers::getWasBuilt()
{
    return wasBuilt;
}
