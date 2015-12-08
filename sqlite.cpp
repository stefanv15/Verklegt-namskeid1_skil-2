#include "person.h"
#include "computers.h"
#include "sqlite.h"

SQLite::SQLite()
{
    openDatabase();
}

//Sækir gögn úr gagnagrunni og geymir í vektor.
void SQLite::openDatabase()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "scientists.sqlite";
    m_db.setDatabaseName(dbName);

    m_db.open();
}

//Nær í nýjust  gögn úr gagnagrunni persóna og skilar í vektor.
vector<Person> SQLite::addPersonQueryToList(QSqlQuery &query)
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

//Nær í nýjustu gögn úr gagnagrunni tölva og skilar í vektor.
vector<Computers> SQLite::addComputerQueryToList(QSqlQuery &query)
{
    vector<Computers> list;

    while(query.next())
    {
        int id = query.value("id").toUInt();
        string nameOfCpu = query.value("nameOfCpu").toString().toStdString();
        int yearBuilt = query.value("yearBuilt").toUInt();
        string typeOfCpu = query.value("typeOfCpu").toString().toStdString();
        string wasBuilt = query.value("wasBuilt").toString().toStdString();

        Computers newCpu(id, nameOfCpu, yearBuilt, typeOfCpu, wasBuilt);
        list.push_back(newCpu);
    }
    return list;
}

//Sækir lista af persónum.
vector<Person> SQLite::getPersonList()
{
    QSqlQuery query(m_db);

    const QString sSQL = "SELECT * FROM person";
    query.exec(sSQL);

    return addPersonQueryToList(query);
}

//Sækir lista af tölvum
vector<Computers> SQLite::getComputerList()
{
    QSqlQuery query(m_db);

    const QString sSQL = "SELECT * FROM computers";
    query.exec(sSQL);

    return addComputerQueryToList(query);
}

//Lokar á tengsl við gagnagrunn.
void SQLite::saveData()
{
    m_db.close();
}

//Bætir persónu við gagnagrunninn.
void SQLite::addData(Person& p)
{
    const QString sInsertSQL = QString("Insert into person(name, gender, yearOfBirth, yearOfDeath) values ('%1','%2',%3,%4)").arg(QString::fromStdString(p.getName()),QString::fromStdString(p.getGender()),QString::number( p.getDayOfBirth()),QString::number(p.getDayOfDeath()));

    QSqlQuery query(m_db);
    query.exec(sInsertSQL);
}

//Bætir tölvu við gagnagrunn.
void SQLite::addComputer(Computers& c)
{
    const QString sInsertSQL = QString("Insert into computers(nameOfCpu, yearBuilt, typeOfCpu, wasBuilt) values ('%1','%2','%3','%4')").arg(QString::fromStdString(c.getNameOfCpu()),QString::number(c.getYearBuilt()),QString::fromStdString(c.getTypeOfCpu()),QString::fromStdString(c.getWasBuilt()));
    QSqlQuery query(m_db);
    query.exec(sInsertSQL);
}

//Venslar persónu og tölvu saman.
void SQLite::addRelation(int computerID, int personID)
{
    const QString sInsertSQL = QString("Insert into comp_pers(compID, persID) "
                                       "values (%1,%2)").arg(QString::number(computerID),QString::number(personID));
    QSqlQuery query(m_db);
    query.exec(sInsertSQL);
}

//Sækir lista af venslafærslum fyrir tölvur
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

//Sækir lista af venslafærslum fyrir persónur.
vector<Comp_pers> SQLite::getLinkedPerson(int cID)
{
    QSqlQuery query(m_db);

    const QString sSQL = "SELECT * FROM comp_pers where compID =  "+QString::number(cID);
    query.exec(sSQL);

    vector<Comp_pers> persList;
    while(query.next())
    {
        int cid = query.value("compID").toUInt();
        int pid = query.value("persID").toUInt();

        Comp_pers newPers(cid, pid);
        persList.push_back(newPers);
    }
    return persList;
}

//Leitar af persónum í gagnagrunni.
vector<Person> SQLite::searchPersons(string search)
{
    QSqlQuery query(m_db);

    QString sSQL = "select * from person where name like '%%%1%%'";
    sSQL = sSQL.arg(QString::fromStdString(search));

    query.exec(sSQL);

    return addPersonQueryToList(query);
}

//Leitar af tölvum í gagnagrunni.
vector<Computers> SQLite::searchComputers(string search)
{
    QSqlQuery query(m_db);

    QString sSQL = "select * from computers where nameOfCpu like '%%%1%%'";
    sSQL = sSQL.arg(QString::fromStdString(search));

    query.exec(sSQL);

    return addComputerQueryToList(query);
}

