#ifndef AZURIRAJSTUDENT_H
#define AZURIRAJSTUDENT_H

#include <QDialog>
#include <QDebug>
#include <QSqlQuery>
#include "mojadb.h"


namespace Ui {
class AzurirajStudent;
}

class AzurirajStudent : public QDialog
{
    Q_OBJECT

public:
    explicit AzurirajStudent(QWidget *parent = nullptr);
    ~AzurirajStudent();

private slots:
    void on_nadiBtn_clicked();

    void on_azuBtn_clicked();

private:
    Ui::AzurirajStudent *ui;
    void showAllElements();
    void hideAllElements();
};

#endif // AZURIRAJSTUDENT_H
