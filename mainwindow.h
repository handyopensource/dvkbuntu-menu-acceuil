#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    float scale = 1.8;
    qreal myscale = scale * 10;
    //QSlider ScaleFactor();
    //ScaleFactor().setValue(myscale);
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ConfigORCA_clicked();

    void on_Discord_clicked();

    void on_Forum_clicked();

    void on_OuvrirKmag_clicked();

    void on_OuvrirSiteWeb_clicked();

    void on_Contacts_clicked();

    void on_OuvrirChromium_clicked();

    void on_ScaleFactor_valueChanged(int value);

    void on_ScaleFactor_sliderReleased();

    void on_Power_clicked();

    void on_Reboot_clicked();

    void on_Deconnection_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
