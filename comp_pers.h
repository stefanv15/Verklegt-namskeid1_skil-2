#ifndef COMP_PERS_H
#define COMP_PERS_H


class Comp_pers
{
public:
    Comp_pers();
    Comp_pers(int cID, int pID);

    int getPersonID();
    int getComputerID();

private:
    int personID;
    int computerID;
};

#endif // COMP_PERS_H
