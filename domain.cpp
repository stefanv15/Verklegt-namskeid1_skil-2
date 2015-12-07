#include "domain.h"
#include "person.h"
#include "computers.h"
#include "comp_pers.h"
//#include "datalayer.h"
//#include <ctype.h>
//#include <string>
#include <algorithm>

<<<<<<< HEAD
Domain::Domain()    //Sjálfgefni smiðurinn fyrir domain klasann.
=======
//Sjálfgefni smiðurinn fyrir domain klasann.
Domain::Domain()
>>>>>>> 526ed041765fd279637b4377dd71b5e016824a28
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
{                                                       // vector af persónum sem fundust.
    vector<Person> list = m_datalayer.getPersonList();
    vector<Person> returnList;

    for(unsigned int i = 0; i < list.size(); i++)
    {
        if(list[i].getName().find(search, 0)!= string::npos)
            returnList.push_back(list[i]);
    }
    return returnList;
}

<<<<<<< HEAD
vector<Computers> Domain::searchComputer(string search)   //Leitar af persónu í lista og skilar
{                                                       // vector af persónum sem fundust.
=======
vector<Computers> Domain::searchComputer(string search)   // Leitar af persónu í lista og skilar
{                                                         // vector af persónum sem fundust.
>>>>>>> 526ed041765fd279637b4377dd71b5e016824a28
    vector<Computers> list = m_datalayer.getComputerList();
    vector<Computers> returnList;

    for(unsigned int i = 0; i < list.size(); i++)
    {
        if(list[i].getNameOfCpu().find(search, 0)!= string::npos)
            returnList.push_back(list[i]);
    }
    return returnList;
}

<<<<<<< HEAD
Computers Domain::findComputerById(int cID) // Leitar af tölvu í lista og skilar henni
=======
Computers Domain::findComputerById(int cID)               // Leitar af tölvu í lista og skilar henni
>>>>>>> 526ed041765fd279637b4377dd71b5e016824a28
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

void Domain::removeScientist(int input)   //Leitar af persónu í lista og skilar
{                                                       // vector án persónum sem leitar var af.
    return m_datalayer.removeScientist(input);
}

void Domain::removeComputer(int input)   //Leitar af persónu í lista og skilar
{                                                       // vector án persónum sem leitar var af.
    return m_datalayer.removeComputer(input);
}

bool compareName(Person& name1, Person& name2)  //Hjálparfall fyrir Sortföllin.
{
    return name1.getName() < name2.getName();
}

vector<Person> Domain::sortList(vector<Person> listOfPersons)   //Raðar upp lista af persónum í stafrófsröð.
{
    sort(listOfPersons.begin(), listOfPersons.end(), compareName);
    return listOfPersons;
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
