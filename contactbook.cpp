#include "contactbook.h"
#include "ui_contactbook.h"

#include<QFile>
#include<QDebug>
#include<QTextStream>
#include<QFileDialog>

QString mFilename = "C:/test/myfile.txt";
void Write(QString Filename,QString str)
{
    QFile mFile(Filename);
    if(!mFile.open(QFile::WriteOnly | QFile::Text)){
        qDebug()<<"could not open file for write";
        return;
    }

    QTextStream out(&mFile);
    out<<str;
    mFile.flush();
    mFile.close();
}

Contactbook::Contactbook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Contactbook)
{
    ui->setupUi(this);

    QStringList ColTitles;

    ui->tableWidget->setColumnCount(4);
    ColTitles<<"學號"<<"班級"<<"姓名"<<"班級";
    ui->tableWidget->setHorizontalHeaderLabels(ColTitles);
}

Contactbook::~Contactbook()
{
    delete ui;
}

void Contactbook::on_pushButton_2_clicked()
{
    QTableWidgetItem *inputRow1,*inputRow2,*inputRow3,*inputRow4;
    inputRow1 = new QTableWidgetItem(QString(ui->lineEdit->text()));
    inputRow2 = new QTableWidgetItem(QString(ui->lineEdit_2->text()));
    inputRow3 = new QTableWidgetItem(QString(ui->lineEdit_3->text()));
    inputRow4 = new QTableWidgetItem(QString(ui->lineEdit_4->text()));
    int rc = ui->tableWidget->rowCount();
    qDebug()<<rc<<"\n";
    ui->tableWidget->insertRow(rc);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,inputRow1);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,inputRow2);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,inputRow3);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,inputRow4);
}


void Contactbook::on_pushButton_clicked()
{
    QString saveFile="";

    for(int i=0;i<ui->tableWidget->rowCount();i++){
        for(int j=0;j<ui->tableWidget->columnCount();j++){
            saveFile+=ui->tableWidget->item(i,j)->text()+",";
        }
        saveFile+="\n";
    }
    Write(mFilename,saveFile);
}


void Contactbook::on_pushButton_3_clicked()
{
    //加 存檔的動作
    close();
}


void Contactbook::on_pushButton_4_clicked()
{

}

