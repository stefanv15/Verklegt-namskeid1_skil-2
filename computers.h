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
    Computers(int idee, string nameOC, int yearB, string typeOC, string wasB);
    Computers(string nameOC, int yearB, string typeOC, string wasB);
    string getNameOfCpu();
    int getYearBuilt();
    int getId();
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
