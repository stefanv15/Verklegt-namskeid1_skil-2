#ifndef INTERFACE_H
#define INTERFACE_H
#include "person.h"
#include "computers.h"
#include "domain.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Interface
{
public:
    Interface();
    void start();

private:
    Domain m_domain;
    void programInfo()const;    //Opnunarskilaboð til notanda.
    void mainMenu() const;  //Aðalvalmynd.
    char listMenu() const;   //Valmynd fyrir lista.
    int sortMenu() const;   //Valmynd fyrir uppröðun á lista.
    Person getPersonInfo(); //Fær upplýsingar um persónu frá notanda.
    Computers getComputerInfo(); //Inntak fyrir upplýsingar um tölvu.
    void printListPerson(vector<Person> listOfPersons); //Prentar út lista af persónum.
    void printListComputers(vector<Computers> listOfComputers); //Prentar út upplýsingar um tölvur.
    void addPerson();
    void addComputer();
    void showListPerson();
    void showListComputer();
    void removeScientist();
    void removeComputer();
    void searchSci();
    void searchComp();
    void printSortedReverse(); //Prentar út upplýsingar í öfugri stafrófsröð.
    void printSorted(); //Prentar út upplýsingar í stafrófsröð.
    void printSortedYear(); //Prentar út upplýsingar frá elsta ári til yngsta.
    void printSortedYearReverse();  //Prentar út upplýsingar frá yngsta ári til elsta.
    void printColumnListPerson(vector<Person> listOfPersons);
};

#endif // INTERFACE_H
