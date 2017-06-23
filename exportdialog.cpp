#include "exportdialog.h"
#include "ui_exportdialog.h"

ExportDialog::ExportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExportDialog)
{
    ui->setupUi(this);
    ui->txtRadioButton->setChecked(true);
    cfext = ".txt";
    dl = "\t";
    cfile = "";
    cfolder = QDir::currentPath();
    ui->folderNameLineEdit->setText(cfolder);
}

ExportDialog::~ExportDialog()
{
    delete ui;
}

void ExportDialog::on_txtRadioButton_toggled(bool checked)
{
    if(checked)
    {
        ui->selDelimComboBox->setEnabled(false);
        cfext = ".txt";
        dl = "\t";
    }
    else
    {
        ui->selDelimComboBox->setEnabled(true);
        cfext = ".csv";
        dl = ",";
    }
}

void ExportDialog::on_selDelimComboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        dl = ",";
        break;
    case 1:
        dl = ";";
        break;
    default:
        break;
    }
}

void ExportDialog::on_fileNameLineEdit_textChanged(const QString &arg1)
{
    cfile = arg1;
}

void ExportDialog::on_folderNameLineEdit_textChanged(const QString &arg1)
{
    cfolder = arg1;
}

void ExportDialog::on_pushButton_clicked()
{
    cfolder = QFileDialog::getExistingDirectory(this, "Select folder", cfolder);
    ui->folderNameLineEdit->setText(cfolder);
}

void ExportDialog::on_buttonBox_accepted()
{
    bool write = true;

    if(!QDir(cfolder).exists())
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText(cfolder + " folder does not exist.");
        msgBox.setInformativeText("Do you wnat to create it?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        int ret = msgBox.exec();
        if(ret == QMessageBox::Yes)
        {
            if(QDir().mkdir(cfolder) == false)
            {

                write = false;
                QMessageBox::information(this, "Failed to export data","Invalid path. Data did not export to file.");
            }
        }
        else
        {
            write = false;
            QMessageBox::information(this, "Failed to export data","Data did not export to file.");
            ui->folderNameLineEdit->setText(QDir::currentPath());
        }
    }
    else if((new QFile(cfolder + cfile + cfext))->exists())
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText(cfolder + cfile + cfext + " already exist");
        msgBox.setInformativeText("Do you wnat to overwrite it?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        int ret = msgBox.exec();
        if(ret != QMessageBox::Yes)
        {
            write = false;
            QMessageBox::information(this, "Export aborted","Data did not export to file.");
        }
    }

    emit returnPath(cfolder + "\\" + cfile + cfext, write, cfext, dl);
}

//void ExportDialog::receivePath(QString currFileExt, QString delim, QString currFilename, QString currFolder)
//{
//    cfext = currFileExt;
//    dl = delim;
//    cfile = currFilename;
//    cfolder = currFolder;

//    // fill form:
//    if(cfext == ".txt")
//        ui->txtRadioButton->setChecked(true);
//    else
//        ui->csvRadioButton->setChecked(true);

//    if(dl == ",")
//        ui->selDelimComboBox->setCurrentIndex(0);
//    else if(dl == ";")
//        ui->selDelimComboBox->setCurrentIndex(1);

//    ui->fileNameLineEdit->setText(cfile);
//    ui->folderNameLineEdit->setText(cfolder);
//}

//http://stackoverflow.com/questions/15833535/transfer-data-between-forms-in-qt
