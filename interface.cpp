#include "interface.h"
#include <iostream>
#include <iomanip>
#include <string>

Interface::Interface()
{

}

//Keyrir forritið.
void Interface::start()
{
    programInfo();

    while(true)
    {
        mainMenu();
        int numb;
        cin >> numb;
        while(cin.fail() || numb > 7 || numb < 1)
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout << "Invalid input! Pick again: ";
            cin >> numb;
        }

        switch(numb)
        {
            case 1:
            {
                addPerson();
                break;
            }           
            case 2:
            {
                addComputer();
                break;
            }
            case 3:
            {
                addRelation();
                break;
            }
            case 4:
            {
                showListPerson();
                break;
            }
            case 5:
            {
                showListComputer();
                break;
            }
            case 6:
            {
                searchSci();
                break;
            }
            case 7:
            {
                searchComp();
                break;
            }
        }
    }
    m_domain.saveAllData();
    return;
}

//Opnunarskilaboð til notanda.
void Interface::programInfo() const
{
    cout << "****************************************************" << endl;
    cout << "*                    WELCOME                       *" << endl;
    cout << "*  This program was made by the group \"22\"         *" << endl;
    cout << "*  Students from Reykjavik University              *" << endl;
    cout << "*                                                  *" << endl;
    cout << "*  #Add        #Sort        #Search        #Link   *" << endl;
    cout << "****************************************************" << endl;
}

//Aðalvalmynd.
void Interface::mainMenu()
{
    char pick;
    cout << endl;
    cout << "-- MAIN MENU -- " << endl;
    cout << "                " << endl;
    cout << "A - Add to list " << endl;
    cout << "S - Show list   " << endl;
    cout << "L - Search list " << endl;
    cout << "Q - Quit   " << endl;
    cin >> pick;

    while(pick != 'A' && pick != 'a' && pick != 'S' && pick != 's' && pick != 'L' && pick != 'l' && pick != 'Q' && pick != 'q')
    {
        cout << "The input you entered is not a valid option. Pick again!" << endl;
        cout << endl;
        cout << "-- MAIN MENU -- " << endl;
        cout << "                " << endl;
        cout << "A - Add to list " << endl;
        cout << "S - Show list   " << endl;
        cout << "L - Search list " << endl;
        cout << "Q - Quit   " << endl;
        cin >> pick;
    }
    if(pick == 'A' || pick == 'a')
    {
        system("cls");
        programInfo();
        cout << endl;
        cout << "-------------- MAIN MENU --------------" << endl;
        cout << "                                       " << endl;
        cout << "A - Add to list "                        << endl;
        cout << "          1. Scientist  2. Computer  3. Relation" << endl;
        cout << "S - Show list "                          << endl;
        cout << "L - Search list "                        << endl;
        cout << "E - Quit "                               << endl;
    }
    if(pick == 'S' || pick == 's')
    {
        system("cls");
        programInfo();
        cout << endl;
        cout << "-------------- MAIN MENU --------------             "<< endl;
        cout << "                                                    "<< endl;
        cout << "A - Add to list "                                    << endl;
        cout << "S - Show list "                                      << endl;
        cout << "        4. Scientists  5. Computers                " << endl;
        cout << "L - Search list "                                    << endl;
        cout << "Q - Quit " << endl;
    }
    if(pick == 'L' || pick == 'l')
    {
        system("cls");
        programInfo();
        cout << endl;
        cout << "-------------- MAIN MENU --------------"              << endl;
        cout << "                                       "              << endl;
        cout << "A - Add to list " << endl;
        cout << "S - Show list " << endl;
        cout << "L - Search list " << endl;
        cout << "        6. Scientist list  7. Computer list   "       << endl;
        cout << "Q - Quit " << endl;
    }
    if(pick == 'Q' || pick == 'q')
    {
        m_domain.saveAllData();
        exit(1);
    }
}

