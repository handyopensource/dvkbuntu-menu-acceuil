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
#include <QtMultimedia/QSound>
#include <QObject>
#include <QDebug>
#include <QEvent>
#include <QtMultimedia/QMediaPlayer>
#include <QFileInfo>
#include <QWidget>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ConfigORCA->installEventFilter(this);
    ui->Discord->installEventFilter(this);
    ui->OuvrirKmag->installEventFilter(this);
    ui->OuvrirSiteWeb->installEventFilter(this);
    ui->OuvrirNavigateur->installEventFilter(this);
    ui->NoComprendo->installEventFilter(this);
    ui->Contacts->installEventFilter(this);
    ui->Power->installEventFilter(this);
    ui->Reboot->installEventFilter(this);
    ui->Deconnection->installEventFilter(this);
    ui->label->setStyleSheet("background-color: black");
    player->setVolume(50);
    player->setMedia(QUrl::fromLocalFile("/usr/share/dvkbuntu-sound/1-connexion_session.ogg.wav"));
    player->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject* watched, QEvent* event)
{
  player->setVolume(50);
  if (watched == ui->ConfigORCA && event->type() == QEvent::HoverEnter)
  {
    qDebug() << "Start hover";
    ui->label->setStyleSheet("background-color: green");
    player->setMedia(QUrl::fromLocalFile("/usr/share/dvkbuntu-sound/7-AccesHandicap.ogg.wav"));
  }
  else if (watched == ui->Discord && event->type() == QEvent::HoverEnter)
  {
    qDebug() << "Start hover";
    ui->label->setStyleSheet("background-color: green");
    player->setMedia(QUrl::fromLocalFile("/usr/share/dvkbuntu-sound/10-DiscordLink.ogg.wav"));
  }
  else if (watched == ui->OuvrirKmag && event->type() == QEvent::HoverEnter)
  {
    qDebug() << "Start hover";
    ui->label->setStyleSheet("background-color: green");
    player->setMedia(QUrl::fromLocalFile("/usr/share/dvkbuntu-sound/6-Kmag.ogg.wav"));
  }
  else if (watched == ui->OuvrirSiteWeb && event->type() == QEvent::HoverEnter)
  {
    qDebug() << "Start hover";
    ui->label->setStyleSheet("background-color: green");
    player->setMedia(QUrl::fromLocalFile("/usr/share/dvkbuntu-sound/8-SiteWeb.ogg.wav"));
  }
  else if (watched == ui->OuvrirNavigateur && event->type() == QEvent::HoverEnter)
  {
    qDebug() << "Start hover";
    ui->label->setStyleSheet("background-color: green");
    player->setMedia(QUrl::fromLocalFile("/usr/share/dvkbuntu-sound/5-browser.ogg.wav"));
  }
  else if (watched == ui->NoComprendo && event->type() == QEvent::HoverEnter)
  {
    qDebug() << "Start hover";
    ui->label->setStyleSheet("background-color: green");
    player->setMedia(QUrl::fromLocalFile("/usr/share/dvkbuntu-sound/9-nocomprendo.ogg.wav"));
  }
  else if (watched == ui->Contacts && event->type() == QEvent::HoverEnter)
  {
    qDebug() << "Start hover";
    ui->label->setStyleSheet("background-color: green");
    player->setMedia(QUrl::fromLocalFile("/usr/share/dvkbuntu-sound/11-Email.ogg.wav"));
  }
  else if (watched == ui->Power && event->type() == QEvent::HoverEnter)
  {
    qDebug() << "Start hover";
    ui->label->setStyleSheet("background-color: green");
    player->setMedia(QUrl::fromLocalFile("/usr/share/dvkbuntu-sound/12-Shutdown.ogg.wav"));
  }
  else if (watched == ui->Reboot && event->type() == QEvent::HoverEnter)
  {
    qDebug() << "Start hover";
    ui->label->setStyleSheet("background-color: green");
    player->setMedia(QUrl::fromLocalFile("/usr/share/dvkbuntu-sound/13-Reboot.ogg.wav"));
  }
  else if (watched == ui->Deconnection && event->type() == QEvent::HoverEnter)
  {
    qDebug() << "Start hover";
    ui->label->setStyleSheet("background-color: green");
    player->setMedia(QUrl::fromLocalFile("/usr/share/dvkbuntu-sound/14-LeaveSession.ogg.wav"));
  }
  else if ((watched == ui->ConfigORCA || watched == ui->Discord || watched == ui->OuvrirKmag || watched == ui->OuvrirSiteWeb || watched == ui->OuvrirNavigateur || watched == ui->NoComprendo || watched == ui->Contacts || watched == ui->Power || watched == ui->Reboot || watched == ui->Deconnection) && event->type() == QEvent::HoverLeave)
  {
    qDebug() << "End hover";
    player->stop();
    player->setMedia(QUrl::fromLocalFile("/usr/share/dvkbuntu-sound/20-Stop.wav"));
    ui->label->setStyleSheet("background-color: red");
  }
  player->play();
  return QMainWindow::eventFilter(watched, event);
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
    QMessageBox messageBox;
    QString textScale;
    messageBox.critical(0,"Redémarrage requis", "Le nouveau facteur d'échelle est de " + textScale.setNum (scale) + ", les changements d'échelles n'interviendront qu'après un redémarrage");
    messageBox.setFixedSize(500,200);
}

void MainWindow::on_Power_clicked()
{
    player->setVolume(50);
    player->setMedia(QUrl::fromLocalFile("/usr/share/dvkbuntu-sound/3-bouton_shutdown.ogg.wav"));
    player->play();
    system("qdbus org.kde.ksmserver /KSMServer org.kde.KSMServerInterface.logout 0 2 3");
}

void MainWindow::on_Reboot_clicked()
{

    player->setVolume(50);
    player->setMedia(QUrl::fromLocalFile("/usr/share/dvkbuntu-sound/2-bouton_reboot.ogg.wav"));
    player->play();
    system("qdbus org.kde.ksmserver /KSMServer org.kde.KSMServerInterface.logout 0 1 3");
}

void MainWindow::on_Deconnection_clicked()
{

    player->setVolume(50);
    player->setMedia(QUrl::fromLocalFile("/usr/share/dvkbuntu-sound/4-bouton_delog.ogg.wav"));
    player->play();
    system("qdbus org.kde.ksmserver /KSMServer org.kde.KSMServerInterface.logout 0 0 3");
}
