#include <iostream>
#include "interface.h"
#include <windows.h>

using namespace std;

int main()
{
    if(false)
    {
   /*     QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        QString dbName = "prufa.sqlite";
        db.setDatabaseName(dbName);

        db.open();

        QSqlQuery query(db);

        const QString sSQL = "SELECT * FROM person "
                             "where id>0";

        const QString sInsertSQL = "Insert into person(name, gender, yearOfBirth, yearOfDeath) "
                                   "values ('Grace Hopper','f', 1906, 1992)";

        query.exec(sInsertSQL);

        query.exec(sSQL);

        while(query.next())
        {
            int id = query.value("id").toUInt();
            string name = query.value("name").toString().toStdString();
            string gender = query.value("gender").toString().toStdString();
            //int age = query.value("age").toUInt();
            cout << id
                 << " "
                 << name
                 << " "
                 << gender << " "
                 << query.value("yearOfBirth").toUInt() << endl;
            //students.push_back(Student(id, name, age));
        }
        db.close();
*/
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);        //grænt letur.
        Interface inter;                                                     //býr til smið af Interface klasanum.
        inter.start();                                                       //Keyrir forritið.

        return 0;
    }
}
