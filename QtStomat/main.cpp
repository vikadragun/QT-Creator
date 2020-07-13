#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QStyle>

int main(int argc, char *argv[])
{
//C:\qtlab\curswork\QtStomat

    QApplication a(argc, argv);
    MainWindow w;
    QFile file("C:\\qtlab\\curswork\\QtStomat\\style.qss");
    if(file.open(QFile::ReadOnly)) {
       QString StyleSheet = QLatin1String(file.readAll());
       qApp->setStyleSheet(StyleSheet);
    }
    w.show();

    return a.exec();
}