//Fjarlægir persónu endanlega úr gagnagrunninum
void SQLite::removeScientist(int input)
{
    QSqlQuery query(m_db);
    QString delSQL = "DELETE FROM person WHERE id = "+QString::number(input);
    query.exec(delSQL);
}

//Fjarlægir tölvu endanlega úr gagnagrunninum
void SQLite::removeComputer(int input)
{
    QSqlQuery query(m_db);
    QString delSQL = "DELETE FROM computers WHERE id = "+QString::number(input);
    query.exec(delSQL);
}

//Raðar nafni tölvunarfræðings eftir stafrófsröð
vector <Person> SQLite::sortAscName()
{
    QSqlQuery query(m_db);
    const QString ascSQL = "SELECT * FROM person ORDER BY name ASC";
    query.exec(ascSQL);
    return addPersonQueryToList(query);
}

//Raðar nafni tölvunarfræðings í öfugri stafrófsröð
vector<Person> SQLite::sortDescName()
{
     QSqlQuery query(m_db);
     const QString descSQL = "SELECT * FROM person ORDER BY name DESC";
     query.exec(descSQL);
     return addPersonQueryToList(query);
}

//Raðar tölvunarfræðingi eftir kyni
vector<Person> SQLite::sortGender()
{
     QSqlQuery query(m_db);
     const QString genderAscSQL = "SELECT * FROM person ORDER BY gender ASC";
     query.exec(genderAscSQL);
     return addPersonQueryToList(query);
}

//Raðar tölvunarfræðingi eftir fæðingarári frá 1-10
vector<Person> SQLite::sortAscYearOfBirth()
{
     QSqlQuery query(m_db);
     const QString yobAscSQL = "SELECT * FROM person ORDER BY yearOfBirth ASC";
     query.exec(yobAscSQL);
     return addPersonQueryToList(query);
}

//Raðar tölvunarfræðingi eftir fæðingarári frá 10-1
vector<Person> SQLite::sortDescYearOfBirth()
{
     QSqlQuery query(m_db);
     const QString yobDescSQL = "SELECT * FROM person ORDER BY yearOfBirth DESC";
     query.exec(yobDescSQL);
     return addPersonQueryToList(query);
}

//Raðar nafni á tölvu eftir stafrófsröð
vector<Computers> SQLite::sortAscNameOfCpu()
{
     QSqlQuery query(m_db);
     const QString cpuAscSQL = "SELECT * FROM computers ORDER BY nameOfCpu ASC";
     query.exec(cpuAscSQL);
     return addComputerQueryToList(query);
}

//Raðar nafni á tölvu eftir öfugri stafrófsröð
vector<Computers> SQLite::sortDescNameOfCpu()
{
     QSqlQuery query(m_db);
     const QString cpuDescSQL = "SELECT * FROM computers ORDER BY nameOfCpu DESC";
     query.exec(cpuDescSQL);
     return addComputerQueryToList(query);
}

//Raðar tölvu eftir byggingarári 1-10
vector<Computers> SQLite::sortAscYearBuilt()
{
     QSqlQuery query(m_db);
     const QString ybAscSQL = "SELECT * FROM computers ORDER BY yearBuilt ASC";
     query.exec(ybAscSQL);
     return addComputerQueryToList(query);
}

//Raðar tölvu eftir byggingarári 10-1
vector<Computers> SQLite::sortDescYearBuilt()
{
     QSqlQuery query(m_db);
     const QString ybDescSQL = "SELECT * FROM computers ORDER BY yearBuilt DESC";
     query.exec(ybDescSQL);
     return addComputerQueryToList(query);
}

//Raðar tölvu eftir týpunafni í stafrófsröð
vector<Computers> SQLite::sortAscTypeOfCpu()
{
     QSqlQuery query(m_db);
     const QString typeAscSQL = "SELECT * FROM computers ORDER BY typeOfCpu ASC";
     query.exec(typeAscSQL);
     return addComputerQueryToList(query);
}

//Raðar tölvu eftir týpunafni í öfugri stafrófsröð
vector<Computers> SQLite::sortDescTypeOfCpu()
{
     QSqlQuery query(m_db);
     const QString typeDescSQL = "SELECT * FROM computers ORDER BY typeOfCpu descSQL";
     query.exec(typeDescSQL);
     return addComputerQueryToList(query);
}

