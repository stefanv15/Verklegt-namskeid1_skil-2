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
    Domain();                                           //Sjálfgefinn smiður.
    void createPerson(Person p);                        //Býr til eintak af persónu.
    void createComputer(Computers c);                   //Býr til eintak af tölvu.
    vector<Person> getList();                           //Sækir personlist.
    vector<Computers> getComputerList();                //Sækir computerlist.
    void saveAllData();                                 //Kallar á savedata.
    vector<Person> searchScientist(string search);      //Leitar af persónu í lista.
    vector<Computers> searchComputer(string search);    //Leitar af tölvu í lista.
    void removeScientist(int input);                    //Eyðir persónu úr gagnagrunni.
    void removeComputer(int input);                     //Eyðir tölvu úr gagnagrunni.
    string getComputerList(int pId);                    //Sækir lista af tölvum fyrir e-a persónu.
    string getPersList(int pId);                        //Sækir lista af persónum fyrir e-a tölvu.
    Computers findComputerById(int cID);                //Finnur og skilar tölvu út frá id.
    Person findPersonById(int cID);                     //Finnur og skilar persónu út frá id.
    void createRelation(int computerID, int personID);  //Býr til tengsl milli tölvu og persónu.
    vector<Person> sortAscName();                       //Raðar persónum eftir stafrófsröð.
    vector<Person> sortDescName();                      //Raðar persónum eftir öfugri stafrófsröð.
    vector<Person> sortGender();                        //Raðar persónum eftir kyni.
    vector<Person> sortAscYearOfBirth();                //Raðar persónum eftir fæðingarári.
    vector<Person> sortDescYearOfBirth();               //Raðar persónum eftir öfugu fæðingarári.
    vector<Computers> sortAscNameOfCpu();               //Raðar tölvum eftir stafrófsröð.
    vector<Computers> sortDescNameOfCpu();              //Raðar tölvum eftir öfugri stafrófsröð.
    vector<Computers> sortAscYearBuilt();               //Raðar tölvum eftir byggingarári.
    vector<Computers> sortDescYearBuilt();              //Raðar tölvum eftir öfugu byggingarári.
    vector<Computers> sortAscTypeOfCpu();               //Raðar tölvum eftir stafrófsröð týpu.
    vector<Computers> sortDescTypeOfCpu();              //Raðar tölvum eftir öfugri stafrófsröð týpu.

private:
    SQLite m_sqlite;                                    //Object af DataLayer fyrir Domain klasann.
};

#endif // DOMAIN_H
