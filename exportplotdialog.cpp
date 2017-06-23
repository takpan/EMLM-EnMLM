#include "exportplotdialog.h"
#include "ui_exportplotdialog.h"

ExportPlotDialog::ExportPlotDialog(PlotGraphs *graphToPlot, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExportPlotDialog)
{
    ui->setupUi(this);

    pg = graphToPlot;

//    if (fileType == ".pdf")
//        ui->fileTypeComboBox->setCurrentIndex(0);
//    else if (fileType == ".png")
//        ui->fileTypeComboBox->setCurrentIndex(1);
//    else if (fileType == ".jpg")
//        ui->fileTypeComboBox->setCurrentIndex(2);
//    else if (fileType == ".bmp")
//        ui->fileTypeComboBox->setCurrentIndex(3);

    fileType = ".pdf";
    ui->fileTypeComboBox->setCurrentIndex(0);
    ui->widthSpinBox->setValue(1000);
    ui->heightSpinBox->setValue(500);
    ui->folderNameLineEdit->setText(QDir::currentPath());
}

ExportPlotDialog::~ExportPlotDialog()
{
    delete ui;
}

void ExportPlotDialog::on_buttonBox_accepted()
{
    bool write = true;

    if(!QDir(fileFolderPath).exists())
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText(fileFolderPath + " folder does not exist.");
        msgBox.setInformativeText("Do you wnat to create it?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        int ret = msgBox.exec();
        if(ret == QMessageBox::Yes)
        {
            if(QDir().mkdir(fileFolderPath) == false)
            {

                write = false;
                QMessageBox::information(this, "Failed to plot","Invalid path.");
            }
        }
        else
        {
            write = false;
            QMessageBox::information(this, "Plot aborted","No plot exported.");
            ui->folderNameLineEdit->setText(QDir::currentPath());
        }
    }
    else if((new QFile(fileFolderPath + fileName + fileType))->exists())
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText(fileFolderPath + fileName + fileType + " already exist");
        msgBox.setInformativeText("Do you wnat to overwrite it?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        int ret = msgBox.exec();
        if(ret != QMessageBox::Yes)
        {
            write = false;
            QMessageBox::information(this, "Plot aborted","Plot did not exported.");
        }
    }
    filePath = fileFolderPath + fileName + fileType;

    if (fileType == ".pdf")
        pg->savePdf(filePath, 0, width, height);
    else if (fileType == ".png")
        pg->savePng(filePath, width, height);
    else if (fileType == ".jpg")
        pg->saveJpg(filePath, width, height);
    else if (fileType == ".bmp")
        pg->saveBmp(filePath, width, height);

}

void ExportPlotDialog::on_fileTypeComboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        fileType = ".pdf";
        break;
    case 1:
        fileType = ".png";
        break;
    case 2:
        fileType = ".jpg";
        break;
    case 3:
        fileType = ".bmp";
        break;
    default:
        break;
    }
}

void ExportPlotDialog::on_widthSpinBox_valueChanged(int arg1)
{
    width = arg1;
}

void ExportPlotDialog::on_heightSpinBox_valueChanged(int arg1)
{
    height = arg1;
}

void ExportPlotDialog::on_fileNameLineEdit_textChanged(const QString &arg1)
{
    fileName = arg1;
}

void ExportPlotDialog::on_folderNameLineEdit_textChanged(const QString &arg1)
{
    fileFolderPath = arg1;
}

void ExportPlotDialog::on_browsePushButton_clicked()
{
    fileFolderPath = QFileDialog::getExistingDirectory(this, "Select folder", "C:\\");
    ui->folderNameLineEdit->setText(fileFolderPath);
}

void ExportPlotDialog::fillForm()
{
    if (fileType == ".pdf")
        ui->fileTypeComboBox->setCurrentIndex(0);
    else if (fileType == ".png")
        ui->fileTypeComboBox->setCurrentIndex(1);
    else if (fileType == ".jpg")
        ui->fileTypeComboBox->setCurrentIndex(2);
    else if (fileType == ".bmp")
        ui->fileTypeComboBox->setCurrentIndex(3);

    ui->widthSpinBox->setValue(width);
    ui->heightSpinBox->setValue(height);
    ui->fileNameLineEdit->setText(fileName);
    ui->folderNameLineEdit->setText(fileFolderPath);
}
