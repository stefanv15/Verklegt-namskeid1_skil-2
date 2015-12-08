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
    //Opnunarskilaboð til notanda.
    programInfo();

    while(true)
    {
        mainMenu();
        int numb;
        cin >> numb;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
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
                showListPerson();
                break;
            }
            case 4:
            {
                showListComputer();
                break;
            }
            case 5:
            {
                searchSci();
                break;
            }
            case 6:
            {
                searchComp();
                break;
            }
            case 7:
            {
                int computerID;
                int personID;
                printListComputers(m_domain.getComputerList()); //breyta
                cout << "Please select a computer to relate to a computer scientist: " << endl;
                cin >> computerID;
                printColumnListPerson(m_domain.getList());
                cout << "Please select a computer scientist to relate to the selected computer: " << endl;
                cin >> personID;
                m_domain.createRelation(computerID, personID);
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
void Interface::mainMenu() const
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

    /*while(pick != 'A' || pick != 'a' || pick != 'S' || pick != 's' || pick != 'L' || pick != 'L' || pick != 'Q' || pick != 'q')
    {
        cout << "The input you entered is not a valid option. Pick again!" << endl;
        mainMenu();
    }*/

    if(pick == 'A' || pick == 'a')
    {
        system("cls");
        programInfo();
        cout << endl;
        cout << "-------------- MAIN MENU --------------" << endl;
        cout << "                                       " << endl;
        cout << "A - Add to list "                        << endl;
        cout << "          1. Scientist  2. Computer  7. Relation" << endl;
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
        cout << "        3. Scientists  4. Computers                " << endl;
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
        cout << "        5. Scientist list  6. Computer list   "       << endl;
        cout << "Q - Quit " << endl;
    }
    if(pick == 'Q' || pick == 'q')
    {
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
    while(gender != "f" && gender != "m") // Villuskilaboð (ef notandi slær inn vitlausann innslátt
    {
        cout << "Invalid gender input!" << endl;
        cout << "Gender (f/m): ";
        cin >> gender;
    }
    cout << "Enter year of birth (yyyy): ";
    cin >> dayOfBirth;
    while(cin.fail() || dayOfBirth < 0 || dayOfBirth > 2015) // Villu tjékk á innslætti dayofbirth
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Invalid year input!" << endl;
        cout << "Enter year of birth (yyyy): ";
        cin >> dayOfBirth;
    }
    cout << "Year of passing (yyyy, Type -1 if scientist is alive): ";
    cin >> dayOfDeath;
    while(cin.fail() || dayOfDeath < -1 || dayOfDeath > 2015) // Villu tjékk á innslætti dayofbirth
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
    while(cin.fail() || year < -1 || year > 2015) // Villu tjékk á innslætti dayofbirth
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Invalid year input!" << endl;
        cout << "Enter year built (yyyy, Type -1 if computer was never built): ";
        cin >> year;
    }
    cout << "Type (a/d/h for analog/digital/hybrid respectively): ";
    cin >> type;
    while(type != "a" && type != "d" && type != "h") // Villuskilaboð (ef notandi slær inn vitlausann innslátt
    {
        cout << "Invalid type input!" << endl;
        cout << "Type (a/d/h for analog/digital/hybrid respectively): ";
        cin >> type;
    }
    cout << "Was the computer built? (y/n): ";
    cin >> built;
    while(built != "y" && built != "n") // Villuskilaboð (ef notandi slær inn vitlausann innslátt
    {
        cout << "Invalid input!" << endl;
        cout << "Was the computer built? (y/n): ";
        cin >> built;
    }
    return Computers(name, year, type, built);
}

//Prentar út upplýsingar um persónur.
void Interface::printListPerson(vector<Person> listOfPersons)
{
    cout << endl;
    cout << "LIST OF COMPUTER SCIENTISTS" << endl;
    cout << "---------------------------" << endl;
    for(unsigned int i = 0; i < listOfPersons.size(); i++)
    {
        cout << "ID: " << listOfPersons[i].getId() << endl;
        cout << "Name: " << listOfPersons[i].getName() << endl;
        cout << "Gender: " << (listOfPersons[i].getGender()=="m"?"Male":"Female") << endl;
        cout << "Born: " << listOfPersons[i].getDayOfBirth() << endl;
        if (listOfPersons[i].getDayOfDeath() > 0)
            cout << "Died: " << listOfPersons[i].getDayOfDeath() << endl;
        string compList = m_domain.getComputerList(listOfPersons[i].getId());
        if(compList.length()>0)
        {
            // Nú viljum við sækja hvaða tölvur tengjast þeim aðila sem við erum að prenta út.
            cout << "Related computers: " << compList << endl;
        }
        cout << "---------------------------" << endl;
    }
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
            // Nú viljum við sækja hvaða tölvur tengjast þeim aðila sem við erum að prenta út.
            cout << compList;
        }
        cout << endl;
    }
    cout << "------------------------------------------------------------------------------" << endl;
}

