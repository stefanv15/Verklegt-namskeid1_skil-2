#ifndef INTERFACE_H
#define INTERFACE_H
#include "person.h"
#include "worker.h"
#include "computers.h"
#include <iostream>
#include <vector>

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
    Computers getComputerInfo();
    void printListPerson(vector<Person> listOfPersons); // prentar út lista af persónum.
    void printListComputers(vector<Computers> listOfComputers);
    int askSearchOrSort();
    void printSortedReverse();
    void printSorted();
    void printSortedYear();
    void printSortedYearReverse();
    int sortMenu();
};

#endif // INTERFACE_H
