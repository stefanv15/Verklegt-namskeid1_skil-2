#ifndef SQLITE_H
#define SQLITE_H
#include "person.h"
#include "computers.h"
//#include <vector>
#include <QtSql>
#include "comp_pers.h"

class SQLite
{
public:
    SQLite();
    void saveData();                                // vistar vector af persónum.
    void addData(Person& p);                        // bætir persónu við
    void addComputer(Computers& c);
    vector<Comp_pers> getLinkedComputers(int pID);  // Sækir lista af venslafærslum fyrir person
    vector<Person> getPersonList();
    vector<Computers> getComputerList();

private:
    QSqlDatabase m_db;
    void openDatabase();                            // opnar tengingu við gagnagrunn.
};

#endif
