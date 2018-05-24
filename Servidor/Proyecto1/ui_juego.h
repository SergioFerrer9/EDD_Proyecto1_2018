/********************************************************************************
** Form generated from reading UI file 'juego.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JUEGO_H
#define UI_JUEGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Juego
{
public:
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label;
    QTextEdit *textEdit;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QFrame *frame;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLabel *label_9;
    QLineEdit *lineEdit_6;
    QLabel *label_10;
    QLineEdit *lineEdit_7;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_3;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;

    void setupUi(QMainWindow *Juego)
    {
        if (Juego->objectName().isEmpty())
            Juego->setObjectName(QStringLiteral("Juego"));
        Juego->resize(1062, 690);
        centralwidget = new QWidget(Juego);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 29, 800, 471));
        QPalette palette;
        QBrush brush(QColor(0, 0, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        QBrush brush1(QColor(49, 54, 59, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        scrollArea->setPalette(palette);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 798, 469));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(210, 510, 600, 161));
        scrollArea_2 = new QScrollArea(centralwidget);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(820, 30, 231, 471));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 229, 469));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 510, 80, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 650, 31, 23));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(9, 0, 1041, 25));
        QPalette palette1;
        QBrush brush2(QColor(0, 85, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(35, 38, 41, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        frame->setPalette(palette1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(40, 0, 91, 25));
        QFont font;
        font.setPointSize(12);
        lineEdit_2->setFont(font);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 0, 61, 25));
        label_4->setFont(font);
        lineEdit_3 = new QLineEdit(frame);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(350, 0, 71, 25));
        lineEdit_3->setFont(font);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(290, 0, 61, 25));
        label_5->setFont(font);
        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(830, 0, 141, 25));
        label_9->setFont(font);
        lineEdit_6 = new QLineEdit(frame);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(970, 0, 71, 25));
        lineEdit_6->setFont(font);
        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(630, 0, 21, 25));
        label_10->setFont(font);
        lineEdit_7 = new QLineEdit(frame);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(650, 0, 71, 25));
        lineEdit_7->setFont(font);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(860, 540, 31, 25));
        label_6->setFont(font);
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(900, 540, 31, 25));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(70, 540, 80, 23));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(900, 520, 31, 25));
        QFont font1;
        font1.setPointSize(11);
        label_7->setFont(font1);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(950, 520, 31, 25));
        label_8->setFont(font1);
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(950, 540, 31, 25));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(900, 570, 80, 23));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(70, 570, 80, 23));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(70, 600, 80, 23));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(70, 630, 80, 23));
        Juego->setCentralWidget(centralwidget);

        retranslateUi(Juego);

        QMetaObject::connectSlotsByName(Juego);
    } // setupUi

    void retranslateUi(QMainWindow *Juego)
    {
        Juego->setWindowTitle(QApplication::translate("Juego", "Juego", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        pushButton->setText(QApplication::translate("Juego", "Iniciar", nullptr));
        pushButton_2->setText(QApplication::translate("Juego", "<<", nullptr));
        label_4->setText(QApplication::translate("Juego", "Nivel", nullptr));
        label_5->setText(QApplication::translate("Juego", "Puntos", nullptr));
        label_9->setText(QApplication::translate("Juego", "Tiempo Restante", nullptr));
        label_10->setText(QApplication::translate("Juego", "X", nullptr));
        label_6->setText(QApplication::translate("Juego", "Pila", nullptr));
        pushButton_3->setText(QApplication::translate("Juego", "Pausa", nullptr));
        label_7->setText(QApplication::translate("Juego", "X", nullptr));
        label_8->setText(QApplication::translate("Juego", "Y", nullptr));
        pushButton_4->setText(QApplication::translate("Juego", "Buscar", nullptr));
        pushButton_5->setText(QApplication::translate("Juego", "Conectar", nullptr));
        pushButton_6->setText(QApplication::translate("Juego", "Enemigos", nullptr));
        pushButton_7->setText(QApplication::translate("Juego", "Limpiar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Juego: public Ui_Juego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JUEGO_H
