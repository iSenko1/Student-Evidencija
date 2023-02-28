#ifndef MOJADB_H
#define MOJADB_H
#include <QDebug>

#include <QSqlDatabase>
#include <QFile>
#include <QDebug>
#include <QSqlError>

class MojaDb
{
private:
    MojaDb();
    static MojaDb *instance;
    void init();
    QSqlDatabase db;
public:
    static MojaDb* getInstance();
    static void ResetInstance();
    void dodajStudent();
    void pronadiStudent();
    void studentReport();
    void azurirajStudent();
    int dohvatProsao();
    int dohvatNeProsao();
    QSqlDatabase getDBInstance();

    ~MojaDb();
};

#endif // MojaDb_H
