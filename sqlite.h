#ifndef SQLITE_H
#define SQLITE_H
#include <QtSql>
#include "person.h"
#include "computers.h"
#include "comp_pers.h"

class SQLite
{
public:
    SQLite();
    void saveData();                                //Vistar vector af persónum.
    void addData(Person& p);                        //Bætir persónu við listann.
    void addComputer(Computers& c);                 //Bætir computer við listann.
    void addRelation(int computerID, int personID); //Venslar person og computer saman.
    vector<Comp_pers> getLinkedComputers(int pID);  //Sækir lista af venslafærslum fyrir person.
    vector<Comp_pers> getLinkedPerson(int cID);     //Sækir lista af venslafærslum fyrir computer.
    vector<Person> getPersonList();                 //Sækir lista af persónum.
    vector<Computers> getComputerList();            //Sækir lista af computer.
    void removeScientist(int input);                //Eyðir person úr gagnagrunninum.
    void removeComputer(int input);                 //Eyðir computer úr gagnagrunnninum.
    vector<Person> searchPersons(string search);    //
    vector<Computers> searchComputers(string search);
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











private:                                                    //Prívat breytur.
    QSqlDatabase m_db;                                      //
    void openDatabase();                                    //Opnar tengingu við gagnagrunn.
    vector<Person> addPersonQueryToList(QSqlQuery &query);
    vector<Computers> addComputerQueryToList(QSqlQuery &query);
};

#endif
