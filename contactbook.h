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
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Contactbook *ui;
};
#endif // CONTACTBOOK_H
