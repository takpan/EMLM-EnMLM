#ifndef IMPORTEXPORTDIALOG_H
#define IMPORTEXPORTDIALOG_H

#include <QDialog>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>

namespace Ui {
class ExportDialog;
}

class ExportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExportDialog(QWidget *parent = 0);
    ~ExportDialog();

signals:
    //void returnValues(QString currFileExt, QString delim, QString currFilename, QString currFolder);
    void returnPath(QString path, bool write, QString currFileExt, QString delim);

public slots:
    //void receivePath(QString currFileExt, QString delim, QString currFilename, QString currFolder);


private slots:
    void on_txtRadioButton_toggled(bool checked);

    void on_buttonBox_accepted();

    void on_selDelimComboBox_currentIndexChanged(int index);

    void on_fileNameLineEdit_textChanged(const QString &arg1);

    void on_folderNameLineEdit_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::ExportDialog *ui;

    int cftype;
    QString dl, fileName, folderName, filePath, cfile, cfolder, cfext, path;
};

#endif // IMPORTEXPORTDIALOG_H
