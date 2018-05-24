/********************************************************************************
** Form generated from reading UI file 'enemigos.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENEMIGOS_H
#define UI_ENEMIGOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Enemigos
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_5;
    QLabel *label_2;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_6;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;

    void setupUi(QMainWindow *Enemigos)
    {
        if (Enemigos->objectName().isEmpty())
            Enemigos->setObjectName(QStringLiteral("Enemigos"));
        Enemigos->resize(580, 600);
        centralwidget = new QWidget(Enemigos);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(40, 9, 511, 541));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 487, 492));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_4->addWidget(scrollArea, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        scrollArea_2 = new QScrollArea(tab_2);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 487, 492));
        gridLayout_5 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_5->addWidget(label_2, 0, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_2->addWidget(scrollArea_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        scrollArea_3 = new QScrollArea(tab_3);
        scrollArea_3->setObjectName(QStringLiteral("scrollArea_3"));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 487, 492));
        gridLayout_6 = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_3 = new QLabel(scrollAreaWidgetContents_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_6->addWidget(label_3, 0, 0, 1, 1);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        gridLayout_3->addWidget(scrollArea_3, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 560, 41, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(520, 560, 61, 23));
        Enemigos->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Enemigos);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 580, 20));
        Enemigos->setMenuBar(menubar);

        retranslateUi(Enemigos);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Enemigos);
    } // setupUi

    void retranslateUi(QMainWindow *Enemigos)
    {
        Enemigos->setWindowTitle(QApplication::translate("Enemigos", "Enemigos", nullptr));
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Enemigos", "Tipo 1", nullptr));
        label_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Enemigos", "Tipo 2", nullptr));
        label_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Enemigos", "Tipo 3", nullptr));
        pushButton->setText(QApplication::translate("Enemigos", "<<", nullptr));
        pushButton_2->setText(QApplication::translate("Enemigos", "Graficas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Enemigos: public Ui_Enemigos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENEMIGOS_H
