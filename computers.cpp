#include "computers.h"

//Sjálfgefinn smiður sem núllstillir private breytur.
Computers::Computers()
{
    nameOfCpu = "";
    id = 0;
    yearBuilt = 0;
    typeOfCpu = "";
    wasBuilt = "";
}

//Computers fall sem hefur aðgang að 5 private breytum.
Computers::Computers(string nameOC, int yearB, string typeOC, string wasB)
{
    nameOfCpu = nameOC;
    yearBuilt = yearB;
    typeOfCpu = typeOC;
    wasBuilt = wasB;
}

//Computers fall sem hefur aðgang að 4 private breytum.
Computers::Computers(int idee, string nameOC, int yearB, string typeOC, string wasB)
{
    id = idee;
    nameOfCpu = nameOC;
    yearBuilt = yearB;
    typeOfCpu = typeOC;
    wasBuilt = wasB;
}

//Skilar nafni á tölvu.
string Computers::getNameOfCpu()
{
    return nameOfCpu;
}

//Skilar ID á tölvu.
int Computers::getId()
{
    return id;
}

//Skilar byggingarári tölvu.
int Computers::getYearBuilt()
{
    return yearBuilt;
}

//Skilar tegund af tölvu.
string Computers::getTypeOfCpu()
{
    return typeOfCpu;
}

//Sækir upplýsingar um hvort tölva hafi verið byggð.
string Computers::getWasBuilt()
{
    return wasBuilt;
}
