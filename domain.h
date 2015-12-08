#ifndef DOMAIN_H
#define DOMAIN_H
#include "SQLite.h"
#include "person.h"
#include "computers.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Domain
{
public:
    Domain();                              //Sjálfgefinn smiður.
    void createPerson(Person p);           //Býr til eintak af persónu.
    void createComputer(Computers c);      //Býr til eintak af computer.
    vector<Person> getList();              //Sækir Persónu lista.
    vector<Computers> getComputerList();   //Sækir Computer lista.
    void saveAllData();                    //Vistar í .txt þegar notandi velur 3. exit.
    vector<Person> searchScientist(string search);      //Leitar af persónu í lista.
    vector<Computers> searchComputer(string search);    //Leitar af computer í lista.
    void removeScientist(int input);       //Eyðir persónu úr gagnagrunni.
    void removeComputer(int input);        //Eyðir computer úr gagnagrunni.
    string getComputerList(int pId);       //Sækja lista af tölvum fyrir e-a persónu
    string getPersList(int pId);         //Sækja lista af persónum fyrir e-a tölvu
    Computers findComputerById(int cID);
    Person findPersonById(int cID);
    void createRelation(int computerID, int personID);
    vector<Person> sortAscName();
    vector<Person> sortDescName();
    vector<Person> sortGender();
    vector<Person> sortAscYearOfBirth();
    vector<Person> sortDescYearOfBirth();
    vector<Computers> sortAscNameOfCpu();
    vector<Computers> sortDescNameOfCpu();
    vector<Computers> sortAscYearBuilt();
    vector<Computers> sortDescYearBuilt();
    vector<Computers> sortAscTypeOfCpu();
    vector<Computers> sortDescTypeOfCpu();

private:
    SQLite m_sqlite;   //Object af DataLayer fyrir Domain klasann.
};

#endif // DOMAIN_H
