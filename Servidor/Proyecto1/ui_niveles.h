/********************************************************************************
** Form generated from reading UI file 'niveles.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NIVELES_H
#define UI_NIVELES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Niveles
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label;
    QMenuBar *menubar;

    void setupUi(QMainWindow *Niveles)
    {
        if (Niveles->objectName().isEmpty())
            Niveles->setObjectName(QStringLiteral("Niveles"));
        Niveles->resize(512, 600);
        centralwidget = new QWidget(Niveles);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 20, 120, 23));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 60, 120, 30));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 140, 120, 30));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 200, 120, 30));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 260, 120, 30));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(0, 560, 41, 23));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(160, 10, 331, 561));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 329, 559));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        Niveles->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Niveles);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 512, 20));
        Niveles->setMenuBar(menubar);

        retranslateUi(Niveles);

        QMetaObject::connectSlotsByName(Niveles);
    } // setupUi

    void retranslateUi(QMainWindow *Niveles)
    {
        Niveles->setWindowTitle(QApplication::translate("Niveles", "Niveles", nullptr));
        lineEdit->setInputMask(QApplication::translate("Niveles", "9999", nullptr));
        pushButton->setText(QApplication::translate("Niveles", "Agregar Niveles", nullptr));
        pushButton_2->setText(QApplication::translate("Niveles", "Agregar Nivel", nullptr));
        pushButton_3->setText(QApplication::translate("Niveles", "Eliminar Nivel", nullptr));
        pushButton_4->setText(QApplication::translate("Niveles", "Ver Imagen", nullptr));
        pushButton_5->setText(QApplication::translate("Niveles", "<<", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Niveles: public Ui_Niveles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVELES_H
