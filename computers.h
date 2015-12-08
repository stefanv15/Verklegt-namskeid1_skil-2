#ifndef COMPUTERS_H
#define COMPUTERS_H
//#include <iostream>
#include <string>
//#include <vector>
using namespace std;

class Computers
{
public:
    Computers();                //Sjálfgefinn smiður
    Computers(int idee, string nameOC, int yearB, string typeOC, string wasB);      //Computers fall sem hefur aðgang að 5 private breytum.
    Computers(string nameOC, int yearB, string typeOC, string wasB);                //Computers fall sem hefur aðgang að 4 private breytum.
    string getNameOfCpu();      //Sækir nafn á tölvu.
    int getYearBuilt();         //Sækir byggingarár tölvu.
    int getId();                //Sækir ID á tölvu.
    string getTypeOfCpu();      //Sækir tegund tölvu.
    string getWasBuilt();       //Sækir upplýsingar um hvort tölva hafi verið byggð.

private:                        //Private breytur.
    int id;
    string nameOfCpu;
    int yearBuilt;
    string typeOfCpu;
    string wasBuilt;


};

#endif // COMPUTERS_H
