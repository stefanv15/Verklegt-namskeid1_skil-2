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

<<<<<<< HEAD
//Býr til tengingu milli pers og computer.
=======
//Leitar af persónu í lista eftir ID og fjarlægir hana endanlega úr gagnagrunninum.
void Domain::removeScientist(int input)
{
    return m_datalayer.removeScientist(input);
}

//Leitar af tölvu í lista eftir ID og fjarlægir hana endanlega úr gagnagrunninum.
void Domain::removeComputer(int input)
{
    return m_datalayer.removeComputer(input);
}

>>>>>>> 665a40f0bb7086337029b7471abdbb24f15521a6
void Domain::createRelation(int computerID, int personID)
{
    m_datalayer.addRelation(computerID, personID);
}

<<<<<<< HEAD
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
=======
vector<Person> Domain::getPersonListByName()            //Raðar upp lista af persónum í stafrófsröð.
{
    return m_datalayer.getPersonListByName();
}

void Domain::sortAscName()
{
    m_datalayer.sortAscName();
}

void Domain::sortDescName()
>>>>>>> 665a40f0bb7086337029b7471abdbb24f15521a6
{
    m_datalayer.sortDescName();
}

<<<<<<< HEAD
//Hjálparfall fyrir sortListReverse fallið.
bool compareNameTwo(Person& name1, Person& name2)
=======
void Domain::sortGender()
>>>>>>> 665a40f0bb7086337029b7471abdbb24f15521a6
{
    m_datalayer.sortGender();
}

<<<<<<< HEAD
//Raðar upp lista af persónum í öfugri stafrófsröð.
vector<Person> Domain::sortListReverse(vector<Person> listOfPersons)
=======
void Domain::sortAscYearOfBirth()
{
    m_datalayer.sortAscYearOfBirth();
}

void Domain::sortDescYearOfBirth()
>>>>>>> 665a40f0bb7086337029b7471abdbb24f15521a6
{
    m_datalayer.sortDescYearOfBirth();
}

<<<<<<< HEAD
//Hjálparfall fyrir sortListYear fallið.
bool compareYear(Person& year1, Person& year2)
=======
void Domain::sortAscNameOfCpu()
>>>>>>> 665a40f0bb7086337029b7471abdbb24f15521a6
{
    m_datalayer.sortAscNameOfCpu();
}

<<<<<<< HEAD
//Raðar upp persónum eftir fæðingarári.
vector<Person> Domain::sortListYear(vector<Person> listOfPersons)
=======
void Domain::sortDescNameOfCpu()
{
    m_datalayer.sortDescNameOfCpu();
}
>>>>>>> 665a40f0bb7086337029b7471abdbb24f15521a6

void Domain::sortAscYearBuilt()
{
    m_datalayer.sortAscYearBuilt();
}

<<<<<<< HEAD
//Hjálpar fall fyrir sortListYearReverse fallið.
bool compareYearTwo(Person& year1, Person& year2)
=======
void Domain::sortDescYearBuilt()
{
    m_datalayer.sortDescYearBuilt();
}

void Domain::sortAscTypeOfCpu()
>>>>>>> 665a40f0bb7086337029b7471abdbb24f15521a6
{
    m_datalayer.sortAscTypeOfCpu();
}

<<<<<<< HEAD
//Raðar upp persónum eftir öfugu fæðingarári (yngsti efst).
vector<Person> Domain::sortListYearReverse(vector<Person> listOfPersons)
=======
void Domain::sortDescTypeOfCpu()
>>>>>>> 665a40f0bb7086337029b7471abdbb24f15521a6
{
    m_datalayer.sortDescTypeOfCpu();
}
