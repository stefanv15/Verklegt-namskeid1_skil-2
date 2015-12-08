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
    void start();                   //Keyrir forritið.

private:
    Domain m_domain;
    void programInfo()const;        //Opnunarskilaboð til notanda.
    void mainMenu();                //Aðalvalmynd.
    char listMenu() const;          //Valmynd fyrir lista.
    int sortMenu() const;           //Valmynd fyrir uppröðun persóna.
    int sortMenu2() const;          //Valmynd fyrir uppröðun tölva.
    Person getPersonInfo();         //Fær upplýsingar um persónu frá notanda.
    Computers getComputerInfo();    //Inntak fyrir upplýsingar um tölvu.
    void printColumnListComputers(vector<Computers> listOfComputers);   //Prentar út upplýsingar um tölvur.
    void printColumnListPerson(vector<Person> listOfPersons);           //Prentar út upplýsingar um persónur.
    void addPerson();               //Bætir við persónu.
    void addComputer();             //Bætir við tölvu.
    void addRelation();             //Bætir við tengslu persónu og tölvu
    void showListPerson();          //Sýnir lista yfir persónur, listmenu og sortmenu.
    void showListComputer();        //Sýnir lista yfir tölvur, listmenu og sortmenu2.
    void removeScientist();         //Fjarlægir persónu endanlega úr gagnagrunni.
    void removeComputer();          //Fjarlægir tölvu endanlega úr gagnagrunni.
    void searchSci();               //Leitar og skilar vektor af öllum persónum sem innihalda leitarskilyrði.
    void searchComp();              //Leitar og skilar vektor af öllum tölvum sem innihalda leitarskilyrði.
};

#endif // INTERFACE_H
