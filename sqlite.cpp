#include "person.h"
#include "computers.h"
#include "sqlite.h"

SQLite::SQLite()
{
    openDatabase();
}

void SQLite::openDatabase()       //Sækir gögn úr gagnagrunni og geymir í vektor.
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "scientists.sqlite";
    m_db.setDatabaseName(dbName);

    m_db.open();
}
vector<Person> SQLite::AddPersonQueryToList(QSqlQuery &query)

{
    vector<Person> list;

    while(query.next())
    {

        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        string gender = query.value("gender").toString().toStdString();
        int dob = query.value("yearOfBirth").toUInt();
        int dod  = query.value("yearOfDeath").toUInt();

        Person newguy(id, name, gender, dob, dod);
        list.push_back(newguy);
    }
    return list;
}

vector<Person> SQLite::getPersonList()
{
    QSqlQuery query(m_db);

    const QString sSQL = "SELECT * FROM person";
    query.exec(sSQL);

    return AddPersonQueryToList(query);
}

vector<Person> SQLite::getPersonListByName()
{
    QSqlQuery query(m_db);

    const QString sSQL = "SELECT * FROM person order by name";
    query.exec(sSQL);

    return AddPersonQueryToList(query);
}

vector<Computers> SQLite::getComputerList()
{
    QSqlQuery query(m_db);

    const QString sSQL = "SELECT * FROM computers";
    query.exec(sSQL);

    vector<Computers> list;

    while(query.next())
    {
        int id = query.value("id").toUInt();
        string nameOfCpu = query.value("nameOfCpu").toString().toStdString();
        int yearBuilt = query.value("yearBuilt").toUInt();
        string typeOfCpu = query.value("typeOfCpu").toString().toStdString();
        string wasBuilt = query.value("wasBuilt").toString().toStdString();

        Computers c(id, nameOfCpu, yearBuilt, typeOfCpu, wasBuilt);
        Computers newCpu(id, nameOfCpu, yearBuilt, typeOfCpu, wasBuilt);
        list.push_back(newCpu);
    }
    return list;
}



void SQLite::saveData()                       //Sækir gögn úr vektor og vistar í skrá.
{
    m_db.close();
}

void SQLite::addData(Person& p)               // Vistar persónu í gagnagrunninn.
{
    const QString sInsertSQL = QString("Insert into person(name, gender, yearOfBirth, yearOfDeath) values ('%1','%2',%3,%4)").arg(QString::fromStdString(p.getName()),QString::fromStdString(p.getGender()),QString::number( p.getDayOfBirth()),QString::number(p.getDayOfDeath()));

    QSqlQuery query(m_db);
    query.exec(sInsertSQL);
}

void SQLite::addComputer(Computers& c)
{

    const QString sInsertSQL = QString("Insert into computers(nameOfCpu, yearBuilt, typeOfCpu, wasBuilt) values ('%1','%2,'%3','%4')").arg(QString::fromStdString(c.getNameOfCpu()),QString::number(c.getYearBuilt()),QString::fromStdString(c.getTypeOfCpu()),QString::fromStdString(c.getWasBuilt()));

    QSqlQuery query(m_db);
    query.exec(sInsertSQL);
}

void SQLite::addRelation(int computerID, int personID)
{
    const QString sInsertSQL = QString("Insert into comp_pers(compID, persID) values (%1,%2)").arg(QString::number(computerID),QString::number(personID));

    QSqlQuery query(m_db);
    query.exec(sInsertSQL);
}

vector<Comp_pers> SQLite::getLinkedComputers(int pID)
{
    QSqlQuery query(m_db);

    const QString sSQL = "SELECT * FROM comp_pers where persID = "+QString::number(pID);
    query.exec(sSQL);

    vector<Comp_pers> cpList;
    while(query.next())
    {
        int cid = query.value("compID").toUInt();
        int pid = query.value("persID").toUInt();

        Comp_pers newCP(cid, pid);
        cpList.push_back(newCP);
    }
    return cpList;
}

vector<Person> SQLite::searchPersons(string search)
{
    QSqlQuery query(m_db);

    QString sSQL = "select * from person where name like '%%%1%%'";
    sSQL = sSQL.arg(QString::fromStdString(search));

    query.exec(sSQL);

    return AddPersonQueryToList(query);
}

void SQLite::removeScientist(int input)
{
    QSqlQuery query(m_db);
    QString delSQL = "DELETE FROM person WHERE id = "+QString::number(input);
    query.exec(delSQL);
}

void SQLite::removeComputer(int input)
{
    QSqlQuery query(m_db);
    QString delSQL = "DELETE FROM person WHERE id = "+QString::number(input);
    query.exec(delSQL);
}

void SQLite::sortAscName()
{
    QSqlQuery query(m_db);
    const QString ascSQL = "SELECT * FROM person ORDER BY name ASC";
    query.exec(ascSQL);
}

void SQLite::sortDescName()
{
     QSqlQuery query(m_db);
     const QString descSQL = "SELECT * FROM person ORDER BY name DESC";
     query.exec(descSQL);
}

void SQLite::sortGender()
{
     QSqlQuery query(m_db);
     const QString genderAscSQL = "SELECT * FROM person ORDER BY gender ASC";
     query.exec(genderAscSQL);
}

void SQLite::sortAscYearOfBirth()
{
     QSqlQuery query(m_db);
     const QString yobAscSQL = "SELECT * FROM person ORDER BY yearOfBirth ASC";
     query.exec(yobAscSQL);
}

void SQLite::sortDescYearOfBirth()
{
     QSqlQuery query(m_db);
     const QString yobDescSQL = "SELECT * FROM person ORDER BY yearOfBirth DESC";
     query.exec(yobDescSQL);
}

void SQLite::sortAscNameOfCpu()
{
     QSqlQuery query(m_db);
     const QString cpuAscSQL = "SELECT * FROM computers ORDER BY nameOfCpu ASC";
     query.exec(cpuAscSQL);
}
void SQLite::sortDescNameOfCpu()
{
     QSqlQuery query(m_db);
     const QString cpuDescSQL = "SELECT * FROM computers ORDER BY nameOfCpu DESC";
     query.exec(cpuDescSQL);
}

void SQLite::sortAscYearBuilt()
{
     QSqlQuery query(m_db);
     const QString ybAscSQL = "SELECT * FROM computers ORDER BY yearBuilt ASC";
     query.exec(ybAscSQL);
}

void SQLite::sortDescYearBuilt()
{
     QSqlQuery query(m_db);
     const QString ybDescSQL = "SELECT * FROM computers ORDER BY yearBuilt DESC";
     query.exec(ybDescSQL);
}

void SQLite::sortAscTypeOfCpu()
{
     QSqlQuery query(m_db);
     const QString typeAscSQL = "SELECT * FROM computers ORDER BY typeOfCpu ASC";
     query.exec(typeAscSQL);
}

void SQLite::sortDescTypeOfCpu()
{
     QSqlQuery query(m_db);
     const QString typeDescSQL = "SELECT * FROM computers ORDER BY typeOfCpu descSQL";
     query.exec(typeDescSQL);
}

