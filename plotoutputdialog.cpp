#include "plotoutputdialog.h"
#include "ui_plotoutputdialog.h"
#include "mainwindow.h"

PlotOutputDialog::PlotOutputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlotOutputDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Widget);

    // initialize pointers:
    tb = new TableManipulation;
    kr = new KaufmanRoberts;
    epd = NULL;
    etd = NULL;

    // initialize aTableMaxRowIndex:
    aTableMaxRowIndex = -1;

    // initialize input table and create cells:
    tb->addIndex(ui->aTableWidget, 1);
    ui->aTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->aTableWidget->horizontalHeader()->setDefaultSectionSize(60);
    ui->aTableWidget->verticalHeader()->setDefaultSectionSize(20);
    ui->aTableWidget->verticalHeader()->setVisible(false);
    ui->aTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    // initialize aStepsTableWidget:
    ui->aStepsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->aStepsTableWidget->horizontalHeader()->setDefaultSectionSize(75);
    ui->aStepsTableWidget->verticalHeader()->setDefaultSectionSize(20);
    ui->aStepsTableWidget->verticalHeader()->setVisible(false);
    ui->aStepsTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->pbOutTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->pbOutTableWidget->horizontalHeader()->setDefaultSectionSize(75);
    ui->pbOutTableWidget->verticalHeader()->setDefaultSectionSize(20);
    ui->pbOutTableWidget->verticalHeader()->setVisible(false);
    ui->pbOutTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->e_uTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->e_uTableWidget->horizontalHeader()->setDefaultSectionSize(75);
    ui->e_uTableWidget->verticalHeader()->setDefaultSectionSize(20);
    ui->e_uTableWidget->verticalHeader()->setVisible(false);
    ui->e_uTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    // initialize plot visibility:
    ui->plotShowCheckBox->setDisabled(true);
    ui->plotServClassComboBox->setDisabled(true);
    ui->scatterComboBox->setDisabled(true);
    ui->pbComboBox->setDisabled(true);


    // create colorList:
    colorList.resize(7);
    colorList[0] = "#FF0000";
    colorList[1] = "#FF8000";
    colorList[2] = "#009000";
    colorList[3] = "#00C4C4";
    colorList[4] = "#0000FF";
    colorList[5] = "#FF00FF";
    colorList[6] = "#A1A1A1";

    // create scatter vector:
    scatterShapes.resize(8);
    scatterShapes[0] = QCPScatterStyle::ssDisc;
    scatterShapes[1] = QCPScatterStyle::ssCircle;
    scatterShapes[2] = QCPScatterStyle::ssCross;
    scatterShapes[3] = QCPScatterStyle::ssPlus;
    scatterShapes[4] = QCPScatterStyle::ssSquare;
    scatterShapes[5] = QCPScatterStyle::ssStar;
    scatterShapes[6] = QCPScatterStyle::ssTriangle;
    scatterShapes[7] = QCPScatterStyle::ssTriangleInverted;
}

PlotOutputDialog::~PlotOutputDialog()
{
    delete ui;
}

//-----------------------------------------------------------------------------
// PRIVATE SLOTS:
//-----------------------------------------------------------------------------
void PlotOutputDialog::on_numOfStepsLineEdit_textChanged(const QString &arg1)
{
    int inputVal;
    bool ok;

    inputVal = arg1.toInt(&ok);
    if(!ok || inputVal < 0)
    {
        ui->numOfStepsLineEdit->setText("");
        changeAMaxColumn(ui->aTableWidget, 3, 0);
    }
    else
    {
        numOfSteps = inputVal;
        changeAMaxColumn(ui->aTableWidget, 3, numOfSteps);
    }
    ui->aStepsTableWidget->setRowCount(0);
    ui->pbOutTableWidget->setRowCount(0);
    ui->e_uTableWidget->setRowCount(0);
    ui->plotWidget->clearGraphs();
    ui->plotWidget->replot();
    ui->plotServClassComboBox->setDisabled(true);
    ui->plotShowCheckBox->setDisabled(true);
}

void PlotOutputDialog::on_aMinLineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);
    if(!ok || inputVal < 0)
    {
        ui->aMinLineEdit->setText("");
    }
    else
        aMinTemp = inputVal;

}

void PlotOutputDialog::on_stepLlineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);
    if(!ok || inputVal < 0)
    {
        ui->stepLlineEdit->setText("");
    }
    else
        stepTemp = inputVal;
}

