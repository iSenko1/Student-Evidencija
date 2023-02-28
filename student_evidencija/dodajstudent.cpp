#include "dodajstudent.h"
#include "ui_dodajstudent.h"

DodajStudent::DodajStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajStudent)
{
    ui->setupUi(this);
    this->setFixedSize(500, 550);

}

DodajStudent::~DodajStudent()
{
    delete ui;
}

void DodajStudent::on_dodajBtn_clicked()
{
    qDebug()<<"in DodajStudent:: on_dodajBtn_clicked()";

    QString jmbagBrStr  = ui->jmbagBr->text();
    QString imeTxtStr   = ui->imeTxt->text();
    QString prezTxtStr  = ui->prezTxt->text();

    //PREDMETI
    QString matTxtStr   = ui->matTxt->text();
    QString progTxtStr  = ui->progTxt->text();
    QString infTxtStr   = ui->infTxt->text();
    QString engTxtStr   = ui->engTxt->text();
    QString ekoTxtStr   = ui->ekoTxt->text();
    QString msTxtStr    = ui->msTxt->text();

    QString polComboStr = ui->polCombo->currentText();

    QSqlQuery query( MojaDb::getInstance()->getDBInstance());

    //prva provjera ako JMBAG postoji
    query.prepare("select count(Id) from studenti_data where JMBAG = '" + jmbagBrStr + "'");
    int flag = -1;
    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        //flag = 1;
    }
    else
    {
        qDebug() << "Uspješno učitano "<< query.lastQuery();
        query.next();
        flag = query.value(0).toInt();
        if(flag>0)
        {
        qDebug() <<" JMBAG već postoji";
        ui->dodanInfo->setText("JMBAG već postoji");
        }
    }

    if(imeTxtStr != nullptr)
    {
        if(flag <= 0)
        {
            query.clear();
            query.prepare("INSERT INTO studenti_data (JMBAG, Ime, Prezime, Matematika1, Programiranje1, Informatika1, Engleski, Ekonomija, MultimedijskiSustavi, ProsaoSemestar) VALUES (:JMBAG, :Ime, :Prezime, :Matematika1, :Programiranje1, :Informatika1, :Engleski, :Ekonomija, :MultimedijskiSustavi, :ProsaoSemestar)");

            query.bindValue(":JMBAG", jmbagBrStr);
            query.bindValue(":Ime", imeTxtStr);
            query.bindValue(":Prezime", prezTxtStr);
            query.bindValue(":Matematika1", matTxtStr);
            query.bindValue(":Programiranje1", progTxtStr);
            query.bindValue(":Informatika1", infTxtStr);
            query.bindValue(":Engleski", engTxtStr);
            query.bindValue(":Ekonomija", ekoTxtStr);
            query.bindValue(":MultimedijskiSustavi", msTxtStr);
            query.bindValue(":ProsaoSemestar", polComboStr);

           if(!query.exec())
           {
               qDebug() << query.lastError().text() << query.lastQuery();

           }
            else
           {
               qDebug() << "uspješno učitavanje "<< query.lastQuery();
                resetAll();
               ui->dodanInfo->setText("Student uspješno unesen!");
           }
       }
    }
    else
   {
       qDebug() << "uspješno učitavanje "<< query.lastQuery();
       ui->dodanInfo->setText("Sva polja moraju biti popunjena!");
   }


}


void DodajStudent::on_pushButton_2_clicked()
{
    resetAll();
}


void DodajStudent::resetAll()
{
    qDebug() << "in DodajStudent:: resetAll()";
    ui->imeTxt->clear();
    ui->prezTxt->clear();
    ui->matTxt->clear();
    ui->engTxt->clear();
    ui->infTxt->clear();
    ui->jmbagBr->clear();
    ui->progTxt->clear();
    ui->ekoTxt->clear();
    ui->msTxt->clear();
    ui->polCombo->setCurrentIndex(0);

}
