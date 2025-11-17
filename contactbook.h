#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Contactbook;
}
QT_END_NAMESPACE

class Contactbook : public QWidget
{
    Q_OBJECT

public:
    Contactbook(QWidget *parent = nullptr);
    ~Contactbook();

private slots:
    void on_btnAdd_clicked();
    void on_btnEdit_clicked();
    void on_btnDelete_clicked();
    void on_btnExport_clicked();
    void on_btnImport_clicked();
    void on_btnExit_clicked();
    void on_btnSearch_clicked();
    void on_btnClearSearch_clicked();
    void on_tableWidget_itemSelectionChanged();

private:
    Ui::Contactbook *ui;
    void clearInputFields();
    void loadSelectedRowToInputs();
};
#endif // CONTACTBOOK_H
