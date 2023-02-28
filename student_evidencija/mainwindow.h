#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPrinter>
#include <QPrintDialog>
#include <QDebug>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

#include "dodajstudent.h"
#include "pronadistudent.h"
#include "studentreport.h"
#include "azurirajstudent.h"

//QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT    //klasa je q objekt

public:
    MainWindow(QWidget *parent = nullptr);      // widget nema parent
    ~MainWindow();      //destruktor

private:
    Ui::MainWindow *ui; //pokazuje na ui klasu
    void init();

    DodajStudent    * ptrDodajStudent;
    PronadiStudent  * ptrPronadiStudent;
    StudentReport   * ptrStudentReport;
    AzurirajStudent * ptrAzurirajStudent;

    int dohvatProsao();
    int dohvatNeProsao();


private slots:
    void on_dodajBtn_clicked();
    void on_azuBtn_clicked();
    void on_nadiBtn_clicked();
    void on_dodajBtn2_clicked();
};
#endif // MAINWINDOW_H
