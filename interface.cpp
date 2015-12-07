#include "interface.h"

Interface::Interface()
{

}

void Interface::start()    //Keyrir forritið.
{
    programInfo();     //Opnunarskilaboð til notanda.
    int numb;

    while(true)
    {
        mainMenu();
        cin >> numb;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
        }
        if(numb < 1 || numb > 6)
        {
            cout << "The input you entered is not a valid option. Pick again!" << endl;     //Villuskilaboð fyrir valmynd.
        }
        switch(numb)
        {
            case 1:
            {
                Person p = getPersonInfo(); //sækja upplýsingar um persónu.
                m_domain.createPerson(p);   //býr til eintak af persónu.
                break;
            }           
            case 2:
            {
                Computers c = getComputerInfo(); //Sækja upplýsingar um tölvu.
                m_domain.createComputer(c); // Býr til eintak af tölvu.
                break;
            }
            case 3:
            {
                vector<Person> list = m_domain.getList(); // Sækja lista.
                this->printListPerson(list);

                int sos_ans = listMenu();
                while(sos_ans != 3)
                {
                    if(sos_ans == 1)
                    {
                        int sort_ans = sortMenu();
                        if(sort_ans == 1)
                        {
                            printSorted();
                        }
                        if(sort_ans == 2)
                        {
                            printSortedReverse();
                        }
                        if(sort_ans == 3)
                        {
                            printSortedYear();
                        }
                        if(sort_ans == 4)
                        {
                            printSortedYearReverse();
                        }
                    }
                    if(sos_ans == 2)
                    {
                        string remove;
                        cout << "Enter name to remove: ";
                        cin >> remove;
                        vector<Person> removelist = m_domain.removeScientist(remove); //
                        printListPerson(removelist);
                    }
                    if(sos_ans == 3)
                    {
                        break;
                    }
                    sos_ans = listMenu();
                }
                break;
             }

            case 4:
            {
                vector<Computers> cpulist = m_domain.getComputerList();
                printListComputers(cpulist);
                break;
            }

            case 5:
            {
                string search;

                cout << "Enter search word: ";
                cin >> search;

                vector<Person> searchlist = m_domain.searchScientist(search);
                printListPerson(searchlist);
                break;

                m_domain.saveAllData(); // Geymum öll gögn áður en forriti er lokað.
                return;
            }
            case 6:
            {
                string search;

                cout << "Enter search word: ";
                cin >> search;

                //vector<Computers> searchlist = m_domain.searchComputer(search);
                //printListComputers(searchlist);
                break;
            }
        }
    }
}

void Interface::programInfo() const  //Opnunarskilaboð til notanda.
{
    cout << "****************************************************" << endl;
    cout << "*                    WELCOME                       *" << endl;
    cout << "*  This program was made by the group \"22\"         *" << endl;
    cout << "*  Students from Reykjavik University              *" << endl;
    cout << "*                                                  *" << endl;
    cout << "* #Add        #Sort        #Search        #Link    *" << endl;
    cout << "****************************************************" << endl;
}

void Interface::mainMenu() const    //Aðalvalmynd.
{
    char pick;
    cout << endl;
    cout << "-- MAIN MENU -- " << endl;
    cout << "                " << endl;
    cout << "A - Add to list " << endl;
    cout << "S - Show list   " << endl;
    cout << "L - Search list " << endl;
    cout << "E - Save/Exit   " << endl;
    cin >> pick;

    if(pick == 'A' || pick == 'a')
    {
        system("cls");
        programInfo();
        cout << endl;
        cout << "-------------- MAIN MENU --------------" << endl;
        cout << "                                       " << endl;
        cout << "A - Add to list "                        << endl;
        cout << "          1. Scientist  2. Computer    " << endl;
        cout << "S - Show list "                          << endl;
        cout << "L - Search list "                        << endl;
        cout << "E - Save/Exit "                          << endl;
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
        cout << "        3. SCIENTISTS  4. COMPUTERS                " << endl;
        cout << "L - Search list "                                    << endl;
        cout << "E - Save/Exit " << endl;
    }
    if(pick == 'L' || pick == 'l')
    {
        system("cls");
        programInfo();
        cout << endl;
        cout << "-------------- MAIN MENU --------------" << endl;
        cout << "                                       " << endl;
        cout << "A - Add to list " << endl;
        cout << "S - Show list " << endl;
        cout << "L - Search list " << endl;
        cout << "        5. Scientist list  6. Computer list   " << endl;
        cout << "E - Save/Exit " << endl;
    }
    if(pick == 'E' || pick == 'e')
    {
        exit(1);
    }
}

Person Interface::getPersonInfo()   //Inntak fyrir upplýsingar um persónu.
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

Computers Interface::getComputerInfo()  //Inntak fyrir upplýsingar um tölvu.
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

void Interface::printListPerson(vector<Person> listOfPersons)   //Prentar út upplýsingar um persónur.
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

void Interface::printListComputers(vector<Computers> listOfComputers)   //Prentar út upplýsingar um tölvur.
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

int Interface::listMenu() const    //Valmynd fyrir "show list".
{

    int answer;

    cout << endl;
    cout << "       LIST MENU      " << endl;
    cout << "       ---------      " << endl;
    cout << "1 - Sort list" << endl;
    cout << "2 - Remove from list" << endl;
    cout << "3 - Return to main menu" << endl;

    cin >> answer;

    while(cin.fail() || answer < 1 || answer > 3)
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "The input you entered is not a valid option. Pick again!" << endl;
        cout << endl;
        cout << "       LIST MENU      " << endl;
        cout << "       ---------      " << endl;
        cout << "1 - Sort list" << endl;
        cout << "2 - Remove from list" << endl;
        cout << "3 - Return to main menu" << endl;
        cin >> answer;
    }

    return answer;
}

// --------------SORTLISTI-OG-SORTFÖLL-------------- //

int Interface::sortMenu() const   //Valmynd fyrir "sort list".

{
    int answer;
    cout << "--------------------------------" << endl;
    cout << "Sort by?" << endl;
    cout << "1 - In alphabetical order " << endl;
    cout << "2 - In reverse alphabetical order " << endl;
    cout << "3 - Birth " << endl;
    cout << "4 - Reverse birth " << endl;
    cin >> answer;
    while(cin.fail() || answer < 1 || answer > 4)
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "The input you entered is not a valid option. Pick again!" << endl;
        cout << "Sort by?" << endl;
        cout << "1 - In alphabetical order " << endl;
        cout << "2 - In reverse alphabetical order " << endl;
        cout << "3 - Birth " << endl;
        cout << "4 - Reverse birth " << endl;
        cin >> answer;
    }
    return answer;
}
void Interface::printSorted()   //Prentar út upplýsingar í Stafrófsröð.
{
    vector<Person>listOfPersons = m_domain.sortList(m_domain.getList());
    printListPerson(listOfPersons);
}

void Interface::printSortedReverse()    //Prentar út upplýsingar í öfugri stafrófsröð.
{
    vector<Person>listOfPersons = m_domain.sortListReverse(m_domain.getList());
    printListPerson(listOfPersons);
}

void Interface::printSortedYear()   //Prentar út upplýsingar frá elsta ári til yngsta.
{
    vector<Person>listOfPersons = m_domain.sortListYear(m_domain.getList());
    printListPerson(listOfPersons);
}

void Interface::printSortedYearReverse()    //Prentar út upplýsingar frá yngsta ári til elsta.
{
    vector<Person>listOfPersons = m_domain.sortListYearReverse(m_domain.getList());
    printListPerson(listOfPersons);
}
