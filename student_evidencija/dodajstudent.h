#ifndef DODAJSTUDENT_H
#define DODAJSTUDENT_H

#include <QDialog>
#include <QDebug>
#include <QSqlQuery>
#include "mojadb.h"

namespace Ui {
class DodajStudent;
}

class DodajStudent : public QDialog
{
    Q_OBJECT

public:
    explicit DodajStudent(QWidget *parent = nullptr);
    ~DodajStudent();

private:
    Ui::DodajStudent *ui;

private slots:
    void resetAll();
    void on_dodajBtn_clicked();
    void on_pushButton_2_clicked();

};

#endif // DODAJSTUDENT_H
