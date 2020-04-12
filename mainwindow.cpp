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
#include <fstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ifstream monFlux;
    monFlux.open((env.value("HOME") + "/.config/kdeglobals").toStdString());

    if(monFlux) // On teste si tout est OK
    {
        // Tout est OK, on peut utiliser le fichier
        string ligne {};
        while(getline(monFlux, ligne)) {
            if (ligne == "ScaleFactor=1" || ligne == "ScaleFactor=1.0") {
                ui->ScaleFactor->setValue(10);
            }
            if (ligne == "ScaleFactor=1.1") {
                ui->ScaleFactor->setValue(11);
            }
            if (ligne == "ScaleFactor=1.2") {
                ui->ScaleFactor->setValue(12);
            }
            if (ligne == "ScaleFactor=1.3") {
                ui->ScaleFactor->setValue(13);
            }
            if (ligne == "ScaleFactor=1.4") {
                ui->ScaleFactor->setValue(14);
            }
            if (ligne == "ScaleFactor=1.5") {
                ui->ScaleFactor->setValue(15);
            }
            if (ligne == "ScaleFactor=1.6") {
                ui->ScaleFactor->setValue(16);
            }
            if (ligne == "ScaleFactor=1.7") {
                ui->ScaleFactor->setValue(17);
            }
            if (ligne == "ScaleFactor=1.8") {
                ui->ScaleFactor->setValue(18);
            }
            if (ligne == "ScaleFactor=1.9") {
                ui->ScaleFactor->setValue(19);
            }
            if (ligne == "ScaleFactor=2" || ligne == "ScaleFactor=2.0") {
                ui->ScaleFactor->setValue(20);
            }
            if (ligne == "ScaleFactor=2.1") {
                ui->ScaleFactor->setValue(21);
            }
            if (ligne == "ScaleFactor=2.2") {
                ui->ScaleFactor->setValue(22);
            }
            if (ligne == "ScaleFactor=2.3") {
                ui->ScaleFactor->setValue(23);
            }
            if (ligne == "ScaleFactor=2.4") {
                ui->ScaleFactor->setValue(24);
            }
            if (ligne == "ScaleFactor=2.5") {
                ui->ScaleFactor->setValue(25);
            }
            if (ligne == "ScaleFactor=2.6") {
                ui->ScaleFactor->setValue(26);
            }
            if (ligne == "ScaleFactor=2.7") {
                ui->ScaleFactor->setValue(27);
            }
            if (ligne == "ScaleFactor=2.8") {
                ui->ScaleFactor->setValue(28);
            }
            if (ligne == "ScaleFactor=2.9") {
                ui->ScaleFactor->setValue(29);
            }
            if (ligne == "ScaleFactor=3" || ligne == "ScaleFactor=3.0") {
                ui->ScaleFactor->setValue(30);
            }
        }
    }
    else
    {
        cout << "Erreur : Impossible d'ouvrir le fichier CreateWave." << endl;
    }
    monFlux.close();
    ui->ConfigORCA->installEventFilter(this);
    ui->Discord->installEventFilter(this);
    ui->OuvrirKmag->installEventFilter(this);
    ui->OuvrirSiteWeb->installEventFilter(this);
    ui->OuvrirNavigateur->installEventFilter(this);
    ui->Forum->installEventFilter(this);
    ui->GitHub->installEventFilter(this);
    ui->NoComprendo->installEventFilter(this);
    ui->VocalFly->installEventFilter(this);
    ui->Contacts->installEventFilter(this);
    ui->Power->installEventFilter(this);
    ui->Reboot->installEventFilter(this);
    ui->Deconnection->installEventFilter(this);
    ui->ScaleFactor->installEventFilter(this);
    ui->label->setStyleSheet("background-color: black");
    if (!play) {
        player->setVolume(50);
        player->setMedia(QUrl::fromLocalFile("/usr/share/dvkbuntu-sound/1-connexion_session.ogg.wav"));
        player->play();
        play=true;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject* watched, QEvent* event)
{
  player->setVolume(50);
  if (!fenetreCritical) {
    if (watched == ui->ScaleFactor && event->type() == QEvent::HoverEnter)
    {
        ui->label->setStyleSheet("background-color: green");
        QString textScale;
        m_process->start("createWaveFromItem \"Pour changer le facteur d'échelle de toute l'interface. Actuellement à " + textScale.setNum (scale));
        play=false;
    }
    else if (watched == ui->ConfigORCA && event->type() == QEvent::HoverEnter)
    {
        ui->label->setStyleSheet("background-color: green");
        m_process->start("createWaveFromItem \"Accès Handicap.\"");
        play=false;
    }
    else if (watched == ui->Discord && event->type() == QEvent::HoverEnter)
    {
        ui->label->setStyleSheet("background-color: green");
        m_process->start("createWaveFromItem \"Pour rejoindre la communauté HandyOpenSource sur Discord.\"");
        play=false;
    }
    else if (watched == ui->OuvrirKmag && event->type() == QEvent::HoverEnter)
    {
        ui->label->setStyleSheet("background-color: green");
        m_process->start("createWaveFromItem \"Ouvrir la loupe Kmag.\"");
        play=false;
    }
    else if (watched == ui->OuvrirSiteWeb && event->type() == QEvent::HoverEnter)
    {
        ui->label->setStyleSheet("background-color: green");
        m_process->start("createWaveFromItem \"Ouvrir le site web de DVKBuntu.\"");
        play=false;
    }
    else if (watched == ui->OuvrirNavigateur && event->type() == QEvent::HoverEnter)
    {
        ui->label->setStyleSheet("background-color: green");
        m_process->start("createWaveFromItem \"Naviguer sur le net.\"");
        play=false;
    }
    else if (watched == ui->Forum && event->type() == QEvent::HoverEnter)
    {
        ui->label->setStyleSheet("background-color: green");
        m_process->start("createWaveFromItem \"Besoin d'aide, allez sur le forum.\"");
        play=false;
    }
    else if (watched == ui->VocalFly && event->type() == QEvent::HoverEnter)
    {
        ui->label->setStyleSheet("background-color: green");
        m_process->start("createWaveFromItem \"Ouvrir l'interface de VocalFly.\"");
        play=false;
    }
    else if (watched == ui->GitHub && event->type() == QEvent::HoverEnter)
    {
        ui->label->setStyleSheet("background-color: green");
        m_process->start("createWaveFromItem \"Accéder au code source de DVKBuntu.\"");
        play=false;
    }
    else if (watched == ui->NoComprendo && event->type() == QEvent::HoverEnter)
    {
        ui->label->setStyleSheet("background-color: green");
        m_process->start("createWaveFromItem \"Lancer l'assistant vocal.\"");
        play=false;
    }
    else if (watched == ui->Contacts && event->type() == QEvent::HoverEnter)
    {
        ui->label->setStyleSheet("background-color: green");
        m_process->start("createWaveFromItem \"Nous écrire par mail.\"");
        play=false;
    }
    else if (watched == ui->Power && event->type() == QEvent::HoverEnter)
    {
        ui->label->setStyleSheet("background-color: green");
        m_process->start("createWaveFromItem \"Arrêt du PC.\"");
        play=false;
    }
    else if (watched == ui->Reboot && event->type() == QEvent::HoverEnter)
    {
        ui->label->setStyleSheet("background-color: green");
        m_process->start("createWaveFromItem \"Redémarrage du PC.\"");
        play=false;
    }
    else if (watched == ui->Deconnection && event->type() == QEvent::HoverEnter)
    {
        ui->label->setStyleSheet("background-color: green");
        m_process->start("createWaveFromItem \"Déconnexion de la session courante.\"");
        play=false;
    }
    else if ((watched == ui->ScaleFactor || watched == ui->VocalFly || watched == ui->GitHub || watched == ui->Forum || watched == ui->ConfigORCA || watched == ui->Discord || watched == ui->OuvrirKmag || watched == ui->OuvrirSiteWeb || watched == ui->OuvrirNavigateur || watched == ui->NoComprendo || watched == ui->Contacts || watched == ui->Power || watched == ui->Reboot || watched == ui->Deconnection) && event->type() == QEvent::HoverLeave)
    {
        m_process->start("createWaveFromItem \"Stop.\"");
        play=false;
        ui->label->setStyleSheet("background-color: red");
    }
    m_process->waitForFinished(-1);
    if (!play) {
          player->setVolume(50);
          player->setMedia(QUrl::fromLocalFile(env.value("HOME") + "/.local/share/dvkbuntu/sonEnCours.wav"));
          player->play();
          play=true;
    }
  }
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

void MainWindow::on_Forum_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.forum.dvkbuntu.org/", QUrl::TolerantMode));
}

void MainWindow::on_VocalFly_clicked()
{
    QProcess *myProcess3 = new QProcess(this);
    myProcess3->startDetached("/usr/bin/VocalFly");
}

void MainWindow::on_GitHub_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/handyopensource", QUrl::TolerantMode));
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
    fenetreCritical = true;

    player->stop();
    play=true;

    QMessageBox messageBox;
    QString textScale;

    m_process->start("createWaveFromItem \"Redémarrage requis ! Le nouveau facteur d'échelle est de " + textScale.setNum (scale) + ", les changements d'échelles n'interviendront qu'après un redémarrage\"");
    m_process->waitForFinished(-1);

    ui->label->setStyleSheet("background-color: red");

    player->setVolume(50);
    player->setMedia(QUrl::fromLocalFile(env.value("HOME") + "/.local/share/dvkbuntu/sonEnCours.wav"));
    player->play();

    messageBox.critical(0,"Redémarrage requis", "Le nouveau facteur d'échelle est de " + textScale.setNum (scale) + ", les changements d'échelles n'interviendront qu'après un redémarrage");
    messageBox.setFixedSize(500,200);
    if (!messageBox.isVisible()) { fenetreCritical =false; }
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