//Inntak fyrir upplýsingar um persónu.
Person Interface::getPersonInfo()
{
    string name;
    string gender;
    int dayOfBirth;
    int dayOfDeath;

    cin.ignore();

    cout << "Name of computer scientist: ";
    getline(cin, name);
    cout << "Gender (f/m): ";
    cin >> gender;
    while(gender != "f" && gender != "m")
    {
        cout << "Invalid gender input!" << endl;
        cout << "Gender (f/m): ";
        cin >> gender;
    }
    cout << "Enter year of birth (yyyy): ";
    cin >> dayOfBirth;
    while(cin.fail() || dayOfBirth < 0 || dayOfBirth > 2015)
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Invalid year input!" << endl;
        cout << "Enter year of birth (yyyy): ";
        cin >> dayOfBirth;
    }
    cout << "Year of passing (yyyy, Type -1 if scientist is alive): ";
    cin >> dayOfDeath;
    while(cin.fail() || dayOfDeath < -1 || dayOfDeath > 2015)
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Invalid year input!" << endl;
        cout << "Year of passing (yyyy, Type -1 if scientist is alive): ";
        cin >> dayOfDeath;
    }
    return Person(name, gender, dayOfBirth, dayOfDeath);
}

//Inntak fyrir upplýsingar um tölvu.
Computers Interface::getComputerInfo()
{
    string name;
    int year;
    string type;
    string built;

    cin.ignore();

    cout << "Name of computer: ";
    getline(cin, name);
    cout << "Enter year built (yyyy, Type -1 if computer was never built): ";
    cin >> year;
    while(cin.fail() || year < -1 || year > 2015)
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Invalid year input!" << endl;
        cout << "Enter year built (yyyy, Type -1 if computer was never built): ";
        cin >> year;
    }
    cout << "Type (a/d/h for analog/digital/hybrid respectively): ";
    cin >> type;
    while(type != "a" && type != "d" && type != "h")
    {
        cout << "Invalid type input!" << endl;
        cout << "Type (a/d/h for analog/digital/hybrid respectively): ";
        cin >> type;
    }
    cout << "Was the computer built? (y/n): ";
    cin >> built;
    while(built != "y" && built != "n")
    {
        cout << "Invalid input!" << endl;
        cout << "Was the computer built? (y/n): ";
        cin >> built;
    }
    return Computers(name, year, type, built);
}

//Prentar út upplýsingar um persónur.
void Interface::printColumnListPerson(vector<Person> listOfPersons)
{
    cout << endl;
    cout << "LIST OF COMPUTER SCIENTISTS" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "ID\tName\t\t\tGender\tBorn\tDied\tRelated computers" << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    for(unsigned int i = 0; i < listOfPersons.size(); i++)
    {
        cout << listOfPersons[i].getId() << "\t";
        cout << std::left << std::setw(23) << std::setfill(' ') << listOfPersons[i].getName().substr(0,23) << "\t";
        cout << (listOfPersons[i].getGender()=="m"?"Male":"Female")<< "\t";
        cout << listOfPersons[i].getDayOfBirth()<< "\t";
        if (listOfPersons[i].getDayOfDeath() > 0)
            cout << listOfPersons[i].getDayOfDeath();
        cout << "\t";
        string compList = m_domain.getComputerList(listOfPersons[i].getId());
        if(compList.length()>0)
        {
            cout << compList;
        }
        cout << endl;
    }
    cout << "------------------------------------------------------------------------------" << endl;
}

