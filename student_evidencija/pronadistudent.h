#ifndef PRONADISTUDENT_H
#define PRONADISTUDENT_H

#include <QDialog>
#include <QDebug>
#include "mojadb.h"
#include <QSqlQuery>

namespace Ui {
class PronadiStudent;
}

class PronadiStudent : public QDialog
{
    Q_OBJECT

public:
    explicit PronadiStudent(QWidget *parent = nullptr);
    ~PronadiStudent();

private slots:
    void on_nadiBtn_clicked();

private:
    Ui::PronadiStudent *ui;
    void showAllElements();
    void hideAllElements();
};

#endif // PRONADISTUDENT_H