//Prentar út upplýsingar um tölvur.
void Interface::printListComputers(vector<Computers> listOfComputers)
{
    cout << endl;
    cout << "     LIST OF COMPUTERS     " << endl;
    cout << "---------------------------" << endl;
    for(unsigned int i = 0; i < listOfComputers.size(); i++)
    {
        cout << "ID: " << listOfComputers[i].getId() << endl;
        cout << "Name: " << listOfComputers[i].getNameOfCpu() << endl;
        if (listOfComputers[i].getYearBuilt() > 0)
            cout << "Year built: " << listOfComputers[i].getYearBuilt() << endl;
        if (listOfComputers[i].getTypeOfCpu() == "a")
            cout << "Type: Analog" << endl;
        else if (listOfComputers[i].getTypeOfCpu() == "d")
            cout << "Type: Digital" << endl;
        else
            cout << "Type: Hybrid" << endl;
        cout << "Built?: " << (listOfComputers[i].getWasBuilt()=="y"?"Yes":"No") << endl;
        cout << "---------------------------" << endl;
    }
}

//Sækir upplýsingar og býr til persónu.
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

//Sýnir lista yfir persónur & Sortmenu.
void Interface::showListPerson()
{
    vector<Person> list = m_domain.getList(); // Sækja lista.
    printColumnListPerson(list);

    char sos_ans = listMenu();

    if(sos_ans == 'S' || sos_ans == 's')
    {
        int sort_ans = sortMenu();
        if(sort_ans == 1)
        {
            m_domain.sortAscName();
            printColumnListPerson(list);
        }
        if(sort_ans == 2)
        {
            m_domain.sortDescName();
            printColumnListPerson(list);
        }
        if(sort_ans == 3)
        {
            m_domain.sortGender();
            printColumnListPerson(list);
        }
        if(sort_ans == 4)
        {
            m_domain.sortAscYearOfBirth();
            printColumnListPerson(list);
        }
        if(sort_ans == 5)
        {
            m_domain.sortDescName();
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
        return;
    }
}

//Sýnir lista yfir tölvur. Sortmenu.
void Interface::showListComputer()
{
    vector<Computers> cpulist = m_domain.getComputerList();
    printListComputers(cpulist);

    char sos_ans = listMenu();
    if(sos_ans == 'S' || sos_ans == 's')
    {
        int sort_ans = sortMenu2();
        if(sort_ans == 1)
        {
            m_domain.sortAscNameOfCpu();
            printListComputers(cpulist);
        }
        if(sort_ans == 2)
        {
            m_domain.sortDescNameOfCpu();
            printListComputers(cpulist);
        }
        if(sort_ans == 3)
        {
            m_domain.sortAscYearBuilt();
            printListComputers(cpulist);
        }
        if(sort_ans == 4)
        {
            m_domain.sortDescYearBuilt();
            printListComputers(cpulist);
        }
        if(sort_ans == 5)
        {
            m_domain.sortAscTypeOfCpu();
            printListComputers(cpulist);
        }
        if(sort_ans == 6)
        {
            m_domain.sortDescTypeOfCpu();
            printListComputers(cpulist);
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
        return;
    }
   // sos_ans = listMenu();
}

//Valmynd fyrir Show list.
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

    return answer;
}

// --------------SORTLISTI-OG-SORTFÖLL-FYRIR-PERSON------------ //

//Valmynd fyrir "sort list".
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

//Eyðir persónu úr gagnagrunni.
void Interface::removeScientist()
{
    int remove;
    cout << "Insert ID of the computer scientist you want to remove: ";
    cin >> remove;
    m_domain.removeScientist(remove);
}

//Eyðir tölvu úr gagnagrunni.
void Interface::removeComputer()
{
    int remove;
    cout << "Insert ID of the computer you want to remove: ";
    cin >> remove;
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
        {cout << "\nYour search did not match any scientists!" << endl;}
    else
        printListPerson(searchlist);
}

//Leitar af tölvu.
void Interface::searchComp()
{
    string search;
    cout << "Enter search word: ";
    cin >> search;

    vector<Computers> searchlist = m_domain.searchComputer(search);
    if (searchlist.size() == 0)
        {cout << "\nYour search did not match any computers!" << endl;}
    else
        printListComputers(searchlist);
}

//Valmynd fyrir "sort list hja computers".
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
