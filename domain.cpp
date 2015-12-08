#include "domain.h"
#include "person.h"
#include "computers.h"
#include "comp_pers.h"
#include <algorithm>

Domain::Domain()    //Sjálfgefni smiðurinn fyrir domain klasann.
{

}

//Býr til eintak af persónu.
void Domain::createPerson(Person p)
{
    m_sqlite.addData(p);
}

//Býr til eintak af tölvu.
void Domain::createComputer(Computers c)
{
    m_sqlite.addComputer(c);
}

//Sækir personlist úr sqlite og skilar honum.
vector<Person> Domain::getList()
{
    return m_sqlite.getPersonList();
}

//Sækir computerlist úr sqlite og skilar honum.
vector<Computers> Domain::getComputerList()
{
    return m_sqlite.getComputerList();
}

//Sækir lista af persónum fyrir e-a tölvu.
string Domain::getPersList(int pId)
{
    vector<Comp_pers> pList = m_sqlite.getLinkedPerson(pId);
    string sPersons = "";
    for(unsigned int i = 0; i < pList.size(); i++)
    {
        if (i>0)
            sPersons += ", ";
        Person pers = findPersonById(pList[i].getPersonID());
        sPersons += pers.getName();
    }
    return sPersons;
}

//Sækir lista af tölvum fyrir e-a persónu.
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
{
    return m_sqlite.searchComputers(search);
}

//Finnur og skilar persónu út frá id.
Person Domain::findPersonById(int cID)
{
    vector<Person> list = m_sqlite.getPersonList();
    Person retPers;
    for(unsigned int i = 0; i < list.size(); i++)
    {
        if(list[i].getId()==cID)
        {
            retPers = list[i];
            break;
        }
    }
    return retPers;
}

//Finnur og skilar tölvu út frá id.
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

//Býr til tengingu milli persónu og tölvu.
void Domain::createRelation(int computerID, int personID)
{
    m_sqlite.addRelation(computerID, personID);
}

// ------------------SORT-FÖLL-OG-UPPRAÐANIR------------------

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
