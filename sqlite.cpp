#include "sqlite.h"
#include <fstream>
#include "person.h"
#include <cstdlib>

SQLite::SQLite()
{
    getData();
}

void SQLite::getData()       //Sækir gögn úr skrá og geymir í vektor.
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "prufa.sqlite";
    m_db.setDatabaseName(dbName);

    m_db.open();

    QSqlQuery query(m_db);

    const QString sSQL = "SELECT * FROM person";
    query.exec(sSQL);

    while(query.next())
    {

        //int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        string gender = query.value("gender").toString().toStdString();
        int dob = query.value("yearOfBirth").toUInt();
        int dod  = query.value("yearOfDeath").toUInt();

        Person newguy(name, gender, dob, dod);
        m_personList.push_back(newguy);
    }
}

void SQLite::saveData()                      //Sækir gögn úr vektor og vistar í skrá.
{
    m_db.close();
}

/******************************************************************************
 * Fall:   addData
 * Lýsing: Bætir við persónu í gagnagrunn.
 *****************************************************************************/
void SQLite::addData(Person& p)
{
    const QString sInsertSQL = QString("Insert into person(name, gender, yearOfBirth, yearOfDeath) values ('%1','%2',%3,%4)").arg(QString::fromStdString(p.getName()),QString::fromStdString(p.getGender()),QString::number( p.getDayOfBirth()),QString::number(p.getDayOfDeath()));

    QSqlQuery query(m_db);
    query.exec(sInsertSQL);

    m_personList.push_back(p);
}

vector<Person> SQLite::getPersonList()        //Skilar private breytunni m_personList.
{
    return m_personList;
}
