#ifndef TEXTFILEMANIPULATION_H
#define TEXTFILEMANIPULATION_H

#include <QTextStream>
#include <QTableWidget>
#include <QMessageBox>
#include <QFile>
#include <QList>

class TextFileManipulation
{
public:
    TextFileManipulation();

    bool findHeader(QTextStream &stream, QVector<QString> &header);

    bool findFirstDataLine(QTextStream &stream);

    bool returnLineData(const QString &line, const QChar &delim, QStringList &parts, const int &columns);

    QVector<QVector<QString>> readFile(QFile &file, QVector<QString> &header, QMessageBox &message);

private:
    QString line, delim;
    QVector<QVector<QString>> fileData;
    int columns, dataRows, totalRows;
    qint64 headerPos, dataPos;

};

#endif // TEXTFILEMANIPULATION_H
