#include "contactbook.h"
#include "ui_contactbook.h"

#include<QFile>
#include<QDebug>
#include<QTextStream>
#include<QFileDialog>
#include<QMessageBox>

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
    ColTitles<<"學號"<<"班級"<<"姓名"<<"電話";
    ui->tableWidget->setHorizontalHeaderLabels(ColTitles);
    
    // Set column widths for better display
    ui->tableWidget->setColumnWidth(0, 120);
    ui->tableWidget->setColumnWidth(1, 120);
    ui->tableWidget->setColumnWidth(2, 150);
    ui->tableWidget->setColumnWidth(3, 150);
    
    // Connect table selection signal
    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged, 
            this, &Contactbook::on_tableWidget_itemSelectionChanged);
}

Contactbook::~Contactbook()
{
    delete ui;
}

void Contactbook::clearInputFields()
{
    ui->txtStudentId->clear();
    ui->txtClass->clear();
    ui->txtName->clear();
    ui->txtPhone->clear();
}

void Contactbook::loadSelectedRowToInputs()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow >= 0) {
        ui->txtStudentId->setText(ui->tableWidget->item(currentRow, 0)->text());
        ui->txtClass->setText(ui->tableWidget->item(currentRow, 1)->text());
        ui->txtName->setText(ui->tableWidget->item(currentRow, 2)->text());
        ui->txtPhone->setText(ui->tableWidget->item(currentRow, 3)->text());
    }
}

void Contactbook::on_btnAdd_clicked()
{
    // Validate inputs
    if(ui->txtStudentId->text().isEmpty() || ui->txtClass->text().isEmpty() ||
       ui->txtName->text().isEmpty() || ui->txtPhone->text().isEmpty()) {
        QMessageBox::warning(this, "輸入錯誤", "請填寫所有欄位！");
        return;
    }
    
    QTableWidgetItem *inputRow1, *inputRow2, *inputRow3, *inputRow4;
    inputRow1 = new QTableWidgetItem(QString(ui->txtStudentId->text()));
    inputRow2 = new QTableWidgetItem(QString(ui->txtClass->text()));
    inputRow3 = new QTableWidgetItem(QString(ui->txtName->text()));
    inputRow4 = new QTableWidgetItem(QString(ui->txtPhone->text()));
    
    int rc = ui->tableWidget->rowCount();
    qDebug()<<rc<<"\n";
    ui->tableWidget->insertRow(rc);
    ui->tableWidget->setItem(rc, 0, inputRow1);
    ui->tableWidget->setItem(rc, 1, inputRow2);
    ui->tableWidget->setItem(rc, 2, inputRow3);
    ui->tableWidget->setItem(rc, 3, inputRow4);
    
    // Clear input fields after adding
    clearInputFields();
    QMessageBox::information(this, "成功", "聯絡人新增成功！");
}

void Contactbook::on_btnEdit_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "選擇錯誤", "請先選擇要編輯的聯絡人！");
        return;
    }
    
    // Validate inputs
    if(ui->txtStudentId->text().isEmpty() || ui->txtClass->text().isEmpty() ||
       ui->txtName->text().isEmpty() || ui->txtPhone->text().isEmpty()) {
        QMessageBox::warning(this, "輸入錯誤", "請填寫所有欄位！");
        return;
    }
    
    ui->tableWidget->item(currentRow, 0)->setText(ui->txtStudentId->text());
    ui->tableWidget->item(currentRow, 1)->setText(ui->txtClass->text());
    ui->tableWidget->item(currentRow, 2)->setText(ui->txtName->text());
    ui->tableWidget->item(currentRow, 3)->setText(ui->txtPhone->text());
    
    clearInputFields();
    QMessageBox::information(this, "成功", "聯絡人編輯成功！");
}

void Contactbook::on_btnDelete_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "選擇錯誤", "請先選擇要刪除的聯絡人！");
        return;
    }
    
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "確認刪除", 
                                   "確定要刪除此聯絡人嗎？",
                                   QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        ui->tableWidget->removeRow(currentRow);
        clearInputFields();
        QMessageBox::information(this, "成功", "聯絡人已刪除！");
    }
}

void Contactbook::on_btnExport_clicked()
{
    QString saveFile="";

    for(int i=0;i<ui->tableWidget->rowCount();i++){
        for(int j=0;j<ui->tableWidget->columnCount();j++){
            saveFile+=ui->tableWidget->item(i,j)->text()+",";
        }
        saveFile+="\n";
    }
    Write(mFilename,saveFile);
    QMessageBox::information(this, "成功", "聯絡人資料已匯出！");
}

void Contactbook::on_btnImport_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("匯入聯絡人"), "",
        tr("Text Files (*.txt);;CSV Files (*.csv);;All Files (*)"));
    
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            ui->tableWidget->setRowCount(0);  // Clear existing data
            QTextStream in(&file);
            
            while (!in.atEnd()) {
                QString line = in.readLine();
                QStringList fields = line.split(",");
                
                if (fields.size() >= 4) {
                    int row = ui->tableWidget->rowCount();
                    ui->tableWidget->insertRow(row);
                    
                    for (int i = 0; i < 4 && i < fields.size(); i++) {
                        ui->tableWidget->setItem(row, i, new QTableWidgetItem(fields[i]));
                    }
                }
            }
            file.close();
            QMessageBox::information(this, "成功", "聯絡人資料已匯入！");
        } else {
            QMessageBox::warning(this, "錯誤", "無法開啟檔案！");
        }
    }
}

void Contactbook::on_btnExit_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "確認結束", 
                                   "確定要結束程式嗎？",
                                   QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        close();
    }
}

void Contactbook::on_btnSearch_clicked()
{
    QString searchText = ui->txtSearch->text().trimmed();
    
    if (searchText.isEmpty()) {
        QMessageBox::information(this, "提示", "請輸入搜尋關鍵字！");
        return;
    }
    
    // Hide all rows first
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        ui->tableWidget->setRowHidden(i, true);
    }
    
    // Show matching rows
    int matchCount = 0;
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        bool match = false;
        for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
            if (ui->tableWidget->item(i, j)->text().contains(searchText, Qt::CaseInsensitive)) {
                match = true;
                break;
            }
        }
        if (match) {
            ui->tableWidget->setRowHidden(i, false);
            matchCount++;
        }
    }
    
    if (matchCount == 0) {
        QMessageBox::information(this, "搜尋結果", "沒有找到符合的聯絡人！");
        on_btnClearSearch_clicked();  // Show all rows again
    } else {
        QMessageBox::information(this, "搜尋結果", 
                                QString("找到 %1 筆符合的聯絡人！").arg(matchCount));
    }
}

void Contactbook::on_btnClearSearch_clicked()
{
    ui->txtSearch->clear();
    
    // Show all rows
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        ui->tableWidget->setRowHidden(i, false);
    }
}

void Contactbook::on_tableWidget_itemSelectionChanged()
{
    loadSelectedRowToInputs();
}

