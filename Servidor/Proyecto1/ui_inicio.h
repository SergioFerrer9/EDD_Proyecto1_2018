/********************************************************************************
** Form generated from reading UI file 'inicio.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_H
#define UI_INICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inicio
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Inicio)
    {
        if (Inicio->objectName().isEmpty())
            Inicio->setObjectName(QStringLiteral("Inicio"));
        Inicio->resize(598, 296);
        centralwidget = new QWidget(Inicio);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 10, 80, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 60, 80, 23));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 120, 80, 23));
        Inicio->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Inicio);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 598, 20));
        Inicio->setMenuBar(menubar);
        statusbar = new QStatusBar(Inicio);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Inicio->setStatusBar(statusbar);

        retranslateUi(Inicio);

        QMetaObject::connectSlotsByName(Inicio);
    } // setupUi

    void retranslateUi(QMainWindow *Inicio)
    {
        Inicio->setWindowTitle(QApplication::translate("Inicio", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("Inicio", "Niveles", nullptr));
        pushButton_2->setText(QApplication::translate("Inicio", "Juego", nullptr));
        pushButton_3->setText(QApplication::translate("Inicio", "Puntajes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Inicio: public Ui_Inicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_H
