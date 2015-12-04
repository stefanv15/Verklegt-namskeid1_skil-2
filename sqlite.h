#ifndef SQLITE_H
#define SQLITE_H
#include "person.h"
#include <vector>
#include <QtSql>

class SQLite
{
public:
    SQLite();
    void saveData();                // vistar vector af persónum.
    void addData(Person& p);        // bætir persónu við
    vector<Person> getPersonList(); // sækir m_personList.

private:
    QSqlDatabase m_db;

    void getData(); // sækir allar persónur úr skrá og setur inn í vectorinn.
    vector<Person> m_personList; // geymir lista af persónum.
    void createTestData();      // temp. prufu data.
};

#endif
