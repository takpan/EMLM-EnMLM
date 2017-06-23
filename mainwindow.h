#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QFileDialog>
#include "kaufmanroberts.h"
#include "tablemanipulation.h"
#include "exportdialog.h"
#include "filemanipulation.h"
#include "customfunctions.h"
#include "textfilemanipulation.h"
#include "plotoutputdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QWidget *form1;
    QWidget *form2;
    KaufmanRoberts *kr;
    TableManipulation *tb;
    ExportDialog *d;
    ExportDialog *d2;
    PlotOutputDialog* pof;

    void createTable(QTableWidget *table, int rows, int columns);

    void addTableRow(QTableWidget *table, int row, int columns);

    void createTableRow(int row);

    QVector<QString> inputTableHeader();

    void fillVectors(QVector<QVector<QString>> data, QVector<QString> header);

signals:
    void passInputFileParams(QString currFileExt, QString delim, QString currFilename, QString currFolder);

    void passGeneralData(int c, int k, QString modelType, QVector<int> b);

    void passTrunkReservation(QVector<int> t);

    void passErlangData(QVector<double> aErl);

    void passEngsetData(QVector<double> aEng, QVector<int> nEng);

    void passErlEngData(QVector<double> aEng, QVector<int> nEng, QVector<QString> modelType);

public slots:
    void receivePath(QString path, bool write, QString currFileExt, QString delim);


private slots:

    void on_bLineEdit_textChanged(const QString &arg1);

    void on_selServClassComboBox_currentIndexChanged(int index);

    void on_numOfServClassSpinBox_valueChanged(int arg1);

    void on_linkCapacityLineEdit_textChanged(const QString &arg1);

    void on_setaRadioButton_toggled(bool checked);

    void on_aLineEdit_textChanged(const QString &arg1);

    void on_l_Or_v_LineEdit_textChanged(const QString &arg1);

    void on_mLineEdit_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_resultsPushButton_clicked();

    void on_trunkResLineEdit_textChanged(const QString &arg1);

    void on_trunkResCheckBox_toggled(bool checked);

    void on_selBlockProbRadioButton_toggled(bool checked);

    void on_blockProbLineEdit_textChanged(const QString &arg1);

    void on_bLineEdit_returnPressed();

    void on_trunkResLineEdit_returnPressed();

    void on_aLineEdit_returnPressed();

    void on_blockProbLineEdit_returnPressed();

    void on_l_Or_v_LineEdit_returnPressed();

    void on_mLineEdit_returnPressed();

    void on_linkCapacityLineEdit_returnPressed();

    void on_numOfServClassSpinBox_editingFinished();

    void on_exportInputPushButton_clicked();

    void on_importInputPushButton_clicked();

    void on_plotExportPushButton_clicked();

    void on_selectModelComboBox_currentIndexChanged(int index);

    void on_NLineEdit_textChanged(const QString &arg1);

    void on_NLineEdit_returnPressed();

    void on_erlangRadioButton_clicked(bool checked);

    void on_engsetRadioButton_clicked(bool checked);

private:
    Ui::MainWindow *ui;

    bool inputTableFilled, trres, linkcap, wr, importClicked;
    int bi, ni, ti, c, cout, k, servClassIndex, inputTableWidth, pbColInd, ft, cftype, v, numOfSources;
    double  ai, lv, m, pbi, lu;
    QString dl, impDelim, cfilepath, cfile, cfolder, cfext, inputParExpPath, inputParImpPath, inputParImpFolder;
    QVector<int> b, t, t0;
    QVector<double> q, p, pb, e, pbin, sumy, zeroRow;
    QVector<QVector<double>> y;

    // Erlang:
    double aiErl, lErl, mErl;
    bool setErl;
    QVector<double> aErl;

    // Engset:
    int niEng;
    double aiEng,vEng, mEng;
    bool setEng;
    QVector<int> nEng;
    QVector<double> aEng, aErlEq, qEng;

    // Erl - Eng:
    QVector<int> nErlEng;
    QVector<double> aErlEng, qErlEng;
    QVector<QString> modelType;
};

#endif // MAINWINDOW_H
