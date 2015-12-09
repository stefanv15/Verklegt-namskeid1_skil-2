#ifndef COMP_PERS_H
#define COMP_PERS_H

class Comp_pers
{
public:
    Comp_pers();                    //Sjálfgefinn smiður fyrir comp_pers klasann.
    Comp_pers(int cID, int pID);    //Smiður sem upphafsstillir prívat breytur.
    int getPersonID();              //Skilar personID.
    int getComputerID();            //Skilar computerID.

private:                            //Private breytur fyrir comp_pers klasann.
    int personID;
    int computerID;
};

#endif // COMP_PERS_H
