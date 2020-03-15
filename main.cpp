#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QtMultimedia/QMediaPlayer>
#include "ui_mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling); // DPI support
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps); //HiDPI pixmaps
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/Logo.png"));
    MainWindow* w = new MainWindow;
    w->show();
    return a.exec();
}