//Prentar út upplýsingar um tölvur.
void Interface::printColumnListComputers(vector<Computers> listOfComputers)
{
    cout << endl;
    cout << "LIST OF COMPUTERS" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "ID\tName of computer\tYear built\tType of computer\t Was built?\tRelated Scientists" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;

    for(unsigned int i = 0; i < listOfComputers.size(); i++)
    {
        cout << listOfComputers[i].getId() << "\t";
        cout << std::left << std::setw(23) << std::setfill(' ') << listOfComputers[i].getNameOfCpu() << "\t";
        if (listOfComputers[i].getYearBuilt() > 0)
            cout << listOfComputers[i].getYearBuilt() << "\t\t";
        if (listOfComputers[i].getTypeOfCpu() == "a")
            cout << "Analog" << "\t\t\t ";
        else if (listOfComputers[i].getTypeOfCpu() == "d")
            cout << "Digital" << "\t\t\t ";
        else
            cout << "Hybrid" << "\t\t\t ";
        cout << (listOfComputers[i].getWasBuilt()=="y"?"Yes\t\t":"No\t\t");
        string persList = m_domain.getPersList(listOfComputers[i].getId());
        if(persList.length()>0)
        {
            cout << persList;
        }
        cout << endl;
    }
    cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

//Sækir upplýsingar og býr til eintak persónu.
void Interface::addPerson()
{
    Person p = getPersonInfo();
    m_domain.createPerson(p);
}

//Sækir upplýsingar og býr til eintak af tölvu.
void Interface::addComputer()
{
    Computers c = getComputerInfo();
    m_domain.createComputer(c);
}

//Tengir saman tölvu og persónu.
void Interface::addRelation()
{
    int computerID;
    int personID;
    printColumnListComputers(m_domain.getComputerList());

    cout << "Please select a computer ID to relate to a computer scientist: " << endl;
    cin >> computerID;
    while(cin.fail() || computerID < 0)
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Invalid input! Select again: ";
        cin >> computerID;
    }
    printColumnListPerson(m_domain.getList());
    cout << "Please select a computer scientist ID to relate to the selected computer: " << endl;
    cin >> personID;
    while(cin.fail() || personID < 0)
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Invalid input! Select again: ";
        cin >> personID;
    }
    m_domain.createRelation(computerID, personID);
}

//Sýnir lista yfir persónur, listmenu & sortmenu.
void Interface::showListPerson()
{
    vector<Person> list = m_domain.getList();
    printColumnListPerson(list);

    char sos_ans = listMenu();

    if(sos_ans == 'S' || sos_ans == 's')
    {
        int sort_ans = sortMenu();
        if(sort_ans == 1)
        {
            list = m_domain.sortAscName();
            printColumnListPerson(list);
        }
        if(sort_ans == 2)
        {
            list = m_domain.sortDescName();
            printColumnListPerson(list);
        }
        if(sort_ans == 3)
        {
            list = m_domain.sortGender();
            printColumnListPerson(list);
        }
        if(sort_ans == 4)
        {
            list = m_domain.sortAscYearOfBirth();
            printColumnListPerson(list);
        }
        if(sort_ans == 5)
        {
            list = m_domain.sortDescYearOfBirth();
            printColumnListPerson(list);
        }
    }
    if(sos_ans == 'R' || sos_ans == 'r')
    {
        removeScientist();
        return;
    }
    if(sos_ans == 'E' || sos_ans == 'e')
    {
        system("cls");
        programInfo();
        return;
    }
}

//Sýnir lista yfir tölvur, listmenu og sortmenu2.
void Interface::showListComputer()
{
    vector<Computers> cpulist = m_domain.getComputerList();
    printColumnListComputers(cpulist);

    char sos_ans = listMenu();

    if(sos_ans == 'S' || sos_ans == 's')
    {
        int sort_ans = sortMenu2();
        if(sort_ans == 1)
        {
            cpulist = m_domain.sortAscNameOfCpu();
            printColumnListComputers(cpulist);
        }
        if(sort_ans == 2)
        {
            cpulist = m_domain.sortDescNameOfCpu();
            printColumnListComputers(cpulist);
        }
        if(sort_ans == 3)
        {
            cpulist = m_domain.sortAscYearBuilt();
            printColumnListComputers(cpulist);
        }
        if(sort_ans == 4)
        {
            cpulist = m_domain.sortDescYearBuilt();
            printColumnListComputers(cpulist);
        }
        if(sort_ans == 5)
        {
            cpulist = m_domain.sortAscTypeOfCpu();
            printColumnListComputers(cpulist);
        }
        if(sort_ans == 6)
        {
            cpulist = m_domain.sortDescTypeOfCpu();
            printColumnListComputers(cpulist);
        }
    }
    if(sos_ans == 'R' || sos_ans == 'r')
    {
        removeComputer();
        return;
    }
    if(sos_ans == 'E' || sos_ans == 'e')
    {
        system("cls");
        programInfo();
        return;
    }
}

