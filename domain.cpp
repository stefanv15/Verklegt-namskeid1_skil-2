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

//Býr til computer.
void Domain::createComputer(Computers c)
{
    m_datalayer.addComputer(c);
}

//Nær í personlist úr datalayer og skilar honum.
vector<Person> Domain::getList()
{
    return m_datalayer.getPersonList();
}

//Sækir ???????????????????????????????????????????????????????????????????????????????????
vector<Computers> Domain::getComputerList()
{
    return m_datalayer.getComputerList();
}

//Sækir????????????????????????????????????????????????????????????????????????????????????
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

//Nær í savedata fallið úr domain og skilar því.
void Domain::saveAllData()
{
    m_datalayer.saveData();
}

//Leitar af persónu í lista og skilar honum.
vector<Person> Domain::searchScientist(string search)

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

//Leitar af persónu í lista og skilar honum.
vector<Computers> Domain::searchComputer(string search)
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

//Leitar af tölvu í lista og skilar henni.
Computers Domain::findComputerById(int cID)

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

//Býr til tengingu milli pers og computer.
void Domain::createRelation(int computerID, int personID)
{
    m_datalayer.addRelation(computerID, personID);
}

//Leitar af persónu í lista og skilar
void Domain::removeScientist(int input)
{                                                       // vector án persónum sem leitar var af.
    return m_datalayer.removeScientist(input);
}

//Leitar af persónu í lista og skilar henni.
void Domain::removeComputer(int input)

{                                                       // vector án persónum sem leitar var af.
    return m_datalayer.removeComputer(input);
}

// ------------------SORT-FÖLL-OG-UPPRAÐANIR------------------

//Raðar upp lista af persónum í stafrófsröð.
vector<Person> Domain::getPersonlistByName()
{
    return m_datalayer.getPersonListByName();
}

//Hjálparfall fyrir sortListReverse fallið.
bool compareNameTwo(Person& name1, Person& name2)
{
    return name1.getName() > name2.getName();
}

//Raðar upp lista af persónum í öfugri stafrófsröð.
vector<Person> Domain::sortListReverse(vector<Person> listOfPersons)
{
    sort(listOfPersons.begin(), listOfPersons.end(), compareNameTwo);
    return listOfPersons;
}

//Hjálparfall fyrir sortListYear fallið.
bool compareYear(Person& year1, Person& year2)
{
    return year1.getDayOfBirth() < year2.getDayOfBirth();
}

//Raðar upp persónum eftir fæðingarári.
vector<Person> Domain::sortListYear(vector<Person> listOfPersons)

{
    sort(listOfPersons.begin(), listOfPersons.end(), compareYear);
    return listOfPersons;
}

//Hjálpar fall fyrir sortListYearReverse fallið.
bool compareYearTwo(Person& year1, Person& year2)
{
    return year1.getDayOfBirth() > year2.getDayOfBirth();
}

//Raðar upp persónum eftir öfugu fæðingarári (yngsti efst).
vector<Person> Domain::sortListYearReverse(vector<Person> listOfPersons)
{
    sort(listOfPersons.begin(), listOfPersons.end(), compareYearTwo);
    return listOfPersons;
}
