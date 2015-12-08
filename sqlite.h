#ifndef SQLITE_H
#define SQLITE_H
#include "person.h"
#include "computers.h"

#include <QtSql>
#include "comp_pers.h"

class SQLite
{
public:
    SQLite();
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

private:
    QSqlDatabase m_db;
    void openDatabase();                            // opnar tengingu við gagnagrunn.
    vector<Person> AddPersonQueryToList(QSqlQuery &query);

};

#endif