void PlotOutputDialog::on_selServClassComboBox_currentIndexChanged(int index)
{
    int indexOfExistingItem;
    servClassIndex = index;
    if (ui->aTableWidget->rowCount() > 0 && index >=0)
    {
        if ((indexOfExistingItem = searchValueInVector(ax, 0, index + 1)) != -1)
        {
            ui->aMinLineEdit->setText(ui->aTableWidget->item(indexOfExistingItem, 1)->text());
            ui->stepLlineEdit->setText(ui->aTableWidget->item(indexOfExistingItem, 2)->text());
        }
        else
        {
            ui->aMinLineEdit->setText("");
            ui->stepLlineEdit->setText("");
        }
    }
}

void PlotOutputDialog::on_setPushButton_clicked()
{
    int indexOfExistingItem;

    if(ui->aMinLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input a(min).");
    else if(ui->stepLlineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input step.");
    else if(ui->numOfStepsLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input number of steps.");
    else
    {
        if (ax.size() > 0 && (indexOfExistingItem = searchValueInVector(ax, 0, ui->selServClassComboBox->currentText().toInt())) != -1)
        {
            // modify ax QVector:
            ax[indexOfExistingItem][1] = aMinTemp;
            ax[indexOfExistingItem][2] = stepTemp;
            ax[indexOfExistingItem][3] = aMinTemp +stepTemp * numOfSteps;
            // modify aTableWidget:
            ui->aTableWidget->item(indexOfExistingItem, 1)->setText(QString::number(ax[indexOfExistingItem][1]));
            ui->aTableWidget->item(indexOfExistingItem, 2)->setText(QString::number(ax[indexOfExistingItem][2]));
            ui->aTableWidget->item(indexOfExistingItem, 3)->setText(QString::number(ax[indexOfExistingItem][3]));
        }
        else
        {
            aTableMaxRowIndex += 1;
            ax.resize(ax.size() + 1);
            ax[aTableMaxRowIndex].resize(4);
            // fill ax QVector:
            ax[aTableMaxRowIndex][0] = servClassIndex + 1;
            ax[aTableMaxRowIndex][1] = aMinTemp;
            ax[aTableMaxRowIndex][2] = stepTemp;
            ax[aTableMaxRowIndex][3] = aMinTemp +stepTemp * numOfSteps;
            // fill aTableWidget:
            tb->addRows(ui->aTableWidget, 1);
            ui->aTableWidget->item(aTableMaxRowIndex, 0)->setText(QString::number(ax[aTableMaxRowIndex][0]));
            ui->aTableWidget->item(aTableMaxRowIndex, 1)->setText(QString::number(ax[aTableMaxRowIndex][1]));
            ui->aTableWidget->item(aTableMaxRowIndex, 2)->setText(QString::number(ax[aTableMaxRowIndex][2]));
            ui->aTableWidget->item(aTableMaxRowIndex, 3)->setText(QString::number(ax[aTableMaxRowIndex][3]));
            // change inputTableWidget cell value:
            ui->inputTableWidget->item(ui->selServClassComboBox->currentIndex(), 1)->setText("var");
            // selServClassComboBox index increment (+1):
            if(ui->selServClassComboBox->currentIndex() < ui->selServClassComboBox->count() - 1)
                ui->selServClassComboBox-> setCurrentIndex(servClassIndex + 1);

            // focus to aMinLineEdit
            ui->aMinLineEdit->setFocus();
        }
        if (ui->aStepsTableWidget->rowCount() > 0)
        {
            ui->aStepsTableWidget->setRowCount(0);
            ui->pbOutTableWidget->setRowCount(0);
            ui->e_uTableWidget->setRowCount(0);
            ui->plotWidget->clearGraphs();
        }
    }
    ui->plotWidget->clearGraphs();
    ui->plotWidget->replot();
    ui->plotServClassComboBox->setDisabled(true);
    ui->plotShowCheckBox->setDisabled(true);
}

void PlotOutputDialog::on_pushButton_clicked()
{
    int indexOfExistingItem;

    if (ax.size() > 0 && (indexOfExistingItem = searchValueInVector(ax, 0, ui->selServClassComboBox->currentText().toInt())) != -1)
    {
        ui->inputTableWidget->item(ui->selServClassComboBox->currentIndex(), 1)->setText(QString::number(a[ui->selServClassComboBox->currentIndex()]));
        ax.remove(indexOfExistingItem);
        ui->aTableWidget->removeRow(indexOfExistingItem);
        aTableMaxRowIndex -= 1;
    }
    if (ui->aStepsTableWidget->rowCount() > 0)
    {
        ui->aStepsTableWidget->setRowCount(0);
        ui->pbOutTableWidget->setRowCount(0);
        ui->e_uTableWidget->setRowCount(0);
        ui->plotWidget->clearGraphs();
        ui->plotWidget->replot();
    }
    ui->plotServClassComboBox->setDisabled(true);
    ui->plotShowCheckBox->setDisabled(true);
}

void PlotOutputDialog::on_plotPushButton_clicked()
{
    if(ui->numOfStepsLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input number of steps.");
    else
    {
        tb->createTable(ui->aStepsTableWidget, numOfSteps + 1, k + 1);
        tb->addIndex(ui->aStepsTableWidget, 0);
        aCalc = calculate_aInputVector(ax, a, numOfSteps);
        for (int i = 1; i <= k; i++)
        {
            ui->aStepsTableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem("a"+QString::number(i))); // fill horizontal header cells
        }
        for (int i = 0; i <= numOfSteps; i++)
        {
            for (int j = 0; j < k; j++)
                ui->aStepsTableWidget->item(i, 1+j)->setText(QString::number(aCalc[i][j], 'f', 4));
        }

        tb->createTable(ui->pbOutTableWidget, numOfSteps + 1, k + 1);
        tb->addIndex(ui->pbOutTableWidget, 0);
        if (modelType == "Erlang")
            pbOut = kr->calculate_pbArray(aCalc, c, b, t);
        else if (modelType == "Engset")
            pbOut = kr->calculate_pbArrayEngset(aCalc, c, b, t, nEng);
        else if (modelType == "ErlEng")
            pbOut = kr->calculate_pbArrayErlEng(aCalc, c, b, t, nErlEng, modelTypeVector);

        for (int i = 1; i <= k ; i++)
        {
            ui->pbOutTableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem("Pb"+QString::number(i))); // fill horizontal header cells
        }
        for (int i = 0; i <= numOfSteps; i++)
        {
            for (int j = 0; j < k; j++)
                ui->pbOutTableWidget->item(i, 1+j)->setText(QString::number(pbOut[i][j], 'g', 7));
        }

        tb->createTable(ui->e_uTableWidget, numOfSteps + 1, k + 2);
        tb->addIndex(ui->e_uTableWidget, 0);


        for (int i = 1; i <= k ; i++)
        {
            ui->e_uTableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem("E(n"+QString::number(i) + ")")); // fill horizontal header cells
        }
        ui->e_uTableWidget->setHorizontalHeaderItem(k + 1, new QTableWidgetItem("U"));

        eArray = kr->return_EArray();
        linkUt = kr->return_linkUt();

        for (int i = 0; i <= numOfSteps; i++)
        {
            for (int j = 0; j < k; j++)
                ui->e_uTableWidget->item(i, 1+j)->setText(QString::number(eArray[i][j], 'g', 7));

            ui->e_uTableWidget->item(i, k + 1)->setText(QString::number(linkUt[i], 'g', 7));
        }

        ui->plotWidget->createGraph(pbOut, colorList);
        ui->plotServClassComboBox->setEnabled(true);
        ui->plotShowCheckBox->setEnabled(true);
        ui->plotShowCheckBox->setChecked(true);
        ui->scatterComboBox->setEnabled(true);
        ui->pbComboBox->setEnabled(true);
    }
}

void PlotOutputDialog::on_plotShowCheckBox_toggled(bool checked)
{
    if(checked && ui->plotWidget->graphCount() > 0)
    {
        ui->plotWidget->graph(ui->plotServClassComboBox->currentIndex())->setVisible(true);
        ui->plotWidget->replot();
    }
    else
    {
        ui->plotWidget->graph(ui->plotServClassComboBox->currentIndex())->setVisible(false);
        ui->plotWidget->replot();
    }
}

void PlotOutputDialog::on_scatterComboBox_currentIndexChanged(int index)
{
    ui->plotWidget->graph(ui->plotServClassComboBox->currentIndex())->setScatterStyle(QCPScatterStyle(scatterShapes[index], 6));
    //ui->plotWidget->graph(ui->plotServClassComboBox->currentIndex())->setScatterStyle(QCPScatterStyle(scatterShapes.at(index), 6));
    ui->plotWidget->replot();
}

void PlotOutputDialog::on_rescalePushButton_clicked()
{
    ui->plotWidget->rescaleAxes(true);
    ui->plotWidget->axisRect()->setAutoMargins(QCP::msNone);
    //ui->plotWidget->axisRect()->setMargins(QMargins(50,20,100,15));
    //ui->plotWidget->plotLayout()->setMargins(*(new QMargins(10,20,30,50)));
    //ui->plotWidget->xAxis->setRangeUpper((ui->plotWidget->xAxis->range()).upper + 1);
    //ui->plotWidget->yAxis->setRangeUpper((ui->plotWidget->yAxis->range()).upper + 0.05*(ui->plotWidget->yAxis->range()).upper);
    ui->plotWidget->replot();
}

void PlotOutputDialog::on_plotServClassComboBox_currentIndexChanged(int index)
{
    if (ui->plotWidget->graphCount() > 0)
    {
        if(ui->plotWidget->graph(index)->visible())
            ui->plotShowCheckBox->setChecked(true);
        else
            ui->plotShowCheckBox->setChecked(false);

        ui->scatterComboBox->setCurrentIndex(scatterShapes.indexOf(ui->plotWidget->graph(index)->scatterStyle().shape()));
    }
}

void PlotOutputDialog::on_exportPushButton_clicked()
{
    if (epd == NULL)
        epd = new ExportPlotDialog(ui->plotWidget);

    epd->exec();
}

void PlotOutputDialog::on_exportTablesPushButton_clicked()
{
    if (etd == NULL)
        etd = new ExportDialog();

    QObject::connect(etd, SIGNAL(returnPath(QString, bool, QString, QString)), this, SLOT(receiveExportTablesPath(QString, bool, QString , QString)));
    etd->exec();

    if(etd->result() == QDialog::Accepted && write == true)
    {

        QFile file(exportTablesPath);
        if(file.open(QFile::WriteOnly | QFile::Truncate | QIODevice::Text))     // Truncate = delete existing content
        {
            QTextStream stream(&file);
            if(fileExt == ".txt")
            {
                stream << "***************************" << endl;
                stream << "*                         *" << endl;
                stream << "*      OUTPUT   DATA      *" << endl;
                stream << "*                         *" << endl;
                stream << "***************************" << endl << endl;

                stream << "step" << delim;
                for (int i = 1; i <= k; i++)
                    stream << "a" << i << delim;

                for (int i = 1; i <= k; i++)
                    stream << "Pb" << i << delim;

                for (int i = 1; i <= k; i++)
                    stream << "E(n" << i << ")" << delim;

                stream << "U";
                stream << endl;
                stream << "--------";
                for (int i = 0; i < k; i++)
                    stream << "------------------------------------------------";

                stream << "---------";
            }
            else if (fileExt == ".csv")
            {
                stream << "step" << delim;
                for (int i = 1; i <= k; i++)
                    stream << "a" << i << delim;

                for (int i = 1; i <= k; i++)
                    stream << "Pb" << i << delim;

                for (int i = 1; i <= k; i++)
                    stream << "E(n" << i << ")" << delim;

                stream << "U";
            }


            for (int i = 0; i <= numOfSteps; i++)
            {
                if(fileExt == ".txt")
                {
                    stream << endl << i << delim;

                    for (int j = 1; j <= k; j++)
                        stream << ui->aStepsTableWidget->item(i, j)->text() << delim;

                    for (int j = 1; j <= k; j++)
                        stream << ui->pbOutTableWidget->item(i, j)->text() << delim;

                    for (int j = 1; j <= k; j++)
                        stream << ui->e_uTableWidget->item(i, j)->text() << delim;

                    stream << ui->e_uTableWidget->item(i, k + 1)->text();
                }
                else if (fileExt == ".csv")
                {
                    stream << endl << i << delim;

                    for (int j = 0; j < k; j++)
                        stream << aCalc[i][j] << delim;

                    for (int j = 0; j < k; j++)
                        stream << pbOut[i][j] << delim;

                    for (int j = 0; j < k; j++)
                        stream << eArray[i][j] << delim;

                    stream << linkUt[i] << delim;
                }
            }
        }
    }
}

void PlotOutputDialog::on_backPushButton_clicked()
{
    this->close();
}

//-----------------------------------------------------------------------------
// PUBLIC SLOTS:
//-----------------------------------------------------------------------------

void PlotOutputDialog::receiveGeneralData(const int &c, const int &k, QString modelType, const QVector<int> &b)
{
    this->c = c;
    this->k = k;
    this->modelType = modelType;
    this->b = b;
}

 void PlotOutputDialog::receiveTrunkReservation(const QVector<int> &t)
 {
     this->t = t;
 }

void PlotOutputDialog::receiveErlangData(const QVector<double> &aErl)
{
    this->a = aErl;
}

void PlotOutputDialog::receiveEngsetData(const QVector<double> &aEng, const QVector<int> &nEng)
{
    this->a = aEng;
    this->nEng = nEng;
}

void PlotOutputDialog::receiveErlEngData(const QVector<double> &aErlEng, const QVector<int> &nErlEng, QVector<QString> modelType)
{
    this->a = aErlEng;
    this->nErlEng = nErlEng;
    this->modelTypeVector = modelType;
}

void PlotOutputDialog::receiveExportTablesPath(QString path, bool write, QString fileExt, QString delim)
{
    exportTablesPath = path;
    this->write = write;
    this->fileExt = fileExt;
    this->delim = delim;
}

//-----------------------------------------------------------------------------
// CUSTOM FUNCTIONS:
//-----------------------------------------------------------------------------
void PlotOutputDialog::fillForm()
{
    ui->capacityLabel->setText(QString::number(c));

    // initialize input table and create cells / set modelTypeLabel:
    tb->createTable(ui->inputTableWidget, k, 5);
    if (modelType == "Erlang")
    {
        ui->inputTableWidget->setFixedWidth(259);
        ui->inputTableWidget->setColumnHidden(4, true);
        ui->modelTypeLabel->setText("Erlang");
    }
    else if (modelType == "Engset")
    {
        ui->inputTableWidget->setFixedWidth(319);
        ui->inputTableWidget->setColumnHidden(4, false);
        ui->modelTypeLabel->setText("Engset");
    }
    else if (modelType == "ErlEng")
    {
        ui->inputTableWidget->setFixedWidth(319);
        ui->inputTableWidget->setColumnHidden(4, false);
        ui->modelTypeLabel->setText("Erlang - Engset");
    }

    ui->inputTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->inputTableWidget->horizontalHeader()->setDefaultSectionSize(60);
    ui->inputTableWidget->verticalHeader()->setDefaultSectionSize(20);
    ui->inputTableWidget->verticalHeader()->setVisible(false);
    ui->inputTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    tb->addIndex(ui->inputTableWidget, 1);

    for (int i = 0; i < k; i++)
    {
        ui->inputTableWidget->item(i, 1)->setText(QString::number(a[i]));
        ui->inputTableWidget->item(i, 2)->setText(QString::number(b[i]));
        ui->inputTableWidget->item(i, 3)->setText(QString::number(t[i]));

        if (modelType == "Engset")
            ui->inputTableWidget->item(i, 4)->setText(QString::number(nEng[i]));
        else if (modelType == "ErlEng")
        {
            if (modelTypeVector[i] == "Erlang")
                ui->inputTableWidget->item(i, 4)->setText("n/a");
            if (modelTypeVector[i] == "Engset")
                ui->inputTableWidget->item(i, 4)->setText(QString::number(nErlEng[i]));
        }
    }

    for (int i = 0; i < k; i++)
    {
        ui->selServClassComboBox->addItem(QString::number(i+1));
        ui->plotServClassComboBox->addItem(QString::number(i+1));
    }
}

int PlotOutputDialog::searchValueInVector(const QVector<QVector<double>> &vector, const int &column, const double &value)
{
    int row, index;

    index = -1;

    row = 0;
    while (index == -1 && row < vector.size())
    {
        if(vector[row][column] == value)
            index = row;

        row++;
    }
    return index;
}

void PlotOutputDialog::changeAMaxColumn(QTableWidget *table, int columnIndex, const int &numOfSteps)
{
    int rows;
    double aMin, step;

    rows = table->rowCount();

    for (int i = 0; i < rows ; i++)
    {
        aMin = table->item(i, 1)->text().toDouble();
        step = table->item(i, 2)->text().toDouble();
        table->item(i, columnIndex)->setText(QString::number(aMin + step * numOfSteps));
    }
}

QVector<QVector<double>> PlotOutputDialog::calculate_aInputVector(const QVector<QVector<double>> &ax, const QVector<double> &aErl, int &numOfSteps)
{
    QVector<QVector<double>> aCalc;
    int k, indexOfExistingItem;

    k = a.size();
    aCalc.resize(numOfSteps + 1);
    for (int i = 0; i <= numOfSteps; i++)
    {
        aCalc[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            if ((indexOfExistingItem = searchValueInVector(ax, 0, j + 1)) != -1)
                aCalc[i][j] = ax[indexOfExistingItem][1] + i * ax[indexOfExistingItem][2];
            else
                aCalc[i][j] = aErl[j];
        }
    }
    return aCalc;
}

//-----------------------------------------------------------------------------
// SET NEXT FOCUS:
//-----------------------------------------------------------------------------
void PlotOutputDialog::on_numOfStepsLineEdit_returnPressed()
{
    ui->aMinLineEdit->setFocus();
}

void PlotOutputDialog::on_aMinLineEdit_returnPressed()
{
    ui->stepLlineEdit->setFocus();
}

void PlotOutputDialog::on_stepLlineEdit_returnPressed()
{
    ui->setPushButton->click();
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
//exportPlotDialog FORM MANIPULATION:
//-----------------------------------------------------------------------------

//ExportPlotDialog::ExportPlotDialog(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::ExportPlotDialog)
//{
//    ui->setupUi(this);    // Create and add the child widgets to this widget
//}

//ExportPlotDialog::~ExportPlotDialog()
//{
//    delete ui;
//}

//void ExportPlotDialog::on_buttonBox_accepted()
//{
//    bool write = true;

//    if(!QDir(cfolder).exists())
//    {
//        QMessageBox msgBox;
//        msgBox.setIcon(QMessageBox::Warning);
//        msgBox.setText(cfolder + " folder does not exist.");
//        msgBox.setInformativeText("Do you wnat to create it?");
//        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
//        msgBox.setDefaultButton(QMessageBox::Yes);
//        int ret = msgBox.exec();
//        if(ret == QMessageBox::Yes)
//        {
//            if(QDir().mkdir(cfolder) == false)
//            {

//                write = false;
//                QMessageBox::information(this, "Failed to export data","Invalid path. Data did not export to file.");
//            }
//        }
//        else
//        {
//            write = false;
//            QMessageBox::information(this, "Failed to export data","Data did not export to file.");
//            ui->folderNameLineEdit->setText(QDir::currentPath());
//        }
//    }
//    else if((new QFile(cfolder + cfile + cfext))->exists())
//    {
//        QMessageBox msgBox;
//        msgBox.setIcon(QMessageBox::Warning);
//        msgBox.setText(cfolder + cfile + cfext + " already exist");
//        msgBox.setInformativeText("Do you wnat to overwrite it?");
//        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
//        msgBox.setDefaultButton(QMessageBox::Yes);
//        int ret = msgBox.exec();
//        if(ret != QMessageBox::Yes)
//        {
//            write = false;
//            QMessageBox::information(this, "Export aborted","Data did not export to file.");
//        }
//    }

//    emit returnPath(cfolder + "\\" + cfile + cfext, write, cfext, dl);
//}

void PlotOutputDialog::on_pbComboBox_currentIndexChanged(int index)
{
    if (index == 0)
    {
        ui->plotWidget->yAxis->setLabel("Blocking probability");
        ui->plotWidget->createGraph(pbOut, colorList);
        ui->plotServClassComboBox->setVisible(true);
        ui->servClassLabel->setVisible(true);
        ui->plotShowCheckBox->setVisible(true);
        ui->plotShowCheckBox->setChecked(true);
    }
    else if (index == 1)
    {
        ui->plotWidget->yAxis->setLabel("Mean number of calls");
        ui->plotWidget->createGraph(eArray, colorList);
        ui->plotServClassComboBox->setVisible(true);
        ui->servClassLabel->setVisible(true);
        ui->plotShowCheckBox->setVisible(true);
        ui->plotShowCheckBox->setChecked(true);
    }
    else if (index == 2)
    {
        ui->plotWidget->yAxis->setLabel("Link Utilization");
        ui->plotWidget->createUGraph(linkUt);
        ui->plotServClassComboBox->setVisible(false);
        ui->plotServClassComboBox->setCurrentIndex(0);
        ui->servClassLabel->setVisible(false);
        ui->plotShowCheckBox->setVisible(false);
    }
}
