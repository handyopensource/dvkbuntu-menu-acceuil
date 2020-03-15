#-------------------------------------------------
#
# Project created by QtCreator 2019-06-19T22:33:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = DVKBuntuAcceuil
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h \
    mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    images/DVKBuntu-etoiles-filantes.jpg \
    images/favicon.svg \
    images/Firefox_Logo.svg \
    images/kmag.svg \
    images/Orca.svg \
    images/Discord.svg \
    images/Logo.png \
    images/Forum.png \
    kcmaccess.desktop \
    images/NoComprendo.png \
    images/NoComprendo.jpg \
    Sound/10-DiscordLink.ogg \
    Sound/11-Email.ogg \
    Sound/12-Shutdown.ogg \
    Sound/13-Reboot.ogg \
    Sound/14-LeaveSession.ogg \
    Sound/5-browser.ogg \
    Sound/6-Kmag.ogg \
    Sound/7-AccesHandicap.ogg \
    Sound/8-SiteWeb.ogg \
    Sound/9-nocomprendo.ogg \
    Sound/1-connexion_session.ogg \
    Sound/2-bouton_reboot.ogg \
    Sound/3-bouton_shutdown.ogg \
    Sound/4-bouton_delog.ogg \
    Sound/1-connexion_session.ogg.wav \
    Sound/2-bouton_reboot.ogg.wav \
    Sound/3-bouton_shutdown.ogg.wav \
    Sound/4-bouton_delog.ogg.wav \
    Sound/5-browser.ogg.wav \
    Sound/6-Kmag.ogg.wav \
    Sound/7-AccesHandicap.ogg.wav \
    Sound/8-SiteWeb.ogg.wav \
    Sound/9-nocomprendo.ogg.wav \
    Sound/10-DiscordLink.ogg.wav \
    Sound/11-Email.ogg.wav \
    Sound/12-Shutdown.ogg.wav \
    Sound/13-Reboot.ogg.wav \
    Sound/14-LeaveSession.ogg.wav

RESOURCES += \
    resources.qrc
