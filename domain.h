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
<<<<<<< HEAD
    Domain();                              //Sjálfgefinn smiður.
    void createPerson(Person p);           //Býr til eintak af persónu.
    void createComputer(Computers c);      //Býr til eintak af computer.
    vector<Person> getList();              //Sækir Persónu lista.
    vector<Computers> getComputerList();   //Sækir Computer lista.
    string getComputerList(int pId);       //Sækja lista af tölvum fyrir e-a persónu
    void saveAllData();                    //Vistar í .txt þegar notandi velur 3. exit.
    vector<Person> searchScientist(string search);      //Leitar af persónu í lista.
    vector<Computers> searchComputer(string search);    //Leitar af computer í lista.
    void removeScientist(int input);       //Eyðir persónu úr gagnagrunni.
    void removeComputer(int input);        //Eyðir computer úr gagnagrunni.
    vector<Person> getPersonlistByName();  //Raðar lista í stafrófsröð og skilar til baka.
    vector<Person> sortListReverse(vector<Person> listOfPersons);       //Raðar lista í öfugri stafrófsröð og skilar til baka.
    vector<Person> sortListYear(vector<Person> listOfPersons);          //Raðar lista upp eftir fæðingarári og skilar til baka.
=======
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
>>>>>>> 665a40f0bb7086337029b7471abdbb24f15521a6
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
<<<<<<< HEAD
    SQLite m_datalayer;                    //Object af DataLayer fyrir Worker klasann.
=======
    SQLite m_datalayer;   //Object af DataLayer fyrir Domain klasann.
>>>>>>> 665a40f0bb7086337029b7471abdbb24f15521a6
};

#endif // DOMAIN_H
