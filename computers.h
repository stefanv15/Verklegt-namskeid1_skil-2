#ifndef COMPUTERS_H
#define COMPUTERS_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Computers
{
public:
    Computers();
    Computers(string nameOC, int idee, string yearB, string typeOC, string wasB);
    string getNameOfCpu();
    int getId();
    string getYearBuilt();
    string getTypeOfCpu();
    string getWasBuilt();

private:
    string nameOfCpu;
    int id;
    string yearBuilt;
    string typeOfCpu;
    string wasBuilt;


};

#endif // COMPUTERS_H
