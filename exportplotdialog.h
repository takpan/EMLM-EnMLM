#ifndef EXPORTPLOTDIALOG_H
#define EXPORTPLOTDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include "plotgraphs.h"

//class PlotGraphs;

namespace Ui {
class ExportPlotDialog;
}

class ExportPlotDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExportPlotDialog(PlotGraphs *graphToPlot, QWidget *parent = 0);
    ~ExportPlotDialog();

    void fillForm();

private slots:
    void on_buttonBox_accepted();

    void on_fileTypeComboBox_currentIndexChanged(int index);

    void on_widthSpinBox_valueChanged(int arg1);

    void on_heightSpinBox_valueChanged(int arg1);

    void on_fileNameLineEdit_textChanged(const QString &arg1);

    void on_folderNameLineEdit_textChanged(const QString &arg1);

    void on_browsePushButton_clicked();

private:
    Ui::ExportPlotDialog *ui;

    int width, height, cftype;
    QString fileType, fileName, fileFolderPath, filePath;
    PlotGraphs *pg;
};

#endif // EXPORTPLOTDIALOG_H
