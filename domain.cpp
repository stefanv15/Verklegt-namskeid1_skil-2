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

//Býr til computer.
void Domain::createComputer(Computers c)
{
    m_sqlite.addComputer(c);
}

//Nær í personlist úr datalayer og skilar honum.
vector<Person> Domain::getList()
{
    return m_sqlite.getPersonList();
}

//Sækir ???????????????????????????????????????????????????????????????????????????????????
vector<Computers> Domain::getComputerList()
{
    return m_sqlite.getComputerList();
}

//Sækir????????????????????????????????????????????????????????????????????????????????????
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

//Nær í savedata fallið úr domain og skilar því.
void Domain::saveAllData()
{
    m_sqlite.saveData();
}

//Leitar af persónu í lista og skilar honum.
vector<Person> Domain::searchScientist(string search)

{
    return m_sqlite.searchPersons(search);
}

//Leitar af persónu í lista og skilar honum.
vector<Computers> Domain::searchComputer(string search)
{                                                         // vector af persónum sem fundust.
    return m_sqlite.searchComputers(search);
}

//Leitar af tölvu í lista og skilar henni.
Computers Domain::findComputerById(int cID)

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


//Býr til tengingu milli pers og computer.
void Domain::createRelation(int computerID, int personID)
{
    m_sqlite.addRelation(computerID, personID);
}


// ------------------SORT-FÖLL-OG-UPPRAÐANIR------------------


vector<Person> Domain::getPersonlistByName()
{
    return m_sqlite.getPersonListByName();
}
//Raðar upp lista af perónum í stafrófsröð.
vector<Person> Domain::sortAscName()
{
    return  m_sqlite.sortAscName();
}
//Raðar upp lista af perónum í öfugri stafrófsröð.
vector<Person> Domain::sortDescName()
{
    return m_sqlite.sortDescName();
}
//Raðar upp lista af persónum eftir kyni.
vector<Person> Domain::sortGender()
{
    return m_sqlite.sortGender();
}
//Raðar upp lista af persónum eftir fæðingarári 1-10.
vector<Person> Domain::sortAscYearOfBirth()
{
    return m_sqlite.sortAscYearOfBirth();
}
//Raðar upp lista af persónum eftir fæðingarári 10-1.
vector<Person> Domain::sortDescYearOfBirth()
{
    return m_sqlite.sortDescYearOfBirth();
}
//Raðar upp lista af tölvum eftir nafni á tölvu í stafrófsröð.
vector<Computers> Domain::sortAscNameOfCpu()
{
    return m_sqlite.sortAscNameOfCpu();
}
//Raðar upp lista af tölvum eftir nafni á tölvu í öfugri stafrófsröð.
vector<Computers> Domain::sortDescNameOfCpu()
{
    return m_sqlite.sortDescNameOfCpu();
}
//Raðar upp lista af tölvum eftir byggingarári 1-10.
vector<Computers> Domain::sortAscYearBuilt()
{
    return m_sqlite.sortAscYearBuilt();
}
//Raðar upp lista af tölvum eftir byggingarári 10-1.
vector<Computers> Domain::sortDescYearBuilt()
{
    return m_sqlite.sortDescYearBuilt();
}
//Raðar upp lista af tölvum eftir týpunafni í stafrófsröð.
vector<Computers> Domain::sortAscTypeOfCpu()
{
    return m_sqlite.sortAscTypeOfCpu();
}
//Raðar upp lista af tölvum eftir týpunafni í öfugri stafrófsröð.
vector<Computers> Domain::sortDescTypeOfCpu()
{
    return m_sqlite.sortDescTypeOfCpu();
}
