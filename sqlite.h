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
    vector<Person> getPersonList();                 // sækir m_personList.
    vector<Computers> getComputerList();
    vector<Comp_pers> getLinkedComputers(int pID);  // Sækir lista af venslafærslum fyrir person

private:
    QSqlDatabase m_db;
    void getData(); // sækir allar persónur úr skrá og setur inn í vectorinn.
    vector<Person> m_personList; // geymir lista af persónum.
    vector<Computers> m_computerList;

    void loadPersonData();
    void loadComputerData();
};

#endif
