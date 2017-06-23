#ifndef PLOTOUTPUTFORM_H
#define PLOTOUTPUTFORM_H

#include <QWidget>
#include <QDialog>
#include <QVector>
#include <QTableWidget>
#include "tablemanipulation.h"
#include "kaufmanroberts.h"
#include "exportplotdialog.h"
#include "exportdialog.h"

namespace Ui {
class PlotOutputDialog;
class ExportPlotDialog;
}

class PlotOutputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlotOutputDialog(QWidget *parent = 0);
    ~PlotOutputDialog();

    void fillForm();

    int searchValueInVector(const QVector<QVector<double>> &vector, const int &column, const double &value);

    QVector<QVector<double>> calculate_aInputVector(const QVector<QVector<double>> &ax);

    QVector<QVector<double>> calculate_aInputVector(const QVector<QVector<double>> &ax, const QVector<double> &aErl, int &numOfSteps);

    void changeAMaxColumn(QTableWidget *table, int columnIndex, const int &numOfSteps);

public slots:

    void receiveGeneralData(const int &c, const int &k, QString modelType, const QVector<int> &b);

    void receiveTrunkReservation(const QVector<int> &t);

    void receiveErlangData(const QVector<double> &aErl);

    void receiveEngsetData(const QVector<double> &aEng, const QVector<int> &nEng);

    void receiveErlEngData(const QVector<double> &aErlEng, const QVector<int> &nErlEng, QVector<QString> modelType);

    void receiveExportTablesPath(QString path, bool write, QString fileExt, QString delim);

private slots:
    void on_setPushButton_clicked();

    void on_selServClassComboBox_currentIndexChanged(int index);

    void on_plotPushButton_clicked();

    void on_aMinLineEdit_textChanged(const QString &arg1);

    void on_stepLlineEdit_textChanged(const QString &arg1);

    void on_numOfStepsLineEdit_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_aMinLineEdit_returnPressed();

    void on_stepLlineEdit_returnPressed();

    void on_numOfStepsLineEdit_returnPressed();

    void on_plotShowCheckBox_toggled(bool checked);

    void on_plotServClassComboBox_currentIndexChanged(int index);

    void on_backPushButton_clicked();

    void on_exportPushButton_clicked();

    void on_rescalePushButton_clicked();

    void on_scatterComboBox_currentIndexChanged(int index);

    void on_exportTablesPushButton_clicked();

    void on_pbComboBox_currentIndexChanged(int index);

private:
    Ui::PlotOutputDialog *ui;
    ExportPlotDialog *epd;
    ExportDialog *etd;
    int c, k, servClassIndex, aTableMaxRowIndex, numOfSteps;
    double aMinTemp, stepTemp, aMaxTemp;
    bool trres, write;
    QString modelType, exportTablesPath, fileExt, delim;
    QVector<int> b, t;
    QVector<double> a, linkUt;
    QVector<QVector<double>> ax, aCalc, pbOut, eArray;
    QVector<QString> colorList, modelTypeVector;
    QTableWidget *inputTable;
    TableManipulation *tb;
    KaufmanRoberts *kr;
    QVector<QCPScatterStyle::ScatterShape> scatterShapes;

    // Erlang:

    // Engset:
    QVector<int> nEng;

    // Erlang - Engset:
    QVector<int> nErlEng;
};

#endif // PLOTOUTPUTFORM_H
