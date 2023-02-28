#include "azurirajstudent.h"
#include "ui_azurirajstudent.h"

AzurirajStudent::AzurirajStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AzurirajStudent)
{
    ui->setupUi(this);
    hideAllElements();
}

AzurirajStudent::~AzurirajStudent()
{
    delete ui;
}

void AzurirajStudent::on_nadiBtn_clicked()
{
    qDebug() << "in PronadiStudent::on_nadiBtn_clicked()";
    hideAllElements();
    QString jmbagNadiStr = ui->jmbagNadi->text();

    QSqlQuery query( MojaDb::getInstance()->getDBInstance());
    query.prepare("select JMBAG, Ime, Prezime, Matematika1, Programiranje1, Informatika1, Engleski, Ekonomija, MultimedijskiSustavi, ProsaoSemestar from studenti_data where JMBAG='" + jmbagNadiStr + "'");

    if(!query.exec())
       qDebug() << query.lastError().text() << query.lastQuery();
    else
       qDebug() << "uspješno učitavanje "<< query.lastQuery();
    //db.close();


    char flag = -1;
    while(query.next())
    {  flag = 1;
       ui->jmbagBr->setText(query.value(0).toString());
       ui->imeTxt->setText(query.value(1).toString());
       ui->prezTxt->setText(query.value(2).toString());
       ui->matTxt->setText(query.value(3).toString());
       ui->progTxt->setText(query.value(4).toString());
       ui->infTxt->setText(query.value(5).toString());
       ui->engTxt->setText(query.value(6).toString());
       ui->ekoTxt->setText(query.value(7).toString());
       ui->msTxt->setText(query.value(8).toString());
       ui->prosaoTxt->setCurrentIndex(ui->prosaoTxt->findText(query.value(9).toString()));
    }
    if(flag == 1)
    {
        showAllElements();
    }

    if(flag == -1)
       ui->infoLbl->show();

}

void AzurirajStudent:: showAllElements()
{
    ui->prezTxt->show();  ui->prezLbl->show();
    ui->imeTxt->show(); ui->imeLbl->show();
    ui->ekoTxt->show(); ui->ekoLbl->show();
    ui->infTxt->show(); ui->infLbl->show();
    ui->progTxt->show(); ui->progLbl->show();
    ui->jmbagBr->show(); ui->jmbagLbl->show();
    ui->matTxt->show(); ui->matLbl->show();
    ui->msTxt->show(); ui->msLbl->show();
    ui->engTxt->show(); ui->engLbl->show();
    ui->prosaoTxt->show(); ui->prosaoLbl->show();
   // ui->pushButton->show();
}

void AzurirajStudent::hideAllElements()
{
    ui->prezTxt->hide(); ui->prezLbl->hide();
    ui->imeTxt->hide(); ui->imeLbl->hide();
    ui->ekoTxt->hide(); ui->ekoLbl->hide();
    ui->infTxt->hide(); ui->infLbl->hide();
    ui->progTxt->hide(); ui->progLbl->hide();
    ui->jmbagBr->hide(); ui->jmbagLbl->hide();
    ui->matTxt->hide(); ui->matLbl->hide();
    ui->msTxt->hide(); ui->msLbl->hide();
    ui->engTxt->hide(); ui->engLbl->hide();
    ui->prosaoTxt->hide(); ui->prosaoLbl->hide();

    //ui->pushButton->hide();
    ui->infoLbl->hide();
}

void AzurirajStudent::on_azuBtn_clicked()
{

    QString jmbagBrStr  = ui->jmbagBr->text();
    QString imeTxtStr      = ui->imeTxt->text();
    QString prezTxtStr     = ui->prezTxt->text();
    QString matTxtStr   = ui->matTxt->text();
    QString progTxtStr  = ui->progTxt->text();
    QString infTxtStr   = ui->infTxt->text();
    QString engTxtStr   = ui->engTxt->text();
    QString ekoTxtStr   = ui->ekoTxt->text();
    QString msTxtStr    = ui->msTxt->text();

    QString prosaoTxtStr     = ui->prosaoTxt->currentText();

    QSqlQuery query( MojaDb::getInstance()->getDBInstance());
    query.clear();


    query.prepare("update studenti_data set Ime = :Ime, Prezime = :Prezime, Matematika1 = :Matematika1, Programiranje1 = :Programiranje1, Informatika1 = :Informatika1, Engleski = :Engleski, Ekonomija= :Ekonomija, MultimedijskiSustavi= :MultimedijskiSustavi, ProsaoSemestar = :ProsaoSemestar where JMBAG = :JMBAG");

    query.bindValue(":JMBAG", jmbagBrStr);
    query.bindValue(":Ime", imeTxtStr);
    query.bindValue(":Prezime", prezTxtStr);
    query.bindValue(":Matematika1", matTxtStr);
    query.bindValue(":Programiranje1", progTxtStr);
    query.bindValue(":Informatika1", infTxtStr);
    query.bindValue(":Engleski", engTxtStr);
    query.bindValue(":Ekonomija", ekoTxtStr);
    query.bindValue(":MultimedijskiSustavi", msTxtStr);
    query.bindValue(":ProsaoSemestar", prosaoTxtStr);

   if(!query.exec())
   {
       qDebug() << query.lastError().text() << query.lastQuery();
       ui->infoLbl->show();
   }
   else
   {
       qDebug() << "uspješno učitavanje "<< query.lastQuery();
       hideAllElements();
       ui->infoLbl->setText("Uspješna promjena podataka!");
       ui->infoLbl->show();

   }
}
