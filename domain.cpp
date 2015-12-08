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

bool compareNameTwo(Person& name1, Person& name2)   //Hjálparfall fyrir sortListReverse fallið.
{
    return name1.getName() > name2.getName();
}

vector<Person> Domain::sortListReverse(vector<Person> listOfPersons)    //Raðar upp lista af persónum í öfugri stafrófsröð.

{
    sort(listOfPersons.begin(), listOfPersons.end(), compareNameTwo);
    return listOfPersons;
}
bool compareYear(Person& year1, Person& year2)  //Hjálparfall fyrir sortListYear fallið.
{
    return year1.getDayOfBirth() < year2.getDayOfBirth();
}

vector<Person> Domain::sortListYear(vector<Person> listOfPersons)   //Raðar upp persónum eftir fæðingarári.

{
    sort(listOfPersons.begin(), listOfPersons.end(), compareYear);
    return listOfPersons;
}
bool compareYearTwo(Person& year1, Person& year2) //Hjálpar fall fyrir sortListYearReverse fallið.
{
    return year1.getDayOfBirth() > year2.getDayOfBirth();
}

vector<Person> Domain::sortListYearReverse(vector<Person> listOfPersons)    //Raðar upp persónum eftir öfugu fæðingarári (yngsti efst)
{
    sort(listOfPersons.begin(), listOfPersons.end(), compareYearTwo);
    return listOfPersons;
}
