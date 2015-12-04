#ifndef INTERFACE_H
#define INTERFACE_H
#include "person.h"
#include "worker.h"

#include <iostream>
#include <vector>
#include "computers.h"

using namespace std;

class Interface
{
public:
    Interface();
    void start();

private:
    Worker m_worker;
    void programInfo()const;
    void pickOption();
    Person getPersonInfo();  // fær upplýsingar um persónu frá notanda.
    void printListPerson(vector<Person> listOfPersons); // prentar út lista af persónum.
    int askSearchOrSort();
    void printSortedReverse();
    void printSorted();
    void printSortedYear();
    void printSortedYearReverse();
    int sortMenu();
    Computers getComputerInfo();
    void printListComputers(vector<Computers> listOfComputers);
};

#endif // INTERFACE_H
