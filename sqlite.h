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
<<<<<<< HEAD
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
    vector<Person> getPersonListByName();           //
    vector<Person> searchPersons(string search);    //
=======
    void saveData();                                // vistar vector af persónum.
    void addData(Person& p);                        // bætir persónu við
    void addComputer(Computers& c);
    void addRelation(int computerID, int personID);
    vector<Comp_pers> getLinkedComputers(int pID);  // Sækir lista af venslafærslum fyrir person
    vector<Person> getPersonList();
    vector<Computers> getComputerList();
    void removeScientist(int input);
    void removeComputer(int input);
    vector<Person> getPersonListByName();
    vector<Person> searchPersons(string search);
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
>>>>>>> 665a40f0bb7086337029b7471abdbb24f15521a6

private:                                                    //Prívat breytur.
    QSqlDatabase m_db;                                      //
    void openDatabase();                                    //Opnar tengingu við gagnagrunn.
    vector<Person> AddPersonQueryToList(QSqlQuery &query);

};

#endif
