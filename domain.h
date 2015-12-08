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
    Domain();

    void createPerson(Person p);  //Býr til eintak af persónu og vistar.
    void createComputer(Computers c);
    vector<Person> getList();   //Sækja lista.
    vector<Computers> getComputerList();
    string getComputerList(int pId);    //Sækja lista af tölvum fyrir e-a persónu
    void saveAllData(); //Vistar í .txt þegar notandi velur 3. exit.
    vector<Person> searchScientist(string search);  //Leitar af persónu í lista.
    vector<Computers> searchComputer(string search);
    void removeScientist(int input);
    void removeComputer(int input);
    vector<Person> getPersonListByName();  //Raðar lista í stafrófsröð og skilar til baka.
    vector<Person> sortListReverse(vector<Person> listOfPersons);   //Raðar lista í öfugri stafrófsröð og skilar til baka.
    vector<Person> sortListYear(vector<Person> listOfPersons);  //Raðar lista upp eftir fæðingarári og skilar til baka.
    vector<Person> sortListYearReverse(vector<Person> listOfPersons);   //Raðar lista upp eftir öfugu fæðingar ári(yngsti efst)
    Computers findComputerById(int cID);
    void createRelation(int computerID, int personID);
    void sortAscName();
    void sortDescName();
    void sortGender();
    void sortAscYearOfBirth();
    void sortDescYearOfBirth();
    void sortAscNameOfCpu();
    void sortDescNameOfCpu();
    void sortAscYearBuilt();
    void sortDescYearBuilt();
    void sortAscTypeOfCpu();
    void sortDescTypeOfCpu();

private:
    SQLite m_sqlite;   //Object af DataLayer fyrir Domain klasann.
};

#endif // DOMAIN_H
