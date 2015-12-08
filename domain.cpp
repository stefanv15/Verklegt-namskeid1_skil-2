#include "domain.h"
#include "person.h"
#include "computers.h"
#include "comp_pers.h"
//#include "datalayer.h"
//#include <ctype.h>
//#include <string>
#include <algorithm>

//Sjálfgefni smiðurinn fyrir domain klasann.
Domain::Domain()
{

}

//Býr til eintak af persónu og vistar.
void Domain::createPerson(Person p)
{
    m_datalayer.addData(p);
}

void Domain::createComputer(Computers c)
{
    m_datalayer.addComputer(c);
}

vector<Person> Domain::getList()                        //Nær í personlist úr datalayer og skilar honum.
{
    return m_datalayer.getPersonList();
}

vector<Computers> Domain::getComputerList()
{
    return m_datalayer.getComputerList();
}

string Domain::getComputerList(int pId)
{
    vector<Comp_pers> cpList = m_datalayer.getLinkedComputers(pId);
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
    m_datalayer.saveData();
}

vector<Person> Domain::searchScientist(string search)   //Leitar af persónu í lista og skilar
{
    return m_datalayer.searchPersons(search);
    /* geyma
    // vector af persónum sem fundust.
    vector<Person> list = m_datalayer.getPersonList();
    vector<Person> returnList;

    for(unsigned int i = 0; i < list.size(); i++)
    {
        if(list[i].getName().find(search, 0)!= string::npos)
            returnList.push_back(list[i]);
    }
    return returnList;*/
}

vector<Computers> Domain::searchComputer(string search)   // Leitar af persónu í lista og skilar
{                                                         // vector af persónum sem fundust.
    vector<Computers> list = m_datalayer.getComputerList();
    vector<Computers> returnList;

    for(unsigned int i = 0; i < list.size(); i++)
    {
        if(list[i].getNameOfCpu().find(search, 0)!= string::npos)
            returnList.push_back(list[i]);
    }
    return returnList;
}

Computers Domain::findComputerById(int cID)               // Leitar af tölvu í lista og skilar henni
{
    vector<Computers> list = m_datalayer.getComputerList();
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

void Domain::createRelation(int computerID, int personID)
{
    m_datalayer.addRelation(computerID, personID);
}

void Domain::removeScientist(int input)                 //Leitar af persónu í lista og skilar
{                                                       // vector án persónum sem leitar var af.
    return m_datalayer.removeScientist(input);
}

void Domain::removeComputer(int input)                  //Leitar af persónu í lista og skilar
{                                                       // vector án persónum sem leitar var af.
    return m_datalayer.removeComputer(input);
}

vector<Person> Domain::getPersonlistByName()            //Raðar upp lista af persónum í stafrófsröð.
{
    return m_datalayer.getPersonListByName();
}

void Domain::sortAscName()
{
    m_datalayer.sortAscName();
}

void Domain::sortDescName()
{
    m_datalayer.sortDescName();
}

void Domain::sortGender()
{
    m_datalayer.sortGender();
}

void Domain::sortAscYearOfBirth()
{
    m_datalayer.sortAscYearOfBirth();
}

void Domain::sortDescYearOfBirth()
{
    m_datalayer.sortDescYearOfBirth();
}

void Domain::sortAscNameOfCpu()
{
    m_datalayer.sortAscNameOfCpu();
}

void Domain::sortDescNameOfCpu()
{
    m_datalayer.sortDescNameOfCpu();
}

void Domain::sortAscYearBuilt()
{
    m_datalayer.sortAscYearBuilt();
}

void Domain::sortDescYearBuilt()
{
    m_datalayer.sortDescYearBuilt();
}

void Domain::sortAscTypeOfCpu()
{
    m_datalayer.sortAscTypeOfCpu();
}

void Domain::sortDescTypeOfCpu()
{
    m_datalayer.sortDescTypeOfCpu();
}
