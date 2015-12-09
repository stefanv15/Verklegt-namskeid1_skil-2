#ifndef COMPUTERS_H
#define COMPUTERS_H
#include <string>

using namespace std;

class Computers
{
public:

    Computers();                                                                    //Sjálfgefinn smiður.
    Computers(int idee, string nameOC, int yearB, string typeOC, string wasB);      //Smiður sem upphafsstillir 5 prívat breytur.
    Computers(string nameOC, int yearB, string typeOC, string wasB);                //Smiður sem upphafsstillir 4 prívat breytur.
    string getNameOfCpu();                                                          //Skilar nafn á tölvu.
    int getYearBuilt();                                                             //Skilar byggingarár tölvu.
    int getId();                                                                    //Skilar ID á tölvu.
    string getTypeOfCpu();                                                          //Skilar tegund tölvu.
    string getWasBuilt();                                                           //Skilar upplýsingar um hvort tölva hafi verið byggð.

private:                                                                            //Prívat breytur.
    int id;
    string nameOfCpu;
    int yearBuilt;
    string typeOfCpu;
    string wasBuilt;
};

#endif // COMPUTERS_H
