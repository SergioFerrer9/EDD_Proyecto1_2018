/********************************************************************************
** Form generated from reading UI file 'resultados.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTADOS_H
#define UI_RESULTADOS_H

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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Resultados
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Resultados)
    {
        if (Resultados->objectName().isEmpty())
            Resultados->setObjectName(QStringLiteral("Resultados"));
        Resultados->resize(800, 600);
        centralwidget = new QWidget(Resultados);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 20, 761, 491));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 737, 442));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        scrollArea_2 = new QScrollArea(tab_2);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 737, 442));
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_3->addWidget(scrollArea_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(700, 510, 80, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 550, 51, 20));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(490, 510, 80, 23));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(380, 510, 113, 23));
        Resultados->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Resultados);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        Resultados->setMenuBar(menubar);
        toolBar = new QToolBar(Resultados);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        Resultados->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(Resultados);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Resultados);
    } // setupUi

    void retranslateUi(QMainWindow *Resultados)
    {
        Resultados->setWindowTitle(QApplication::translate("Resultados", "MainWindow", nullptr));
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Resultados", "General", nullptr));
        label_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Resultados", "Usuario", nullptr));
        pushButton->setText(QApplication::translate("Resultados", "Lista", nullptr));
        pushButton_2->setText(QApplication::translate("Resultados", "<<", nullptr));
        pushButton_3->setText(QApplication::translate("Resultados", "Arbol", nullptr));
        toolBar->setWindowTitle(QApplication::translate("Resultados", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Resultados: public Ui_Resultados {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTADOS_H
