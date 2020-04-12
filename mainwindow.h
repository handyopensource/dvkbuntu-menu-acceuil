#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QMouseEventTransition>
#include <QtWidgets>
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    float scale = 1.8;
    qreal myscale = scale * 10;
    bool fenetreCritical = false;
    //QSlider ScaleFactor();
    //ScaleFactor().setValue(myscale);
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual bool eventFilter(QObject* watched, QEvent* event);
    QMediaPlayer *player = new QMediaPlayer;
    QProcess *m_process = new QProcess;
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();

private slots:
    void on_ConfigORCA_clicked();

    void on_Discord_clicked();

    void on_NoComprendo_clicked();

    void on_OuvrirKmag_clicked();

    void on_OuvrirSiteWeb_clicked();

    void on_Contacts_clicked();

    void on_OuvrirNavigateur_clicked();

    void on_ScaleFactor_valueChanged(int value);

    void on_ScaleFactor_sliderReleased();

    void on_Power_clicked();

    void on_Reboot_clicked();

    void on_Deconnection_clicked();

    void on_Forum_clicked();

    void on_VocalFly_clicked();

    void on_GitHub_clicked();

private:
    Ui::MainWindow *ui;
    bool play = false;
};

#endif // MAINWINDOW_H
