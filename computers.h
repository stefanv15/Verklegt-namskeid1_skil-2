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
    Computers(string nameOC, int idee, int yearB, string typeOC, string wasB);
    Computers(string nameOC, int yearB, string typeOC, string wasB);
    int getId();
    string getNameOfCpu();
    int getYearBuilt();
    string getTypeOfCpu();
    string getWasBuilt();

private:
    int id;
    string nameOfCpu;
    int yearBuilt;
    string typeOfCpu;
    string wasBuilt;


};

#endif // COMPUTERS_H
