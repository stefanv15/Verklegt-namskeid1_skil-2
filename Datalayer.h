#ifndef DATALAYER_H
#define DATALAYER_H
#include "Person.h"
#include <vector>


class DataLayer
{
public:
    DataLayer();
    void saveData();                // vistar vector af persónum.
    void addData(Person& p);        // bætir persónu við
    vector<Person> getPersonList(); // sækir m_personList.

private:
    void getData(); // sækir allar persónur úr skrá og setur inn í vectorinn.
    vector<Person> m_personList; // geymir lista af persónum.
    void createTestData();      // temp. prufu data.
};

#endif // DATALAYER_H
