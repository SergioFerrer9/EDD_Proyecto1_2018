/********************************************************************************
** Form generated from reading UI file 'terminado.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TERMINADO_H
#define UI_TERMINADO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Terminado
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Terminado)
    {
        if (Terminado->objectName().isEmpty())
            Terminado->setObjectName(QStringLiteral("Terminado"));
        Terminado->resize(377, 186);
        centralwidget = new QWidget(Terminado);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 90, 80, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 90, 80, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 0, 121, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 20, 161, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 40, 271, 31));
        Terminado->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Terminado);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 377, 20));
        Terminado->setMenuBar(menubar);
        statusbar = new QStatusBar(Terminado);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Terminado->setStatusBar(statusbar);

        retranslateUi(Terminado);

        QMetaObject::connectSlotsByName(Terminado);
    } // setupUi

    void retranslateUi(QMainWindow *Terminado)
    {
        Terminado->setWindowTitle(QApplication::translate("Terminado", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("Terminado", "No", nullptr));
        pushButton_2->setText(QApplication::translate("Terminado", "SI", nullptr));
        label->setText(QApplication::translate("Terminado", "!!! FELICIDADES !!!", nullptr));
        label_2->setText(QApplication::translate("Terminado", "Has completado el nivel", nullptr));
        label_3->setText(QApplication::translate("Terminado", "Deseas ver los enemigos que has eliminado", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Terminado: public Ui_Terminado {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TERMINADO_H
