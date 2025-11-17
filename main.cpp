#include "contactbook.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Contactbook w;
    w.show();
    return a.exec();
}
