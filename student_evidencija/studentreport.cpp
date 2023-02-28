#include "studentreport.h"
#include "ui_studentreport.h"

StudentReport::StudentReport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentReport)
{
    ui->setupUi(this);
    init();
}

StudentReport::~StudentReport()
{
    delete ui;
}

void StudentReport::init()
{
    qDebug() << "in init()";
    QSqlQueryModel * model = new QSqlQueryModel(this);

    QSqlQuery query( MojaDb::getInstance()->getDBInstance());
    query.prepare("select JMBAG, Ime, Prezime, Matematika1, Programiranje1, Informatika1, Engleski, Ekonomija, MultimedijskiSustavi, ProsaoSemestar from studenti_data");

    if(!query.exec())
       qDebug() << query.lastError().text() << query.lastQuery();
    else
       qDebug() << "== success query fetch()";

    while(query.next())
    qDebug()<<query.value(0).toString();

    model->setQuery(query);
    ui->tableView->setModel(model);
    qDebug() << "Studenata ima : " << model->rowCount();
    ui->tableView->show();
}

void StudentReport::on_brisatBtn_clicked()
{
    QString jmbagBrStr = ui->jmbagBr->text();

    QSqlQuery query( MojaDb::getInstance()->getDBInstance());
    query.prepare("DELETE FROM studenti_data where JMBAG='" + jmbagBrStr + "'");

    if(!query.exec())
       qDebug() << query.lastError().text() << query.lastQuery();
    else
       qDebug() << "Uspješno izbrisan podatak! "<< query.lastQuery();
    //db.close();
}

