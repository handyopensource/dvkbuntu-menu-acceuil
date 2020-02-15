//#include "scalingconfig.h"
//#include "ksharedconfig.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDesktopServices>
#include <QProcess>
//#include <KSharedConfig>
//#include <KConfigGroup>
//#include <KScreen/Output>
#include <qurl.h>
#include <QMessageBox>
#include <QSettings>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <QByteRef>
#include <QMetaType>
#include <QByteArray>
#include <QFile>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool is_readable( const std::string & file )
{
    std::ifstream fichier( file.c_str() );
    return (bool) fichier != 0;
}

void MainWindow::on_ConfigORCA_clicked()
{
    QProcess *myProcess1 = new QProcess(this);
    myProcess1->startDetached("kcmshell5 kcmaccess");
}

void MainWindow::on_Discord_clicked()
{
    QDesktopServices::openUrl(QUrl("https://discord.gg/zG7g8cU", QUrl::TolerantMode));
}

void MainWindow::on_NoComprendo_clicked()
{
    using std::cout;
    if ( is_readable( "/usr/bin/nocomprendo" ) )
    {
        QProcess *myProcess3 = new QProcess(this);
        myProcess3->startDetached("/usr/bin/nocomprendo");
    }
    else
    {
        /* Le fichier n'existe pas */
        QMessageBox::warning(this, "NoComprendo Non Installé", "Veuillez suivre les instructions d'installation sur la page web qui va s'ouvrir");
        QDesktopServices::openUrl(QUrl("https://github.com/handyopensource/dvkbuntu-script-tts", QUrl::TolerantMode));
    }
}

void MainWindow::on_OuvrirNavigateur_clicked()
{
    QDesktopServices::openUrl(QUrl("file:///home/Accueil_local/index.html", QUrl::TolerantMode));
}

void MainWindow::on_OuvrirKmag_clicked()
{
    QProcess *myProcess3 = new QProcess(this);
    myProcess3->startDetached("/usr/bin/kmag");
}

void MainWindow::on_OuvrirSiteWeb_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.dvkbuntu.org", QUrl::TolerantMode));
}

void MainWindow::on_Contacts_clicked()
{
    QDesktopServices::openUrl(QUrl("mailto:handyopensourcedvkbuntu@gmail.com?subject=DVKBuntu&body=Bonjour \n \n \nCordialement\nPrénom Nom"));
}

void MainWindow::on_ScaleFactor_valueChanged(int value)
{
    float fvalue = value;
    scale=fvalue/10;

    ostringstream newscale;
    newscale<<scale;

    QString newnewscale = QString::fromStdString(newscale.str());

    QProcess::startDetached("/opt/dvkbuntu-menu-acceuil/ScaleFactor.sh", QStringList {newnewscale});
}

void MainWindow::on_ScaleFactor_sliderReleased()
{
    //QByteArray arrayScale(reinterpret_cast<const char*>(&scale),sizeof(scale));
    //qputenv("QT_SCALE_FACTOR",arrayScale);
    QMessageBox messageBox;
    QString textScale;
    messageBox.critical(0,"Redémarrage requis", "Le nouveau facteur d'échelle est de " + textScale.setNum (scale) + ", les changements d'échelles n'interviendront qu'après un redémarrage");
    messageBox.setFixedSize(500,200);
}

void MainWindow::on_Power_clicked()
{
    system("qdbus org.kde.ksmserver /KSMServer org.kde.KSMServerInterface.logout 0 2 3");
}

void MainWindow::on_Reboot_clicked()
{
    system("qdbus org.kde.ksmserver /KSMServer org.kde.KSMServerInterface.logout 0 1 3");
}

void MainWindow::on_Deconnection_clicked()
{
    system("qdbus org.kde.ksmserver /KSMServer org.kde.KSMServerInterface.logout 0 0 3");
}
