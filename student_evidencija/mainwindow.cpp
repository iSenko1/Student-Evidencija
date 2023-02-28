#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts>

//using namespace QtCharts;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),    //zove q main window
    ui(new Ui::MainWindow)  //ui klasa i stavimo ui member
{
    ui->setupUi(this);
    this->setFixedSize(700, 800);
    init();

    ptrDodajStudent = new DodajStudent(this);
    ptrPronadiStudent = new PronadiStudent(this);
    ptrStudentReport = new StudentReport(this);
    ptrAzurirajStudent = new AzurirajStudent(this);

}

void MainWindow::init()
{
    QBarSet *set0 = new QBarSet("Nisu Prošli Semestar");
    QBarSet *set1 = new QBarSet("Prošli Semestar");

    *set0 << dohvatNeProsao();
    *set1 << dohvatProsao();

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Status prolaznosti studenata");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QFont font;
    font.setPixelSize(18);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::black));

    QStringList categories;
    categories << " " ;
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,50);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    //bg od charta
    QLinearGradient backgroundGradient;
    backgroundGradient.setStart(QPointF(0, 0));
    backgroundGradient.setFinalStop(QPointF(0, 1));
    backgroundGradient.setColorAt(0.0, QRgb(0xd2d0d1));
    backgroundGradient.setColorAt(1.0, QRgb(0x4c4547));
    backgroundGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    chart->setBackgroundBrush(backgroundGradient);

    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    //chartView->setGeometry(0,100,300,200);
    chartView->resize(200,150);
    //this->setCentralWidget(chartView);
    ui->verticalLayout->addWidget(chartView);



}
MainWindow::~MainWindow()
{
    delete ui;
    MojaDb::ResetInstance(); //brisanje DB instance
    delete ptrDodajStudent; ptrDodajStudent = nullptr;
    delete ptrPronadiStudent; ptrPronadiStudent = nullptr;
    delete ptrStudentReport; ptrPronadiStudent = nullptr;
    delete ptrAzurirajStudent; ptrAzurirajStudent = nullptr;

}

int MainWindow::dohvatProsao()
{
    qDebug() <<"in MojaDb::dohvatProsao()";

    QSqlQuery query( MojaDb::getInstance()->getDBInstance());

    query.prepare("select count(Id) from studenti_data where ProsaoSemestar = 'DA'");
    int count = -1;
    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        //flag = 1;
    }
    else
    {
        qDebug() << "Uspješno učitano "<< query.lastQuery();
        query.next();

        count = query.value(0).toInt();
        qDebug()<< "Studenti koji nisu prošli : "<<count;
        return count;
    }
    return 0;
}

int MainWindow::dohvatNeProsao()
{
    qDebug() <<" in MojaDb::dohvatNeProsao()";

    QSqlQuery query( MojaDb::getInstance()->getDBInstance());

    //first check if SerialNo already exist
    query.prepare("select count(Id) from studenti_data where ProsaoSemestar = 'NE'");
    int count = -1;
    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        //flag = 1;
    }
    else
    {
        qDebug() << "Uspješno učitano "<< query.lastQuery();
        query.next();

        count = query.value(0).toInt();
        qDebug()<< "Studenti koji nisu prošli : "<<count;
        return count;
    }
    return 0;
}

void MainWindow::on_dodajBtn_clicked()
{
    ptrDodajStudent->show();
}


void MainWindow::on_azuBtn_clicked()
{
    ptrPronadiStudent->show();
}


void MainWindow::on_nadiBtn_clicked()
{
    ptrAzurirajStudent->show();
}


void MainWindow::on_dodajBtn2_clicked()
{
    ptrStudentReport->init();
    ptrStudentReport->show();
}

