#-------------------------------------------------
#
# Project created by QtCreator 2018-01-12T22:50:27
#
#-------------------------------------------------

QT       += core gui \
            sql \
            printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = invoice_manager
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
        mainwindow.cpp \
    receiver_settings.cpp \
    invoice_settings.cpp \
    article_settings.cpp \
    article2invoice_settings.cpp

HEADERS += \
        mainwindow.h \
    receiver_settings.h \
    invoice_settings.h \
    constant_defs.h \
    article_settings.h \
    article2invoice_settings.h

FORMS += \
        mainwindow.ui \
    receiver_settings.ui \
    invoice_settings.ui \
    article_settings.ui \
    article2invoice_settings.ui
