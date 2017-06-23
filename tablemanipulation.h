#ifndef TABLEMANIPULATION_H
#define TABLEMANIPULATION_H

#include <QTableWidget>


class TableManipulation
{
public:
    TableManipulation();

    void createTable(QTableWidget *table, int rows, int columns);

    void addRows(QTableWidget *table, int rows);

    void addColumns(QTableWidget *table, int columns);

    void addColumns(QTableWidget *table, int position, int columns);

    void removeRows(QTableWidget *table, int rows);

    void addIndex(QTableWidget *table, int start);

    void addIndex(QTableWidget *table, int column, int start);

    void addIndex(QTableWidget *table, int column, int start, int base);

    void create_ykj_headers();

    bool checkTable(QTableWidget *table);

    bool checkColumn(QTableWidget *table, const int &columnIndex);

    bool checkPbCol(QTableWidget *table, const int &pbColInd);

    void fillTable(QTableWidget *table, QVector<QString> header, QVector<QVector<QString>> &data);

    bool fillRow(QTableWidget *table, const int &rowIndex, const QVector<double> &data);

    bool fillColumn(QTableWidget *table, const int &columnIndex, const QVector<double> &data);

    bool fillColumn(QTableWidget *table, const int &columnIndex, const QVector<int> &data);

    bool fillColumn(QTableWidget *table, const int &columnIndex, const QVector<QString> &data);

    bool fillNColumn(QTableWidget *table, const int &columnIndex, QVector<int> &data, QVector<QString> modelType);

    bool searchCell(QTableWidget *table, const int &column, const QString &value);

    void clearColumn(QTableWidget *table, const int &columnIndex);

    QVector<QVector<QString>> rowsToColumns(QVector<QVector<QString>> &data);


    //void fillRow(QTableWidget *table);
};

#endif // TABLEMANIPULATION_H
