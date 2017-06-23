#include "textfilemanipulation.h"

TextFileManipulation::TextFileManipulation()
{

}

bool TextFileManipulation::findHeader(QTextStream &stream, QVector<QString> &header)
{
    QStringList parts;
    bool firstColFound, headerFound;

    firstColFound = false;
    headerFound = false;
    columns = header.size();
    headerPos = 0;

    while(headerFound == false && !(line = stream.readLine()).isNull())
    {
        if (line.length() >= header[0].size())
        {
            firstColFound = true;
            for(int i = 0; i < header[0].size(); i++)
            {
                if(line[i] != header[0][i])
                    firstColFound = false;
            }
        }
        if (firstColFound == true)
        {
            delim =  line[header[0].size()];
            parts = line.split(delim);
            if(columns == parts.length())
            {
                headerFound = true;
                for (int i = 0; i < columns; i++)
                {
                    if (header[i] != parts[i])
                    {
                        headerFound = false;
                        break;
                    }
                }
            }
        }
        if (!headerFound)
            headerPos = stream.pos();
    }
    return headerFound;
}

bool TextFileManipulation::findFirstDataLine(QTextStream &stream)
{
    bool dataFound;

    dataFound = false;
    dataPos = stream.pos();
    while(dataFound == false && !(line = stream.readLine()).isNull())
    {
        if((line.split(delim)).length() == columns)
            dataFound = true;

        if(!dataFound)
            dataPos = stream.pos();
    }
    return dataFound;
}

bool TextFileManipulation::returnLineData(const QString &line, const QChar &delim, QStringList &parts, const int &columns)
{
    bool ok;

    ok = false;
    parts = line.split(delim, QString::KeepEmptyParts);
    if(parts.length() == columns)
        ok = true;

    return ok;
}

QVector<QVector<QString>> TextFileManipulation::readFile(QFile &file, QVector<QString> &header, QMessageBox &message)
{
    QStringList parts;

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

        if (findHeader(stream, header))
        {
            fileData.resize(1);
            if (findFirstDataLine(stream))
            {
                //line = stream.readLine(dataPos);
                int i = 0;
                do
                {
                    if((parts = line.split(delim)).size() != columns)
                    {
                        message.setIcon(QMessageBox::Warning);
                        message.setText("File reading stopped.");
                        message.setInformativeText("Inappropriate row format encountered.");
                        break;
                    }
                    else
                    {
                        fileData.resize(i+1);
                        fileData[i].resize(columns);
                        parts = line.split(delim);
                        for (int j = 0; j < columns; j++)
                        {
                            fileData[i][j] = parts[j];
                        }
                        i++;
                    }
                }
                while (!(line = stream.readLine()).isNull());
                message.setIcon(QMessageBox::Information);
                message.setText("Successful import.");
                message.setInformativeText("File imported successfully.");

            }
            else
            {
                message.setIcon(QMessageBox::Warning);
                message.setText("Could not find appropriate data.");
                message.setInformativeText("Data din not imported.");
            }

        }
        else
        {
            message.setIcon(QMessageBox::Warning);
            message.setText("Could not open the file.");
            message.setInformativeText("Header did not find");
        }
    }
    return fileData;
}
