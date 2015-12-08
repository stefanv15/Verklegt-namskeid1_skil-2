#include "domain.h"
#include "person.h"
#include "computers.h"
#include "comp_pers.h"
//#include "datalayer.h"
//#include <ctype.h>
//#include <string>
#include <algorithm>

Domain::Domain()    //Sjálfgefni smiðurinn fyrir domain klasann
{

}

//Býr til eintak af persónu og vistar.
void Domain::createPerson(Person p)
{
    m_sqlite.addData(p);
}

void Domain::createComputer(Computers c)
{
    m_sqlite.addComputer(c);
}

vector<Person> Domain::getList()                        //Nær í personlist úr datalayer og skilar honum.
{
    return m_sqlite.getPersonList();
}

vector<Computers> Domain::getComputerList()
{
    return m_sqlite.getComputerList();
}

string Domain::getComputerList(int pId)
{
    vector<Comp_pers> cpList = m_sqlite.getLinkedComputers(pId);
    string sComputers = "";
    for(unsigned int i = 0; i < cpList.size(); i++)
    {
        if (i>0)
            sComputers += ", ";
        Computers comp = findComputerById(cpList[i].getComputerID());
        sComputers += comp.getNameOfCpu();
    }
    return sComputers;
}

void Domain::saveAllData()                              // Nær í savedata fallið úr datalayer og skilar því.
{
    m_sqlite.saveData();
}

vector<Person> Domain::searchScientist(string search)   //Leitar af persónu í lista og skilar
{
    return m_sqlite.searchPersons(search);
}

vector<Computers> Domain::searchComputer(string search)   // Leitar af persónu í lista og skilar
{                                                         // vector af persónum sem fundust.
    return m_sqlite.searchComputers(search);
}

Computers Domain::findComputerById(int cID)               // Leitar af tölvu í lista og skilar henni
{
    vector<Computers> list = m_sqlite.getComputerList();
    Computers retComp;
    for(unsigned int i = 0; i < list.size(); i++)
    {
        if(list[i].getId()==cID)
        {
            retComp = list[i];
            break;
        }
    }
    return retComp;
}

//Leitar af persónu í lista eftir ID og fjarlægir hana endanlega úr gagnagrunninum.
void Domain::removeScientist(int input)
{
    return m_sqlite.removeScientist(input);
}

//Leitar af tölvu í lista eftir ID og fjarlægir hana endanlega úr gagnagrunninum.
void Domain::removeComputer(int input)
{
    return m_sqlite.removeComputer(input);
}

void Domain::createRelation(int computerID, int personID)
{
    m_sqlite.addRelation(computerID, personID);
}

vector<Person> Domain::getPersonListByName()            //Raðar upp lista af persónum í stafrófsröð.
{
    return m_sqlite.getPersonListByName();
}

void Domain::sortAscName()
{
    m_sqlite.sortAscName();
}

void Domain::sortDescName()
{
    m_sqlite.sortDescName();
}

void Domain::sortGender()
{
    m_sqlite.sortGender();
}

void Domain::sortAscYearOfBirth()
{
    m_sqlite.sortAscYearOfBirth();
}

void Domain::sortDescYearOfBirth()
{
    m_sqlite.sortDescYearOfBirth();
}

void Domain::sortAscNameOfCpu()
{
    m_sqlite.sortAscNameOfCpu();
}

void Domain::sortDescNameOfCpu()
{
    m_sqlite.sortDescNameOfCpu();
}

void Domain::sortAscYearBuilt()
{
    m_sqlite.sortAscYearBuilt();
}

void Domain::sortDescYearBuilt()
{
    m_sqlite.sortDescYearBuilt();
}

void Domain::sortAscTypeOfCpu()
{
    m_sqlite.sortAscTypeOfCpu();
}

void Domain::sortDescTypeOfCpu()
{
    m_sqlite.sortDescTypeOfCpu();
}