//Valmynd fyrir lista.
char Interface::listMenu() const
{
    char answer;

    cout << endl;
    cout << "       LIST MENU      " << endl;
    cout << "       ---------      " << endl;
    cout << "S - Sort list" << endl;
    cout << "R - Remove from list" << endl;
    cout << "E - Return to main menu" << endl;
    cin >> answer;

    while(answer != 's' && answer != 'S' && answer != 'r' && answer != 'R' && answer != 'e' && answer != 'E')
    {
        cout << "Invalid input!" << endl;
        cout << endl;
        cout << "       LIST MENU      " << endl;
        cout << "       ---------      " << endl;
        cout << "S - Sort list" << endl;
        cout << "R - Remove from list" << endl;
        cout << "E - Return to main menu" << endl;
        cin >> answer;
    }
    return answer;
}

//Valmynd fyrir uppröðun persóna.
int Interface::sortMenu() const
{
    int answer;
    cout << "--------------------------------" << endl;
    cout << "Sort by?" << endl;
    cout << "1 - In alphabetical order " << endl;
    cout << "2 - In reverse alphabetical order " << endl;
    cout << "3 - Gender " << endl;
    cout << "4 - Year of birth " << endl;
    cout << "5 - Reverse year of birth " << endl;
    cin >> answer;
    while(cin.fail() || answer < 1 || answer > 5)
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "The input you entered is not a valid option. Pick again!" << endl;
        cout << "Sort by?" << endl;
        cout << "1 - In alphabetical order " << endl;
        cout << "2 - In reverse alphabetical order " << endl;
        cout << "3 - Gender " << endl;
        cout << "4 - Year of birth " << endl;
        cout << "5 - Reverse year of birth " << endl;
        cin >> answer;
    }
    return answer;
}

//Valmynd fyrir uppröðun tölva.
int Interface::sortMenu2() const
{
    int answer;
    cout << "--------------------------------" << endl;
    cout << "Sort by?" << endl;
    cout << "1 - Name of computer" << endl;
    cout << "2 - Reverse name of computer " << endl;
    cout << "3 - Year built " << endl;
    cout << "4 - Reverse year built " << endl;
    cout << "5 - Type of computer" << endl;
    cout << "6 - Reverse type of computer " << endl;
    cin >> answer;
    while(cin.fail() || answer < 1 || answer > 6)
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "The input you entered is not a valid option. Pick again!" << endl;
        cout << "Sort by?" << endl;
        cout << "1 - Name of computer" << endl;
        cout << "2 - Reverse name of computer " << endl;
        cout << "3 - Year built " << endl;
        cout << "4 - Reverse year built " << endl;
        cout << "5 - Type of computer" << endl;
        cout << "6 - Reverse type of computer " << endl;
        cin >> answer;
    }
    return answer;
}

//Eyðir persónu endanlega úr gagnagrunni.
void Interface::removeScientist()
{
    int remove;
    cout << "Insert ID of the computer scientist you want to remove: ";
    cin >> remove;
    while(cin.fail() || remove < 1)
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Invalid input! Insert again:";
        cin >> remove;
    }
    m_domain.removeScientist(remove);
}

//Eyðir tölvu úr endanlega gagnagrunni.
void Interface::removeComputer()
{
    int remove;
    cout << "Insert ID of the computer you want to remove: ";
    cin >> remove;
    while(cin.fail() || remove < 1)
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Invalid input! Insert again:";
        cin >> remove;
    }
    m_domain.removeComputer(remove);
}

//Leitar af persónu.
void Interface::searchSci()
{
    string search;
    cout << "Enter search word: ";
    cin >> search;

    vector<Person> searchlist = m_domain.searchScientist(search);
    if (searchlist.size() == 0)
        cout << "\nYour search did not match any scientists!" << endl;
    else
        printColumnListPerson(searchlist);
}

//Leitar af tölvu.
void Interface::searchComp()
{
    string search;
    cout << "Enter search word: ";
    cin >> search;

    vector<Computers> searchlist = m_domain.searchComputer(search);
    if (searchlist.size() == 0)
        cout << "\nYour search did not match any computers!" << endl;
    else
        printColumnListComputers(searchlist);
}
