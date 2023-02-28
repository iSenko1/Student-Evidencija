#ifndef STUDENTREPORT_H
#define STUDENTREPORT_H

#include <QDialog>
#include <QDebug>
#include <QSqlQuery>
#include "mojadb.h"
#include <QSqlQueryModel>

namespace Ui {
class StudentReport;
}

class StudentReport : public QDialog
{
    Q_OBJECT

public:
    explicit StudentReport(QWidget *parent = nullptr);
    ~StudentReport();
    void init();

private slots:
    void on_brisatBtn_clicked();

private:
    Ui::StudentReport *ui;
    void readDatafromDB();
};

#endif // STUDENTREPORT_H
