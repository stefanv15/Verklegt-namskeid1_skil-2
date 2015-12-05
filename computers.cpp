#include "computers.h"
Computers::Computers()
{
    nameOfCpu = "";
    id = 0;
    yearBuilt = 0;
    typeOfCpu = "";
    wasBuilt = "";
}

Computers::Computers(string nameOC, int yearB, string typeOC, string wasB)
{
    nameOfCpu = nameOC;
    yearBuilt = yearB;
    typeOfCpu = typeOC;
    wasBuilt = wasB;
}

Computers::Computers(int idee, string nameOC, int yearB, string typeOC, string wasB)
{
    id = idee;
    nameOfCpu = nameOC;
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

int Computers::getYearBuilt()
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
