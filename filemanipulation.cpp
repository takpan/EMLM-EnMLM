#include "customfunctions.h"

bool findHeaderLine(QTextStream &stream, QChar &delim, int &columns)
{
    QStringList parts;
    QString line;
    bool headerFound;
    headerFound = false;

    while(headerFound == false && !(line = stream.readLine()).isNull())
    {
        if(line[0] == 'k')
        {
            delim =  line[1];
            parts = line.split(delim);
            if((columns = parts.length()) >= 3 && parts[1] == "b")
            {
                switch (columns)
                {
                case 3:
                    if(parts[2] == "a")
                        headerFound = true;
                    break;
                case 4:
                    if(parts[2] == "t" && parts[3] == "a")
                        headerFound = true;
                    break;
                case 5:
                    if(parts[2] == "t" && parts[3] == "a" && parts[4] == "pb")
                        headerFound = true;
                    break;
                default:
                    break;
                }
            }
        }
    }
    return headerFound;
}

QString findFirstDataLine(QTextStream &stream, const QChar &delim, const int &columns)
{
    QString line;
    QStringList parts;
    bool dataFound;

    dataFound = false;
    while(dataFound == false && !(line = stream.readLine()).isNull())
    {
        if((line.split(delim)).length() == columns)
            dataFound = true;
    }
    return line;
}

bool returnLineData(const QString &line, const QChar &delim, QStringList &parts, const int &columns)
{
    bool ok;

    ok = false;
    parts = line.split(delim, QString::KeepEmptyParts);
    if(parts.length() == columns)
        ok = true;

    return ok;
}

int fillInputVectorsFromFile(QTextStream &stream, QVector<int> &b, QVector<int> &t, QVector<double> &a, QVector<double> &pbin)
{
    QChar delim;
    QString line;
    QStringList parts;
    int columns, currRow;
    int res;

    res = 0;
    if(findHeaderLine(stream, delim, columns))
    {
        if((line = findFirstDataLine(stream, delim, columns)) != NULL)
        {
            currRow = -1;
            do
            {
                if(returnLineData(line, delim, parts, columns))
                {
                    currRow++;
                    b.resize(currRow+1);
                    a.resize(currRow+1);
                    t.resize(currRow+1);
                    pbin.resize(currRow+1);
                    b[currRow] = (new QString(parts[1]))->toInt();
                    if(columns == 3)
                        a[currRow] = (new QString(parts[2]))->toInt();

                    if(columns >= 4)
                    {
                        t[currRow] = (new QString(parts[2]))->toInt();
                        a[currRow] = (new QString(parts[3]))->toInt();

                    }
                    if(columns == 5)
                    {
                        pbin[currRow] = (new QString(parts[4]))->toInt();
                    }
                }
                else
                {
                    res = 1;    //QMessageBox::warning(mw, "Warning","Some of the data did not insert.");
                    break;
                }
            }
            while(!(line = stream.readLine()).isNull());
        }
        else
            res = 3;    //QMessageBox::warning(this, "Error","No data found or no appropriate data format.");
    }
    else
        res = 2;    //QMessageBox::warning(this, "Error","No header found.");

    return res;
}
