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
    void saveData();                                            //Lokar á tengsl við gagnagrunn.
    void addData(Person& p);                                    //Bætir persónu við gagnagrunn.
    void addComputer(Computers& c);                             //Bætir tölvu við gagnagrunn.
    void addRelation(int computerID, int personID);             //Venslar persónu og tölvu saman.
    vector<Comp_pers> getLinkedComputers(int pID);              //Sækir lista af venslafærslum fyrir persónur.
    vector<Comp_pers> getLinkedPerson(int cID);                 //Sækir lista af venslafærslum fyrir tölvur.
    vector<Person> getPersonList();                             //Sækir lista af persónum.
    vector<Computers> getComputerList();                        //Sækir lista af tölvum.
    void removeScientist(int input);                            //Eyðir persónu úr gagnagrunninum.
    void removeComputer(int input);                             //Eyðir tölvu úr gagnagrunnninum.
    vector<Person> searchPersons(string search);                //Leitar af persónum í gagnagrunninum.
    vector<Computers> searchComputers(string search);           //Leitar af tölvum í gagnagrunninum.
    vector<Person> sortAscName();                               //Raðar persónum í gagnagrunninum eftir stafrófsröð.
    vector<Person> sortDescName();                              //Raðar persónum í gagnagrunninum eftir öfugri stafrófsröð.
    vector<Person> sortGender();                                //Raðar persónum í gagnagrunninum eftir kyni.
    vector<Person> sortAscYearOfBirth();                        //Raðar persónum í gagnagrunninum eftir fæðingarári.
    vector<Person> sortDescYearOfBirth();                       //Raðar persónum í gagnagrunninum eftir öfugu fæðingarári.
    vector<Computers> sortAscNameOfCpu();                       //Raðar tölvum í gagnagrunninum eftir stafrófsröð.
    vector<Computers> sortDescNameOfCpu();                      //Raðar tölvum í gagnagrunninum eftir öfugri stafrófsröð.
    vector<Computers> sortAscYearBuilt();                       //Raðar tölvum í gagnagrunninum eftir byggingarári.
    vector<Computers> sortDescYearBuilt();                      //Raðar tölvum í gagnagrunninum eftir öfugu byggingarári.
    vector<Computers> sortAscTypeOfCpu();                       //Raðar tölvum í gagnagrunninum eftir stafrófsröð týpu.
    vector<Computers> sortDescTypeOfCpu();                      //Raðar tölvum í gagnagrunninum eftir öfugri stafrófsröð týpu.

private:                                                        //Prívat breytur.
    QSqlDatabase m_db;
    void openDatabase();                                        //Opnar tengingu við gagnagrunn.
    vector<Person> addPersonQueryToList(QSqlQuery &query);      //Nær í nýjustu gögn úr gagnagrunni persóna og skilar i vektor.
    vector<Computers> addComputerQueryToList(QSqlQuery &query); //Nær í nýjustu gögn úr gagnagrunni tölva og skilar í vektor.
};

#endif
