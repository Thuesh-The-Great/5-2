#include "mainwindow.h"
#include "htmlhandler.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HTML ob;
    MainWindow w( ob );
    w.show();
    return a.exec();
}
