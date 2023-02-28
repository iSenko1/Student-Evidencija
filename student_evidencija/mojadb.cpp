#include "mojadb.h"

MojaDb* MojaDb::instance = nullptr;

MojaDb::MojaDb()
{
    init();
}
void MojaDb::init()
{
    db = QSqlDatabase::addDatabase("QSQLITE", "Data");
    db.setDatabaseName("d:/studenti_data.sqlite");

    if(QFile::exists("d:/studenti_data.sqlite"))
            qDebug() << "DB datoteka već postoji";
        else
           qDebug() << "DB datoteka ne postoji";

        if (!db.open())
            qDebug() << db.lastError().text();
        else
            qDebug() << "DB uspješno učitana!";

}

MojaDb *MojaDb::getInstance()
{
    qDebug() << "in MojaDb::getInstance()";

    if(instance == nullptr)
        instance = new MojaDb();

    return instance;

}

QSqlDatabase MojaDb::getDBInstance()
{
    return db;
}

void MojaDb::ResetInstance()
   {
      delete instance;
      instance = nullptr;
   }

MojaDb::~MojaDb()
{
   db.close();
}
