#include "mainwindow.h"
#include <QApplication>
#include "listamatrices.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
