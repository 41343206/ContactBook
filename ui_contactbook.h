/********************************************************************************
** Form generated from reading UI file 'contactbook.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTBOOK_H
#define UI_CONTACTBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Contactbook
{
public:
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QFormLayout *formLayout_4;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Contactbook)
    {
        if (Contactbook->objectName().isEmpty())
            Contactbook->setObjectName("Contactbook");
        Contactbook->resize(800, 600);
        verticalLayout_2 = new QVBoxLayout(Contactbook);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tableWidget = new QTableWidget(Contactbook);
        tableWidget->setObjectName("tableWidget");

        verticalLayout_2->addWidget(tableWidget);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        label = new QLabel(Contactbook);
        label->setObjectName("label");

        formLayout_4->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        lineEdit = new QLineEdit(Contactbook);
        lineEdit->setObjectName("lineEdit");

        formLayout_4->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit);

        label_2 = new QLabel(Contactbook);
        label_2->setObjectName("label_2");

        formLayout_4->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        label_3 = new QLabel(Contactbook);
        label_3->setObjectName("label_3");

        formLayout_4->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        label_4 = new QLabel(Contactbook);
        label_4->setObjectName("label_4");

        formLayout_4->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        lineEdit_2 = new QLineEdit(Contactbook);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout_4->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEdit_2);

        lineEdit_3 = new QLineEdit(Contactbook);
        lineEdit_3->setObjectName("lineEdit_3");

        formLayout_4->setWidget(2, QFormLayout::ItemRole::FieldRole, lineEdit_3);

        lineEdit_4 = new QLineEdit(Contactbook);
        lineEdit_4->setObjectName("lineEdit_4");

        formLayout_4->setWidget(3, QFormLayout::ItemRole::FieldRole, lineEdit_4);


        verticalLayout_2->addLayout(formLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(Contactbook);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(Contactbook);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Contactbook);

        QMetaObject::connectSlotsByName(Contactbook);
    } // setupUi

    void retranslateUi(QWidget *Contactbook)
    {
        Contactbook->setWindowTitle(QCoreApplication::translate("Contactbook", "Contactbook", nullptr));
        label->setText(QCoreApplication::translate("Contactbook", "\345\255\270\350\231\237:", nullptr));
        label_2->setText(QCoreApplication::translate("Contactbook", "\347\217\255\347\264\232:", nullptr));
        label_3->setText(QCoreApplication::translate("Contactbook", "\345\247\223\345\220\215:", nullptr));
        label_4->setText(QCoreApplication::translate("Contactbook", "\351\233\273\350\251\261:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Contactbook", "\346\226\260\345\242\236", nullptr));
        pushButton->setText(QCoreApplication::translate("Contactbook", "\345\214\257\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Contactbook: public Ui_Contactbook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTBOOK_H
