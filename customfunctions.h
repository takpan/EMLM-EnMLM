#ifndef CUSTOMFUNCTIONS
#define CUSTOMFUNCTIONS

#include <QTextStream>
#include <QTableWidget>
#include <QMessageBox>
#include "mainwindow.h"

bool findHeaderLine(QTextStream &stream, QChar &delim, int &columns);

QString findFirstDataLine(QTextStream &stream, const QChar &delim, const int &columns);

bool returnLineData(const QString &line, const QChar &delim, QStringList &parts, const int &columns);

int fillInputVectorsFromFile(QTextStream &stream, QVector<int> &b, QVector<int> &t, QVector<double> &a, QVector<double> &pbin);

#endif // CUSTOMFUNCTIONS

