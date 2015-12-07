#include "worker.h"
#include "person.h"
#include "computers.h"
#include "comp_pers.h"
//#include "datalayer.h"
//#include <ctype.h>
//#include <string>
#include <algorithm>

Worker::Worker()            //Sjálfgefni smiðurinn fyrir Worker klasann.
{

}

void Worker::createPerson(Person p)     // Býr til eintak af persónu og vistar.
{
    m_datalayer.addData(p);
}

void Worker::createComputer(Computers c)
{
    m_datalayer.addComputer(c);
}

vector<Person> Worker::getList()        //Nær í personlist úr datalayer og skilar honum.
{
    return m_datalayer.getPersonList();
}

vector<Computers> Worker::getComputerList()
{
    return m_datalayer.getComputerList();
}

string Worker::getComputerList(int pId)
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

void Worker::saveAllData()              //Nær í savedata fallið úr datalayer og skilar því.
{
    m_datalayer.saveData();
}

vector<Person> Worker::searchScientist(string search)   // Leitar af persónu í lista og skilar
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

vector<Computers> Worker::searchComputer(string search)   // Leitar af persónu í lista og skilar
{                                                       // vector af persónum sem fundust.
    vector<Computers> list = m_datalayer.getComputerList();
    vector<Computers> returnList;

    for(unsigned int i = 0; i < list.size(); i++)
    {
        if(list[i].getNameOfCpu().find(search, 0)!= string::npos)
            returnList.push_back(list[i]);
    }
    return returnList;
}

Computers Worker::findComputerById(int cID)             // Leitar af tölvu í lista og skilar henni
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

vector<Person> Worker::removeScientist(string remove)   // Leitar af persónu í lista og skilar
{                                                       // vector án persónum sem leitar var af.
    vector<Person> list = m_datalayer.getPersonList();
    vector<Person> returnList;

    for(unsigned int i = 0; i < list.size(); i++)
    {
        if(list[i].getName().find(remove, 0) == string::npos)
            returnList.push_back(list[i]);
    }
    return returnList;
}



bool compareName(Person& name1, Person& name2)              //Hjálparfall fyrir Sortföllin.
{
    return name1.getName() < name2.getName();
}


vector<Person> Worker::sortList(vector<Person> listOfPersons)
{
    sort(listOfPersons.begin(), listOfPersons.end(), compareName);
    return listOfPersons;
}

bool compareNameTwo(Person& name1, Person& name2)
{
    return name1.getName() > name2.getName();
}

vector<Person> Worker::sortListReverse(vector<Person> listOfPersons)
{
    sort(listOfPersons.begin(), listOfPersons.end(), compareNameTwo);
    return listOfPersons;
}
bool compareYear(Person& year1, Person& year2)
{
    return year1.getDayOfBirth() < year2.getDayOfBirth();
}

vector<Person> Worker::sortListYear(vector<Person> listOfPersons)
{
    sort(listOfPersons.begin(), listOfPersons.end(), compareYear);
    return listOfPersons;
}
bool compareYearTwo(Person& year1, Person& year2)
{
    return year1.getDayOfBirth() > year2.getDayOfBirth();
}

vector<Person> Worker::sortListYearReverse(vector<Person> listOfPersons)
{
    sort(listOfPersons.begin(), listOfPersons.end(), compareYearTwo);
    return listOfPersons;
}
