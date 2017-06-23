#-------------------------------------------------
#
# Project created by QtCreator 2015-10-19T23:12:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Thesis_app
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    kaufmanroberts.cpp \
    tablemanipulation.cpp \
    exportdialog.cpp \
    exportdialog.cpp \
    textfilemanipulation.cpp \
    plotoutputdialog.cpp \
    qcustomplot.cpp \
    plotgraphs.cpp \
    exportplotdialog.cpp

HEADERS  += mainwindow.h \
    kaufmanroberts.h \
    tablemanipulation.h \
    exportdialog.h \
    ui_importexportdialog.h \
    exportdialog.h \
    textfilemanipulation.h \
    plotoutputdialog.h \
    qcustomplot.h \
    plotgraphs.h \
    exportplotdialog.h

FORMS    += mainwindow.ui \
    exportdialog.ui \
    exportdialog.ui \
    plotoutputdialog.ui \
    exportplotdialog.ui
