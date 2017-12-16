#-------------------------------------------------
#
# Project created by QtCreator 2017-12-15T16:48:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pic10chw4newversion2
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


SOURCES += \
        main.cpp \
    airplane.cpp \
    missile.cpp \
    explode.cpp \
    sky.cpp

HEADERS += \
    airplane.h \
    missile.h \
    explode.h \
    sky.h \
    pub.h

FORMS +=

RESOURCES += \
    useless.qrc \
    planeimages.qrc

DISTFILES += \
    ../../images/2.gif \
    ../../images/3.gif \
    ../../images/4.gif \
    ../../images/5.gif \
    ../../images/6.gif \
    ../../images/7.gif \
    ../../images/8.gif \
    ../../images/9.gif \
    ../../images/missileL.gif \
    ../../images/missileLD.gif \
    ../../images/missileLU.gif \
    ../../images/missileR.gif \
    ../../images/missileRD.gif \
    ../../images/missileRU.gif \
    ../../images/missileU.gif \
    ../../images/skypicture5.jpeg \
    ../../images/airplaneD.png \
    ../../images/airplaneU.png \
    ../../images/logo.png
