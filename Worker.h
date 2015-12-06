#ifndef WORKER_H
#define WORKER_H
#include "SQLite.h"
#include "person.h"
#include "computers.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Worker
{
public:
    Worker();

    void createPerson(Person p);                            // Býr til eintak af persónu og vistar.
    void createComputer(Computers c);
    vector<Person> getList();                               // sækja lista.
    vector<Computers> getComputerList();
    string getComputerList(int pId);             // Sækja lista af tölvum fyrir e-a persónu
    void saveAllData();                                     // Vistar í .txt þegar notandi velur 3. exit.
    vector<Person> searchScientist(string search);          // Leitar af persónu í lista.
    vector<Person> removeScientist(string remove);
    vector<Person> sortList(vector<Person> listOfPersons);  // Raðar lista í stafrófsröð og skilar til baka.
    vector<Person> sortListReverse(vector<Person> listOfPersons);
    vector<Person> sortListYear(vector<Person> listOfPersons);
    vector<Person> sortListYearReverse(vector<Person> listOfPersons);
    Computers findComputerById(int cID);

private:
    SQLite m_datalayer;                                  // Object af DataLayer fyrir Worker klasann.
};

#endif // WORKER_H
