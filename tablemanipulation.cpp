#include "tablemanipulation.h"

TableManipulation::TableManipulation()
{

}

void TableManipulation::createTable(QTableWidget *table, int rows, int columns)
{
    // resize table according to rows/columns parameters
    table->setColumnCount(columns);
    table->setRowCount(rows);

    // create cells
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            table->setItem(i,j,new QTableWidgetItem());
            table->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
}

void TableManipulation::addRows(QTableWidget *table, int rows)
{
    int r, c;

    r = table->rowCount();
    c = table->columnCount();
    for(int i=r; i<r+rows; i++)
    {
        table->insertRow(i);
        for(int j=0; j<c; j++)
        {
            table->setItem(i,j,new QTableWidgetItem);
            table->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
}

void TableManipulation::removeRows(QTableWidget *table, int rows)
{
    int r;

    r = table->rowCount()-1;    // finds the last existing row index of the table
    for(int i=0; i<rows; i++)
        table->removeRow(r-1);
}

void TableManipulation::addColumns(QTableWidget *table, int columns)
{
    int r, c;

    r = table->rowCount();
    c = table->columnCount();
    for(int i=c; i<c+columns; i++)
    {
        table->insertColumn(i);
        for(int j=0; j<r; j++)
        {
            table->setItem(i,j,new QTableWidgetItem);
            table->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
}

void TableManipulation::addColumns(QTableWidget *table, int position, int columns) // position = index of first new column
{
    int r, c;

    r = table->rowCount();
    c = table->columnCount();
    for(int i=0; i<columns; i++)
    {
        table->insertColumn(position + i);
        for(int j=0; j<r; j++)
        {
            table->setItem(i,j,new QTableWidgetItem);
            table->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
}

void TableManipulation::addIndex(QTableWidget *table, int start)
{
    int r;

    r = table->rowCount();
    for(int i=0; i<r; i++)
        table->item(i,0)->setText(QString::number(start+i));
}

void TableManipulation::addIndex(QTableWidget *table, int column, int start)
{
    int r;

    r = table->rowCount();
    for(int i=0; i<r; i++)
        table->item(i,column)->setText(QString::number(start+i));
}

void TableManipulation::addIndex(QTableWidget *table, int column, int start, int base)
{
    int r;

    r = table->rowCount();
    for(int i=base; i<r; i++)
        table->item(i,column)->setText(QString::number(i+1));
}

bool TableManipulation::checkTable(QTableWidget *table)
{
    bool flag = true;
    int r, c;

    r = table->rowCount();
    c = table->columnCount();

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(table->item(i,j)->text().isEmpty())
            {
                flag = false;
                return flag;
            }
        }
    }
    return flag;
}

bool TableManipulation::checkColumn(QTableWidget *table, const int &columnIndex)
{
    int i, numOfRows;
    bool ok;

    numOfRows = table->rowCount();
    ok = true;
    i = 0;

    while (i < numOfRows && ok == true)
    {
        if (table->item(i, columnIndex)->text().isEmpty())
            ok = false;

        i++;
    }
    return ok;
}

bool TableManipulation::checkPbCol(QTableWidget *table, const int &pbColInd)
{
    bool flag = true;
    int r;

    r = table->rowCount();

    for(int i=0; i<r; i++)
    {
        if(table->item(i, pbColInd)->text().toDouble() == 0 || table->item(i, pbColInd)->text().toDouble() > 1)
        {
            flag = false;
            return flag;
        }
    }
    return flag;
}

bool TableManipulation::searchCell(QTableWidget *table, const int &column, const QString &value)
{
    bool valueFound;
    int rows;

    valueFound = false;
    rows = table->rowCount();

    for (int i = 0; i < rows; i++)
        if(table->item(i, column)->text() == value)
            valueFound = true;

    return valueFound;
}

void TableManipulation::fillTable(QTableWidget *table, QVector<QString> header, QVector<QVector<QString>> &data)
{
    QVector<QVector<QString>> transposedMatrix;
    int r, columns;

    r = data.size();
    columns = header.size();
    table->setRowCount(0);  // remove all rows
    table->setRowCount(r);
    transposedMatrix = rowsToColumns(data);
    createTable(table, r, 7);

    addIndex(table, 1);
    for (int i = 0; i < columns; i++)
    {
        if (header[i] == "a")
            fillColumn(table, 1, transposedMatrix[i]);
        else if (header[i] == "b")
            fillColumn(table, 2, transposedMatrix[i]);
        else if (header[i] == "t")
            fillColumn(table, 3, transposedMatrix[i]);
        else if (header[i] == "N")
            fillColumn(table, 4, transposedMatrix[i]);
        else if (header[i] == "Pb")
            fillColumn(table, 5, transposedMatrix[i]);
        else if (header[i] == "model")
            fillColumn(table, 6, transposedMatrix[i]);
    }
}

bool TableManipulation::fillRow(QTableWidget *table, const int &rowIndex, const QVector<double> &data)
{
    int numOfColumns;
    bool ok;

    numOfColumns = table->columnCount() - 2;
    ok = false;

    if (numOfColumns == data.size())
    {
        for (int i = 1; i <= numOfColumns; i++)
            table->item(rowIndex, i)->setText(QString::number(data[i - 1]));

        ok = true;
    }
    return ok;
}

bool TableManipulation::fillColumn(QTableWidget *table, const int &columnIndex, const QVector<double> &data)
{
    int numOfRows;
    bool ok;

    numOfRows = table->rowCount();
    ok = false;

    if (numOfRows == data.size())
    {
        for (int i = 0; i < numOfRows; i++)
            table->item(i, columnIndex)->setText(QString::number(data[i]));

        ok = true;
    }
    return ok;
}

bool TableManipulation::fillColumn(QTableWidget *table, const int &columnIndex, const QVector<int> &data)
{
    int numOfRows;
    bool ok;

    numOfRows = table->rowCount();
    ok = false;

    if (numOfRows == data.size())
    {
        for (int i = 0; i < numOfRows; i++)
            table->item(i, columnIndex)->setText(QString::number(data[i]));

        ok = true;
    }
    return ok;
}

bool TableManipulation::fillColumn(QTableWidget *table, const int &columnIndex, const QVector<QString> &data)
{
    int numOfRows;
    bool ok;

    numOfRows = table->rowCount();
    ok = false;

    if (numOfRows == data.size())
    {
        for (int i = 0; i < numOfRows; i++)
            table->item(i, columnIndex)->setText(data[i]);

        ok = true;
    }
    return ok;
}

bool TableManipulation::fillNColumn(QTableWidget *table, const int &columnIndex, QVector<int> &data, QVector<QString> modelType)
{
    int numOfRows;
    bool ok;

    numOfRows = table->rowCount();
    ok = false;

    if (numOfRows == data.size())
    {
        for (int i = 0; i < numOfRows; i++)
            if (modelType[i] == "Erlang")
                table->item(i, columnIndex)->setText("n/a");
            else if (modelType[i] == "Engset")
                table->item(i, columnIndex)->setText(QString::number(data[i]));

        ok = true;
    }
    return ok;
}

void TableManipulation::clearColumn(QTableWidget *table, const int &columnIndex)
{
    for (int i = 0; i < table->rowCount(); i++)
        table->item(i, columnIndex)->setText("");
}

QVector<QVector<QString>> TableManipulation::rowsToColumns(QVector<QVector<QString>> &data)
{
    QVector<QVector<QString>> transposedMatrix;
    int numOfRows, numOfColumns;

    numOfRows = data.size();
    numOfColumns = data[0].size();
    transposedMatrix.resize(numOfColumns);
    for (int i = 0; i < numOfColumns; i++)
        transposedMatrix[i].resize(numOfRows);

    for (int i = 0; i < numOfRows; i++)
    {
        for (int j = 0; j < numOfColumns; j++)
            transposedMatrix[j][i] = data[i][j];
    }

    return transposedMatrix;
}

void TableManipulation::create_ykj_headers()
{

}




