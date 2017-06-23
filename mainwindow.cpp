#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::setWindowTitle("EMLM - EnMLM");

    kr = new KaufmanRoberts;
    tb = new TableManipulation;
    d = NULL;
    pof = NULL;
    inputParImpFolder = QDir::currentPath();

    // initialize k:
    k = 1;

    // initialize servClassIndex:
    servClassIndex = 0;

    // initialize pbColIndex:
    pbColInd = 4;

    // initialize trres, linkcap:
    trres = false;
    linkcap = false;

    // initialize setEng, setErl, importClicked:
    setErl = false;
    setEng = false;
    importClicked = false;

    // initialize inputTableFilled:
    inputTableFilled = false;

    // initialize radio/check boxes
    ui->selBlockProbRadioButton->setChecked(true);
    ui->setaRadioButton->setChecked(true);
    ui->trunkResCheckBox->setChecked(false);

    // initialize line edit:
    ui->aLineEdit->setText("0");
    ui->bLineEdit->setText("0");

    // initialize input table and create cells:
    inputTableWidth = 199;
    tb->createTable(ui->inputTableWidget, 1, 7);
    ui->inputTableWidget->setColumnHidden(3, true);
    ui->inputTableWidget->setColumnHidden(4, true);
    ui->inputTableWidget->setColumnHidden(5, true);
    ui->inputTableWidget->setColumnHidden(6, true);
    tb->addIndex(ui->inputTableWidget, 1);
    ui->inputTableWidget->setFixedWidth(inputTableWidth);
    ui->inputTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->inputTableWidget->horizontalHeader()->setDefaultSectionSize(60);
    ui->inputTableWidget->verticalHeader()->setDefaultSectionSize(20);
    ui->inputTableWidget->verticalHeader()->setVisible(false);
    ui->inputTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->inputTableWidget->setColumnWidth(0,60);
    ui->inputTableWidget->setColumnWidth(1,60);
    ui->inputTableWidget->setColumnWidth(2,60);
    ui->inputTableWidget->setColumnWidth(3,60);
    ui->inputTableWidget->setColumnWidth(4,60);
    ui->inputTableWidget->setColumnWidth(5,60);
    ui->inputTableWidget->setColumnWidth(6,60);

    // initialize the other tables:
    ui->outputTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->outputTableWidget->horizontalHeader()->setDefaultSectionSize(75);
    ui->outputTableWidget->verticalHeader()->setDefaultSectionSize(20);
    ui->outputTableWidget->verticalHeader()->setVisible(false);
    ui->outputTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //------------------------------
    ui->blockingProbTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->blockingProbTableWidget->horizontalHeader()->setDefaultSectionSize(75);
    ui->blockingProbTableWidget->verticalHeader()->setDefaultSectionSize(20);
    ui->blockingProbTableWidget->verticalHeader()->setVisible(false);
    ui->blockingProbTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //------------------------------
    ui->ykjTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ykjTableWidget->horizontalHeader()->setDefaultSectionSize(75);
    ui->ykjTableWidget->verticalHeader()->setDefaultSectionSize(20);
    ui->ykjTableWidget->verticalHeader()->setVisible(false);
    ui->ykjTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    // hide model type line edit:
    ui->modelTypeLabel->setHidden(true);
    ui->erlangRadioButton->setHidden(true);
    ui->engsetRadioButton->setHidden(true);

    // hide trunk reservation line edit:
    ui->trunkResLabel->setHidden(true);
    ui->trunkResLineEdit->setHidden(true);

    // hide blocking probability line edit:
    ui->blockProbLabel->setHidden(true);
    ui->blockProbLineEdit->setHidden(true);

    // resize QVectors (all QVector items are initialized to 0):
    aErl.resize(1);
    aEng.resize(1);
    aErlEq.resize(1);
    aErlEng.resize(1);
    b.resize(1);
    t.resize(1);
    nEng.resize(1);
    nErlEng.resize(1);
    pbin.resize(1);
    t0.resize(1);
    modelType.resize(1);

    // create zeroRow vector:
    zeroRow.resize(5);

    // fill initial row with zero values:
    tb->fillRow(ui->inputTableWidget, 0, zeroRow);

    // focus on link capacity line edit:
    ui->linkCapacityLineEdit->setFocus();

//  ui->label_10->setText("A<sub>1</sub><sup>2</sup>");

}

MainWindow::~MainWindow()
{
    delete ui;
}

//-----------------------------------------------------------------------------
// PRIVATE SLOTS:
//-----------------------------------------------------------------------------
void MainWindow::on_selBlockProbRadioButton_toggled(bool checked)
{
    if (checked)
    {
        linkcap = false;
        inputTableWidth -= 60;
        ui->inputTableWidget->setColumnHidden(5, true);
        ui->inputTableWidget->setFixedWidth(inputTableWidth);
        ui->linkCapacityLabel->setDisabled(false);
        ui->linkCapacityLineEdit->setDisabled(false);
        ui->blockProbLabel->setHidden(true);
        ui->blockProbLineEdit->setHidden(true);
        ui->blockProbGroupBox->setDisabled(false);
        ui->linkCapacityGroupBox->setDisabled(true);
        ui->outputTableWidget->setDisabled(false);
        ui->ykjTableWidget->setDisabled(false);
        ui->plotExportPushButton->setEnabled(true);
    }
    else
    {
        linkcap = true;
        inputTableWidth += 60;
        ui->inputTableWidget->setColumnHidden(5, false);
        ui->inputTableWidget->setColumnWidth(5,60);
        ui->inputTableWidget->setFixedWidth(inputTableWidth);
        ui->linkCapacityLabel->setDisabled(true);
        ui->linkCapacityLineEdit->setDisabled(true);
        ui->blockProbLabel->setHidden(false);
        ui->blockProbLineEdit->setHidden(false);
        ui->blockProbGroupBox->setDisabled(true);
        ui->linkCapacityGroupBox->setDisabled(false);
        ui->outputTableWidget->setDisabled(true);
        ui->ykjTableWidget->setDisabled(true);
        ui->plotExportPushButton->setDisabled(true);
    }
}

void MainWindow::on_selectModelComboBox_currentIndexChanged(int index)
{
    if (index == 0)
    {
        ui->modelTypeLabel->setHidden(true);
        ui->erlangRadioButton->setHidden(true);
        ui->engsetRadioButton->setHidden(true);
        ui->set_lm_Or_vm_RadioButton->setText("Set λ, μ");
        ui->aLabel->setText("Traffic load, a:");
        ui->l_Or_v_Label->setText("Call rate, λ:");
        ui->setaRadioButton->setChecked(true);
        ui->NLabel->setVisible(false);
        ui->NLineEdit->setVisible(false);

        if (!ui->inputTableWidget->isColumnHidden(4))
        {
            inputTableWidth -= 60;
            ui->inputTableWidget->setFixedWidth(inputTableWidth);
            ui->inputTableWidget->setColumnHidden(4, true);
        }

        if (!ui->inputTableWidget->isColumnHidden(6))
        {
            inputTableWidth -= 60;
            ui->inputTableWidget->setFixedWidth(inputTableWidth);
            ui->inputTableWidget->setColumnHidden(6, true);
        }

        tb->fillColumn(ui->inputTableWidget, 1, aErl);
        ui->selServClassComboBox->setCurrentIndex(0);
        ui->aLineEdit->setText(ui->inputTableWidget->item(0, 1)->text());
        ui->bLineEdit->setText(ui->inputTableWidget->item(0, 2)->text());
        ui->trunkResLineEdit->setText(ui->inputTableWidget->item(0, 3)->text());
        ui->NLineEdit->setText(ui->inputTableWidget->item(0, 4)->text());
        ui->blockProbLineEdit->setText(ui->inputTableWidget->item(0, 5)->text());
    }
    else if (index == 1)
    {
        ui->modelTypeLabel->setHidden(true);
        ui->erlangRadioButton->setHidden(true);
        ui->engsetRadioButton->setHidden(true);
        ui->set_lm_Or_vm_RadioButton->setText("Set v, μ");
        ui->aLabel->setText("Traffilc load per idle source, a:");
        ui->l_Or_v_Label->setText("Call rate per idle source, v:");
        ui->setaRadioButton->setChecked(true);
        ui->NLabel->setVisible(true);
        ui->NLineEdit->setVisible(true);

        if (ui->inputTableWidget->isColumnHidden(4))
        {
            inputTableWidth += 60;
            ui->inputTableWidget->setFixedWidth(inputTableWidth);
            ui->inputTableWidget->setColumnHidden(4, false);
        }

        if (!ui->inputTableWidget->isColumnHidden(6))
        {
            inputTableWidth -= 60;
            ui->inputTableWidget->setFixedWidth(inputTableWidth);
            ui->inputTableWidget->setColumnHidden(6, true);
        }

        ui->inputTableWidget->setColumnWidth(4,60);
        ui->inputTableWidget->setFixedWidth(inputTableWidth);
        tb->fillColumn(ui->inputTableWidget, 1, aEng);
        tb->fillColumn(ui->inputTableWidget, 4, nEng);
        ui->selServClassComboBox->setCurrentIndex(0);
        ui->aLineEdit->setText(ui->inputTableWidget->item(0, 1)->text());
        ui->bLineEdit->setText(ui->inputTableWidget->item(0, 2)->text());
        ui->trunkResLineEdit->setText(ui->inputTableWidget->item(0, 3)->text());
        ui->NLineEdit->setText(ui->inputTableWidget->item(0, 4)->text());
        ui->blockProbLineEdit->setText(ui->inputTableWidget->item(0, 5)->text());
    }
    else if (index == 2)
    {
        ui->modelTypeLabel->setHidden(false);
        ui->erlangRadioButton->setHidden(false);
        ui->engsetRadioButton->setHidden(false);
        ui->NLabel->setVisible(false);
        ui->NLineEdit->setVisible(false);
        ui->set_lm_Or_vm_RadioButton->setText("Set λ, μ");
        ui->aLabel->setText("Traffic load, a:");
        ui->l_Or_v_Label->setText("Call rate, λ:");

        if (ui->inputTableWidget->isColumnHidden(4))
        {
            inputTableWidth += 60;
            ui->inputTableWidget->setFixedWidth(inputTableWidth);
            ui->inputTableWidget->setColumnHidden(4, false);
        }

        if (ui->inputTableWidget->isColumnHidden(6))
        {
            inputTableWidth += 60;
            ui->inputTableWidget->setFixedWidth(inputTableWidth);
            ui->inputTableWidget->setColumnHidden(6, false);
        }

        if (ui->inputTableWidget->item(servClassIndex, 6)->text().isEmpty() || ui->inputTableWidget->item(servClassIndex, 6)->text() == "Erlang")
            ui->erlangRadioButton->setChecked(true);
        else if (ui->inputTableWidget->item(servClassIndex, 6)->text() == "Engset")
            ui->engsetRadioButton->setChecked(true);

        tb->fillColumn(ui->inputTableWidget, 1, aErlEng);
        tb->fillColumn(ui->inputTableWidget, 4, nErlEng);
        tb->fillNColumn(ui->inputTableWidget, 4, nErlEng, modelType);
    }
}

void MainWindow::on_linkCapacityLineEdit_textChanged(const QString &arg1)
{
    int inputVal;
    bool ok;

    // clear all output tables/labels:
    ui->outputTableWidget->setRowCount(0);
    ui->ykjTableWidget->setRowCount(0);
    ui->blockingProbTableWidget->setRowCount(0);
    ui->linkUtLabel->setText("");

    inputVal = arg1.toInt(&ok);
    if(!ok || inputVal < 1)
        ui->linkCapacityLineEdit->setText("");
    else
        c = inputVal;
}

void MainWindow::on_numOfServClassSpinBox_valueChanged(int arg1)
{
    int temp;

    temp = servClassIndex;  // store temporarily service class index
    ui->selServClassComboBox->clear();

    for(int i = 1; i <= arg1; i++)
        ui->selServClassComboBox->addItem(QString::number(i));

    if (arg1 - k >= 0)
    {
        for (int i = 0; i < arg1-k; i++)
        {
            tb->addRows(ui->inputTableWidget,1);    // the new row has index = k
            tb->addIndex(ui->inputTableWidget,0,k+i,k);
            tb->fillRow(ui->inputTableWidget, k+i, zeroRow);
        }
    }
    else
    {
        for (int i = 0; i < k-arg1; i++)
            ui->inputTableWidget->removeRow(k-i-1);
    }

    ui->selServClassComboBox->setCurrentIndex(temp);    // assign to selServClassComboBox its previous value

    k = arg1;

    aErl.resize(arg1);
    aEng.resize(arg1);
    aErlEq.resize(arg1);
    aErlEng.resize(arg1);
    b.resize(arg1);
    t.resize(arg1);
    nEng.resize(arg1);
    nErlEng.resize(arg1);
    pbin.resize(arg1);
    t0.resize(arg1);
    modelType.resize(arg1);
}

void MainWindow::on_trunkResCheckBox_toggled(bool checked)
{
    if (checked)
    {
        trres = true;
        inputTableWidth += 60;
        ui->inputTableWidget->setColumnHidden(3,false);
        ui->inputTableWidget->setColumnWidth(3,60);
        ui->inputTableWidget->setFixedWidth(inputTableWidth);
        ui->trunkResLabel->setHidden(false);
        ui->trunkResLineEdit->setHidden(false);
    }
    else
    {
        trres = false;
        inputTableWidth -= 60;
        ui->inputTableWidget->setColumnHidden(3,true);
        ui->inputTableWidget->setFixedWidth(inputTableWidth);
        ui->trunkResLabel->setHidden(true);
        ui->trunkResLineEdit->setHidden(true);
    }
}

void MainWindow::on_selServClassComboBox_currentIndexChanged(int index)
{
    servClassIndex = index;

    if (index >=0)
    {
        ui->aLineEdit->setText(ui->inputTableWidget->item(index, 1)->text());
        ui->bLineEdit->setText(ui->inputTableWidget->item(index, 2)->text());
        ui->trunkResLineEdit->setText(ui->inputTableWidget->item(index, 3)->text());
        ui->NLineEdit->setText(ui->inputTableWidget->item(index, 4)->text());
        ui->blockProbLineEdit->setText(ui->inputTableWidget->item(index, 5)->text());

        if (ui->selectModelComboBox->currentIndex() == 2)
        {
            if (ui->inputTableWidget->item(servClassIndex, 6)->text() == "Erlang")
            {
                ui->erlangRadioButton->setChecked(true);
                ui->NLabel->setVisible(false);
                ui->NLineEdit->setVisible(false);
            }
            else if (ui->inputTableWidget->item(servClassIndex, 6)->text() == "Engset")
            {
                ui->engsetRadioButton->setChecked(true);
                ui->NLabel->setVisible(true);
                ui->NLineEdit->setVisible(true);
            }
        }
    }
}

void MainWindow::on_erlangRadioButton_clicked(bool checked)
{
    if (checked)
    {
        ui->NLabel->setVisible(false);
        ui->NLineEdit->setVisible(false);
        ui->set_lm_Or_vm_RadioButton->setText("Set λ, μ");
        ui->aLabel->setText("Traffic load, a:");
        ui->l_Or_v_Label->setText("Call rate, λ:");
    }
}

void MainWindow::on_engsetRadioButton_clicked(bool checked)
{
    if (checked)
    {
        ui->NLabel->setVisible(true);
        ui->NLineEdit->setVisible(true);
        ui->NLineEdit->setText(ui->inputTableWidget->item(servClassIndex, 4)->text());
        ui->set_lm_Or_vm_RadioButton->setText("Set v, μ");
        ui->aLabel->setText("Traffilc load per idle source, a:");
        ui->l_Or_v_Label->setText("Call rate per idle source, v:");
    }
}

void MainWindow::on_setaRadioButton_toggled(bool checked)
{
    if(checked)
    {
        ui->aLineEdit->setEnabled(true);
        ui->l_Or_v_LineEdit->setEnabled(false);
        ui->mLineEdit->setEnabled(false);
        ui->aLineEdit->setFocus();

        if (ui->selectModelComboBox->currentIndex() == 0)
        {
            ui->NLabel->setVisible(false);
            ui->NLineEdit->setVisible(false);
        }
        else if (ui->selectModelComboBox->currentIndex() == 1)
        {
            ui->NLabel->setVisible(true);
            ui->NLineEdit->setVisible(true);
        }
    }
    else
    {
        ui->aLineEdit->setEnabled(false);
        ui->l_Or_v_LineEdit->setEnabled(true);
        ui->mLineEdit->setEnabled(true);
        ui->l_Or_v_LineEdit->setFocus();

        if (ui->selectModelComboBox->currentIndex() == 1)
        {
            ui->NLabel->setVisible(true);
            ui->NLineEdit->setVisible(true);
        }
    }
}

void MainWindow::on_aLineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);

    if (ui->setaRadioButton->isChecked())
    {
        if (!ok || inputVal < 0)
            ui->aLineEdit->setText("");
        else
        {
            ai = inputVal;
            ui->l_Or_v_LineEdit->setText("");
            ui->mLineEdit->setText("");
        }
    }
}

void MainWindow::on_l_Or_v_LineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);

    if (!ok || inputVal < 0)
    {
        ui->l_Or_v_LineEdit->setText("");
        ui->aLineEdit->setText("");
    }
    else
    {
        lv = inputVal;

        if(!ui->mLineEdit->text().isEmpty())
        {
            ai = lv/m;
            ui->aLineEdit->setText(QString::number(ai));
        }
    }
}

void MainWindow::on_mLineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);

    if (!ok || inputVal < 0)
    {
        ui->mLineEdit->setText("");
        ui->aLineEdit->setText("");
    }
    else
    {
        m = inputVal;

        if (!ui->l_Or_v_LineEdit->text().isEmpty())
        {
            ai = lv/m;
            ui->aLineEdit->setText(QString::number(ai));
        }
    }
}

void MainWindow::on_NLineEdit_textChanged(const QString &arg1)
{
    int inputVal;
    bool ok;

    inputVal = arg1.toInt(&ok);

    if (!ok || inputVal < 0 )
        ui->NLineEdit->setText("");
    else
        ni = inputVal;

}

void MainWindow::on_bLineEdit_textChanged(const QString &arg1)
{
    int inputVal;
    bool ok;

    inputVal = arg1.toInt(&ok);

    if (!ok || inputVal < 0){
        ui->bLineEdit->setText("");
    }
    else
        bi = inputVal;
}

void MainWindow::on_trunkResLineEdit_textChanged(const QString &arg1)
{
    int inputVal;
    bool ok;

    inputVal = arg1.toInt(&ok);

    if (!ok || inputVal < 0)
        ui->trunkResLineEdit->setText("");
    else
        ti = inputVal;
}

void MainWindow::on_blockProbLineEdit_textChanged(const QString &arg1)
{
    double inputVal;
    bool ok;

    inputVal = arg1.toDouble(&ok);

    if (!ok || inputVal < 0 || inputVal > 1)
        ui->blockProbLineEdit->setText("");
    else
        pbi = inputVal;
}

void MainWindow::createTable(QTableWidget *table, int rows, int columns)
{
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<columns; j++)
        {
            table->setItem(i,j,new QTableWidgetItem);

            if (j == 0)
                table->item(i,j)->setText(QString::number(i+1));
        }
    }
}

void MainWindow::addTableRow(QTableWidget *table, int row, int columns)
{
    for (int i=0; i<columns; i++)
    {
        table->setItem(row,i,new QTableWidgetItem);
        table->item(row,i)->setTextAlignment(Qt::AlignCenter);

        if (i == 0)
            table->item(row,i)->setText(QString::number(row+1));
    }
}

void MainWindow::createTableRow(int row)
{
    for (int i=0; i<3; i++)
    {
        ui->inputTableWidget->setItem(row,i,new QTableWidgetItem);
        ui->inputTableWidget->item(row,i)->setTextAlignment(Qt::AlignCenter);

        if (i == 0)
            ui->inputTableWidget->item(row,i)->setText(QString::number(row+1));
    }
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->setaRadioButton->isChecked() && ui->aLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input a");
    else if (ui->set_lm_Or_vm_RadioButton->isChecked() && (ui->l_Or_v_LineEdit->text().isEmpty() || ui->mLineEdit->text().isEmpty()))
        QMessageBox::warning(this, "Error","Input traffic load data");
    else if (ui->selectModelComboBox->currentIndex() == 1 && ui->NLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input N");
    else if (ui->bLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input b");
    else if (ui->trunkResCheckBox->isChecked() && ui->trunkResLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input t");
    else if (ui->selLinkCapacityRadioButton->isChecked() && ui->blockProbLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input Pb");
    else
    {
        if (ui->selectModelComboBox->currentIndex() == 0)
            aErl[servClassIndex] = ai;
        else if (ui->selectModelComboBox->currentIndex() == 1)
        {
            aEng[servClassIndex] = ai;
            aErlEq[servClassIndex] = ai * ni;
        }
        else if (ui->selectModelComboBox->currentIndex() == 2)
        {
            aErlEng[servClassIndex] = ai;

            if (ui->erlangRadioButton->isChecked())
            {
                aErlEq[servClassIndex] = ai;
            }
            else if (ui->engsetRadioButton->isChecked())
            {
                aErlEq[servClassIndex] = ai * ni;
            }
        }

        b[servClassIndex] = bi;

        if (ui->trunkResCheckBox->isChecked())
            t[servClassIndex] = ti;

        if (ui->selectModelComboBox->currentIndex() == 1)
            nEng[servClassIndex] = ni;
        else if ( ui->selectModelComboBox->currentIndex() == 2 && ui->engsetRadioButton->isChecked())
            nErlEng[servClassIndex] = ni;

        if (ui->selLinkCapacityRadioButton->isChecked())
            pbin[servClassIndex] = pbi;

        if (ui->selectModelComboBox->currentIndex() == 2)
        {
            if (ui->erlangRadioButton->isChecked())
                modelType[servClassIndex] = "Erlang";
            else if (ui->engsetRadioButton->isChecked())
                modelType[servClassIndex] = "Engset";
        }

        if(bi != b[servClassIndex] || ti != t[servClassIndex] || aiErl != aErl[servClassIndex] || niEng != nEng[servClassIndex])
        {
            // clear all output tables/labels:
            ui->outputTableWidget->setRowCount(0);
            ui->ykjTableWidget->setRowCount(0);
            ui->blockingProbTableWidget->setRowCount(0);
            ui->linkUtLabel->setText("");
            ui->linkCapacityOutLabel->setText("");
        }
        else if(pbi != pbin[servClassIndex])
            ui->linkCapacityOutLabel->setText("");

        // fill input table:
        if (ui->selectModelComboBox->currentIndex() == 0)
            ui->inputTableWidget->item(servClassIndex,1)->setText(QString::number(aErl[servClassIndex]));
        else if (ui->selectModelComboBox->currentIndex() == 1)
            ui->inputTableWidget->item(servClassIndex,1)->setText(QString::number(aEng[servClassIndex]));
        else if (ui->selectModelComboBox->currentIndex() == 2)
        {
            ui->inputTableWidget->item(servClassIndex,1)->setText(QString::number(aErlEng[servClassIndex]));
        }

        ui->inputTableWidget->item(servClassIndex,2)->setText(QString::number(b[servClassIndex]));
        ui->inputTableWidget->item(servClassIndex,3)->setText(QString::number(t[servClassIndex]));
        if (ui->selectModelComboBox->currentIndex() == 1)
            ui->inputTableWidget->item(servClassIndex,4)->setText(QString::number(nEng[servClassIndex]));
        else if (ui->selectModelComboBox->currentIndex() == 2)
        {
            if (ui->erlangRadioButton->isChecked())
                ui->inputTableWidget->item(servClassIndex,4)->setText("n/a");
            else if (ui->engsetRadioButton->isChecked())
                ui->inputTableWidget->item(servClassIndex,4)->setText(QString::number(nErlEng[servClassIndex]));
        }

        ui->inputTableWidget->item(servClassIndex,5)->setText(QString::number(pbin[servClassIndex]));
        ui->inputTableWidget->item(servClassIndex,6)->setText(modelType[servClassIndex]);

        // sevice class combo box index increment (+1):
        if(ui->selServClassComboBox->currentIndex() < ui->selServClassComboBox->count() - 1)
            ui->selServClassComboBox-> setCurrentIndex(servClassIndex + 1);

        ui->aLineEdit->setFocus();
        ui->aLineEdit->selectAll();
    }

    if (ui->selectModelComboBox->currentIndex() == 0)
        setErl = true;
    else if (ui->selectModelComboBox->currentIndex() == 1)
        setEng = true;
}

void MainWindow::on_resultsPushButton_clicked()
{
    if(ui->selBlockProbRadioButton->isChecked() && ui->linkCapacityLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input value for link capacity, C.");
    else if (!tb->checkColumn(ui->inputTableWidget, 1))
        QMessageBox::warning(this, "Error","Input a for all service classes.");
    else if (!tb->checkColumn(ui->inputTableWidget, 2))
        QMessageBox::warning(this, "Error","Input b for all service classes.");
    else if (ui->trunkResCheckBox->isChecked() && !tb->checkColumn(ui->inputTableWidget, 3))
        QMessageBox::warning(this, "Error","Input t for all service classes.");
    else if (ui->selectModelComboBox->currentIndex() == 1 && !tb->checkColumn(ui->inputTableWidget, 4))
        QMessageBox::warning(this, "Error","Input N for all service classes.");
    else if (ui->selLinkCapacityRadioButton->isChecked() && !tb->checkPbCol(ui->inputTableWidget, 5))
        QMessageBox::warning(this, "Error","Input Pb for all service classes.");
    else
    {
        if (ui->selBlockProbRadioButton->isChecked() && ui->selectModelComboBox->currentIndex() == 0)
        {
            if (!ui->trunkResCheckBox->isChecked())
            {
                q = kr->calculate_qj(c, b, t0, aErl);
                pb = kr->calculate_pbk(q, b, t0);
                y = kr->calculate_ykj(q, aErl, b, t0);
            }
            else
            {
                q = kr->calculate_qj(c, b, t, aErl);
                pb = kr->calculate_pbk(q, b, t);
                y = kr->calculate_ykj(q, aErl, b, t);
            }

            p = kr->calculate_pj(q);
            //y = kr->calculate_ykj(q, aErl, b, t);
            sumy = kr->calculate_sum_ykbk(b, y);
            e = kr->calculate_E(p, y);
            lu = kr->calculateLinkUt(p);

            // output table:
            ui->outputTableWidget->setRowCount(0);  // remove all rows from output table
            tb->createTable(ui->outputTableWidget,c+1,3);
            tb->addIndex(ui->outputTableWidget, 0);

            for (int i = 0; i <= c; i++)
            {
                ui->outputTableWidget->item(i,1)->setText(QString::number(q[i], 'g', 7));
                ui->outputTableWidget->item(i,2)->setText(QString::number(p[i], 'g', 7));
            }

            // yk table:
            tb->createTable(ui->ykjTableWidget, c+1, k+2);  //setText("A<sub>1</sub><sup>2</sup>");
            tb->addIndex(ui->ykjTableWidget, 0);

            for (int i=1; i<k+1; i++)
            {
                ui->ykjTableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem("y"+QString::number(i)+"(j)")); // fill horizontal header cells
            }
            ui->ykjTableWidget->setHorizontalHeaderItem(k+1, new QTableWidgetItem("Σ(yk*bk)")); // fill the last cell of the horizontal header
            for (int j = 0; j <= c; j++)
            {
                for(int i = 0; i < k; i++)
                    ui->ykjTableWidget->item(j, 1+i)->setText(QString::number(y[j][i], 'g', 7));

                ui->ykjTableWidget->item(j, k+1)->setText(QString::number(sumy[j], 'g', 7));
            }

            // pb table:
            tb->createTable(ui->blockingProbTableWidget, k, 3);
            tb->addIndex(ui->blockingProbTableWidget, 1);

            for (int i = 0; i < k; i++)
            {
                ui->blockingProbTableWidget->item(i,1)->setText(QString::number(pb[i], 'g', 7));
                ui->blockingProbTableWidget->item(i,2)->setText(QString::number(e[i], 'g', 7));
            }

            ui->linkUtLabel->setText(QString::number(lu, 'g', 3));
        }
        else if (ui->selLinkCapacityRadioButton->isChecked() && ui->selectModelComboBox ->currentIndex() == 0)
        {
            if(!ui->trunkResCheckBox->isChecked())
                cout = kr->calculate_c(b, t0, aErl, pbin);
            else
                cout = kr->calculate_c(b, t, aErl, pbin);

            ui->linkCapacityOutLabel->setText(QString::number(cout));
        }
        else if (ui->selBlockProbRadioButton->isChecked() && ui->selectModelComboBox->currentIndex() == 1)
        {
            if (!ui->trunkResCheckBox->isChecked())
            {
                q = kr->calculate_qj(c, b, t0, aErlEq);
                y = kr->calculate_ykj(q, aErlEq, b, t0);
                sumy = kr->calculate_sum_ykbk(b, y);
                qEng = kr->calculate_qj_Engset(aEng, b, t0, nEng, y);
                p = kr->calculate_pj(qEng);
                pb = kr->calculate_pbk(qEng, b, t0);
                e = kr->calculate_E(p, y);
                lu = kr->calculateLinkUt(p);
            }
            else
            {
                q = kr->calculate_qj(c, b, t, aErlEq);
                y = kr->calculate_ykj(q, aErlEq, b, t);
                sumy = kr->calculate_sum_ykbk(b, y);
                qEng = kr->calculate_qj_Engset(aEng, b, t, nEng, y);
                p = kr->calculate_pj(qEng);
                pb = kr->calculate_pbk(qEng, b, t);
                e = kr->calculate_E(p, y);
                lu = kr->calculateLinkUt(p);
            }

            // output table:
            ui->outputTableWidget->setRowCount(0);  // remove all rows from output table
            tb->createTable(ui->outputTableWidget, c+1, 3);
            tb->addIndex(ui->outputTableWidget, 0);

            for (int i = 0; i <= c; i++)
            {
                ui->outputTableWidget->item(i,1)->setText(QString::number(qEng[i], 'g', 7));
                ui->outputTableWidget->item(i,2)->setText(QString::number(p[i], 'g', 7));
            }
            // yk table:
            tb->createTable(ui->ykjTableWidget, c+1, k+2);  //setText("A<sub>1</sub><sup>2</sup>");
            tb->addIndex(ui->ykjTableWidget, 0);

            for (int i=1; i<k+1; i++)
            {
                ui->ykjTableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem("y"+QString::number(i)+"(j)")); // fill horizontal header cells
            }
            ui->ykjTableWidget->setHorizontalHeaderItem(k+1, new QTableWidgetItem("Σ(yk*bk)")); // fill the last cell of the horizontal header

            for (int j = 0; j <= c; j++)
            {
                for (int i = 0; i < k; i++)
                    ui->ykjTableWidget->item(j, 1+i)->setText(QString::number(y[j][i], 'g', 7));

                ui->ykjTableWidget->item(j, k+1)->setText(QString::number(sumy[j], 'g', 7));
            }

            // pb table:
            tb->createTable(ui->blockingProbTableWidget, k, 3);
            tb->addIndex(ui->blockingProbTableWidget, 1);
            for (int i = 0; i < k; i++)
            {
                ui->blockingProbTableWidget->item(i,1)->setText(QString::number(pb[i], 'g', 7));
                ui->blockingProbTableWidget->item(i,2)->setText(QString::number(e[i], 'g', 7));
            }

            ui->linkUtLabel->setText(QString::number(lu, 'g', 3));

        }
        else if (ui->selLinkCapacityRadioButton->isChecked() && ui->selectModelComboBox ->currentIndex() == 1)
        {
            if (!ui->trunkResCheckBox->isChecked())
                cout = kr->calculate_C_Engset(aEng, aErlEq, b, t0, nEng, pbin);
            else
                cout = kr->calculate_C_Engset(aEng, aErlEq, b, t, nEng, pbin);

            ui->linkCapacityOutLabel->setText(QString::number(cout));
        }
        else if (ui->selBlockProbRadioButton->isChecked() && ui->selectModelComboBox->currentIndex() == 2)
        {
            if (!ui->trunkResCheckBox->isChecked())
            {
                q = kr->calculate_qj(c, b, t0, aErlEq);
                y = kr->calculate_ykj(q, aErlEq, b, t0);
                sumy = kr->calculate_sum_ykbk(b, y);
                qErlEng = kr->calculate_qj_ErlEng(aErlEng, b, t0, nErlEng, y, modelType);
                p = kr->calculate_pj(qErlEng);
                pb = kr->calculate_pbk(qErlEng, b, t0);
                e = kr->calculate_E(p, y);
                lu = kr->calculateLinkUt(p);
            }
            else
            {
                q = kr->calculate_qj(c, b, t, aErlEq);
                y = kr->calculate_ykj(q, aErlEq, b, t);
                sumy = kr->calculate_sum_ykbk(b, y);
                qErlEng = kr->calculate_qj_ErlEng(aErlEng, b, t, nErlEng, y, modelType);
                p = kr->calculate_pj(qErlEng);
                pb = kr->calculate_pbk(qErlEng, b, t);
                e = kr->calculate_E(p, y);
                lu = kr->calculateLinkUt(p);
            }

            // output table:
            ui->outputTableWidget->setRowCount(0);  // remove all rows from output table
            tb->createTable(ui->outputTableWidget, c+1, 3);
            tb->addIndex(ui->outputTableWidget, 0);

            for (int i = 0; i <= c; i++)
            {
                ui->outputTableWidget->item(i,1)->setText(QString::number(qErlEng[i], 'g', 7));
                ui->outputTableWidget->item(i,2)->setText(QString::number(p[i], 'g', 7));
            }
            // yk table:
            tb->createTable(ui->ykjTableWidget, c+1, k+2);  //setText("A<sub>1</sub><sup>2</sup>");
            tb->addIndex(ui->ykjTableWidget, 0);

            for (int i=1; i<k+1; i++)
            {
                ui->ykjTableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem("y"+QString::number(i)+"(j)")); // fill horizontal header cells
            }
            ui->ykjTableWidget->setHorizontalHeaderItem(k+1, new QTableWidgetItem("Σ(yk*bk)")); // fill the last cell of the horizontal header

            for (int j = 0; j <= c; j++)
            {
                for(int i = 0; i < k; i++)
                    ui->ykjTableWidget->item(j, 1+i)->setText(QString::number(y[j][i], 'g', 7));

                ui->ykjTableWidget->item(j, k+1)->setText(QString::number(sumy[j], 'g', 7));
            }

            // pb table:
            tb->createTable(ui->blockingProbTableWidget, k, 3);
            tb->addIndex(ui->blockingProbTableWidget, 1);

            for (int i = 0; i < k; i++)
            {
                ui->blockingProbTableWidget->item(i,1)->setText(QString::number(pb[i], 'g', 7));
                ui->blockingProbTableWidget->item(i,2)->setText(QString::number(e[i], 'g', 7));
            }

            ui->linkUtLabel->setText(QString::number(lu, 'g', 3));

        }
        else if (ui->selLinkCapacityRadioButton->isChecked() && ui->selectModelComboBox ->currentIndex() == 2)
        {
            if(!ui->trunkResCheckBox->isChecked())
                cout = kr->calculate_C_ErlEng(aErlEng, aErlEq, b, t0, nErlEng, pbin, modelType);
            else
                cout = kr->calculate_C_ErlEng(aErlEng, aErlEq, b, t, nErlEng, pbin, modelType);

            ui->linkCapacityOutLabel->setText(QString::number(cout));
        }
    }
}

void MainWindow::on_plotExportPushButton_clicked()
{
    if(ui->selBlockProbRadioButton->isChecked() && ui->linkCapacityLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Error","Input value for link capacity, C.");
    else if (!tb->checkColumn(ui->inputTableWidget, 1))
        QMessageBox::warning(this, "Error","Input a for all service classes.");
    else if (!tb->checkColumn(ui->inputTableWidget, 2))
        QMessageBox::warning(this, "Error","Input b for all service classes.");
    else if (ui->trunkResCheckBox->isChecked() && !tb->checkColumn(ui->inputTableWidget, 3))
        QMessageBox::warning(this, "Error","Input t for all service classes.");
    else if (ui->selectModelComboBox->currentIndex() == 1 && !tb->checkColumn(ui->inputTableWidget, 4))
        QMessageBox::warning(this, "Error","Input N for all service classes.");
    else if (ui->selLinkCapacityRadioButton->isChecked() && !tb->checkPbCol(ui->inputTableWidget, 5))
        QMessageBox::warning(this, "Error","Input Pb for all service classes.");
    else
    {
        pof  = new PlotOutputDialog;

        connect(this, SIGNAL(passGeneralData(int, int, QString, QVector<int>)),
                pof, SLOT(receiveGeneralData(int, int, QString, QVector<int>)));

        connect(this, SIGNAL(passTrunkReservation(QVector<int>)),
                pof, SLOT(receiveTrunkReservation(QVector<int>)));

        connect(this, SIGNAL(passErlangData(QVector<double>)),
                pof, SLOT(receiveErlangData(QVector<double>)));

        connect(this, SIGNAL(passEngsetData(QVector<double>, QVector<int>)),
                pof, SLOT(receiveEngsetData(QVector<double>, QVector<int>)));

        connect(this, SIGNAL(passErlEngData(QVector<double>,QVector<int>,QVector<QString>)),
                pof, SLOT(receiveErlEngData(QVector<double>,QVector<int>,QVector<QString>)));

        if (ui->selectModelComboBox->currentIndex() == 0)
        {
            emit passGeneralData(c, k, "Erlang", b);
            emit passErlangData(aErl);
        }
        else if (ui->selectModelComboBox->currentIndex() == 1)
        {
            emit passGeneralData(c, k, "Engset", b);
            emit passEngsetData(aEng, nEng);
        }
        else if (ui->selectModelComboBox->currentIndex() == 2)
        {
            emit passGeneralData(c, k, "ErlEng", b);
            emit passErlEngData(aErlEng, nErlEng, modelType);
        }

        if (!ui->trunkResCheckBox->isChecked())
            emit passTrunkReservation(t0);
        else
            emit passTrunkReservation(t);

        pof->fillForm();
        pof->exec();
    }
}

//-----------------------------------------------------------------------------
// ON RETURN PRESSED:
//-----------------------------------------------------------------------------

void MainWindow::on_linkCapacityLineEdit_returnPressed()
{
    ui->numOfServClassSpinBox->setFocus();
    ui->numOfServClassSpinBox->selectAll();
}

void MainWindow::on_numOfServClassSpinBox_editingFinished()
{
    if (ui->setaRadioButton->isChecked())
    {
        ui->aLineEdit->setFocus();
        ui->aLineEdit->selectAll();
    }
    else
    {
        ui->l_Or_v_LineEdit->setFocus();
        ui->l_Or_v_LineEdit->selectAll();
    }
}

void MainWindow::on_aLineEdit_returnPressed()
{
    if (ui->selectModelComboBox->currentIndex() == 0)
    {
        ui->bLineEdit->setFocus();
        ui->bLineEdit->selectAll();
    }
    else if (ui->selectModelComboBox->currentIndex() == 1)
    {
        ui->NLineEdit->setFocus();
        ui->NLineEdit->selectAll();
    }
    else if (ui->selectModelComboBox->currentIndex() == 2)
    {
        if (ui->erlangRadioButton->isChecked())
        {
            ui->bLineEdit->setFocus();
            ui->bLineEdit->selectAll();
        }
        else if (ui->engsetRadioButton->isChecked())
        {
            ui->NLineEdit->setFocus();
            ui->NLineEdit->selectAll();
        }
    }
}

void MainWindow::on_l_Or_v_LineEdit_returnPressed()
{
    ui->mLineEdit->setFocus();
    ui->mLineEdit->selectAll();
}

void MainWindow::on_mLineEdit_returnPressed()
{
    if (ui->selectModelComboBox->currentIndex() == 1 || (ui->selectModelComboBox->currentIndex() == 2 && ui->engsetRadioButton->isChecked()))
    {
        ui->NLineEdit->setFocus();
        ui->NLineEdit->selectAll();
    }
    else
    {
        ui->bLineEdit->setFocus();
        ui->bLineEdit->selectAll();
    }
}

void MainWindow::on_NLineEdit_returnPressed()
{
    ui->bLineEdit->setFocus();
    ui->bLineEdit->selectAll();
}

void MainWindow::on_bLineEdit_returnPressed()
{
    if(ui->trunkResCheckBox->isChecked())
    {
        ui->trunkResLineEdit->setFocus();
        ui->trunkResLineEdit->selectAll();
    }
    else
        if(ui->selLinkCapacityRadioButton->isChecked())
        {
            ui->blockProbLineEdit->setFocus();
            ui->blockProbLineEdit->selectAll();
        }
        else
            ui->pushButton->click();
}

void MainWindow::on_trunkResLineEdit_returnPressed()
{
    if(ui->selLinkCapacityRadioButton->isChecked())
    {
        ui->blockProbLineEdit->setFocus();
        ui->blockProbLineEdit->selectAll();
    }
    else
        ui->pushButton->click();
}

void MainWindow::on_blockProbLineEdit_returnPressed()
{
    ui->pushButton->click();
}

//-----------------------------------------------------------------------------
// PUBLIC SLOTS:
//-----------------------------------------------------------------------------

void MainWindow::receivePath(QString path, bool write, QString currFileExt, QString delim)
{
    inputParExpPath = path;
    wr = write;
    cfext = currFileExt;
    dl = delim;
}

//-----------------------------------------------------------------------------
// IMPORT / EXPORT FILE:
//-----------------------------------------------------------------------------

void MainWindow::on_exportInputPushButton_clicked()
{
    if (d == NULL)
        d = new ExportDialog;

    QObject::connect(d, SIGNAL(returnPath(QString, bool, QString, QString)), this, SLOT(receivePath(QString, bool, QString , QString)));
    d->exec();
    if (d->result() == QDialog::Accepted && wr == true)
    {

        QFile file(inputParExpPath);
        if (file.open(QFile::WriteOnly | QFile::Truncate | QIODevice::Text))     // Truncate = delete existing content
        {
            QTextStream stream(&file);
            if (cfext == ".txt")
            {
                stream << "***************************" << endl;
                stream << "*                         *" << endl;
                stream << "*    INPUT PARAMETRERS    *" << endl;
                stream << "*                         *" << endl;
                stream << "***************************" << endl << endl;
            }
            //stream << "k" << dl;
            stream << "a" << dl;
            stream << "b";

            if (trres)
                stream << dl << "t";

            if (ui->selectModelComboBox->currentIndex() == 1 || (ui->selectModelComboBox->currentIndex() == 2 && ui->engsetRadioButton->isChecked()))
                stream << dl << "N";

            if (linkcap)
                stream << dl << "Pb";

            if (ui->selectModelComboBox->currentIndex() == 2)
                stream << dl << "model";

            if (cfext == ".txt")
            {
                stream << endl;
                stream << "-----------------------------------------------";
            }

            for(int i = 0; i < k; i++)
            {
                if (ui->selectModelComboBox->currentIndex() == 0)
                    stream << endl << aErl[i];
                else if (ui->selectModelComboBox->currentIndex() == 1)
                    stream << endl << aEng[i];
                else if (ui->selectModelComboBox->currentIndex() == 2)
                    stream << endl << aErlEng[i];

                stream << dl << b[i];

                if(trres)
                    stream << dl << t[i];

                if (ui->selectModelComboBox->currentIndex() == 1)
                    stream << dl << nEng[i];
                else if (ui->selectModelComboBox->currentIndex() == 2 && ui->engsetRadioButton->isChecked())
                    stream << dl << nErlEng[i];

                if(linkcap)
                    stream << dl << pbin[i];

                if (ui->selectModelComboBox->currentIndex() == 2)
                    stream << dl << modelType[i];
            }
        }
    }
}

void MainWindow::on_importInputPushButton_clicked()
{
    QVector<QString> header;
    QVector<QVector<QString>> fileData;
    QMessageBox message;
    QString fileName;
    TextFileManipulation *tfm;

    tfm = new TextFileManipulation;     // creates new object

    fileName = QFileDialog::getOpenFileName(
                this,
                "Open File",
                inputParImpFolder,
                "*.txt *.csv"
                );

    if (!fileName.isEmpty())
    {
        QFile file(fileName);    // constructs a new QFile object according to the selected file
        header = inputTableHeader();
        fileData = tfm->readFile(file, header, message);

        if (fileData.size() >= 2)
        {
            ui->numOfServClassSpinBox->setValue(fileData.size());
            tb->fillTable(ui->inputTableWidget, header, fileData);
            fillVectors(fileData, header);
        }

        message.exec();

        if (importClicked == false)
            importClicked = true;
    }
}

//-----------------------------------------------------------------------------
// CUSTOM FUNCTIONS:
//-----------------------------------------------------------------------------

QVector<QString> MainWindow::inputTableHeader()
{
    int currentIndex;

    QVector<QString> header(2);
    header[0] = "a";
    header[1] = "b";
    currentIndex = 2;
    if (ui->trunkResCheckBox->isChecked())
    {
        header.resize(currentIndex + 1);
        header[currentIndex] = "t";
        currentIndex ++;
    }

    if (ui->selectModelComboBox->currentIndex() == 1 || ui->selectModelComboBox->currentIndex() == 2)
    {
        header.resize(currentIndex + 1);
        header[currentIndex] = "N";
        currentIndex ++;
    }

    if (ui->selLinkCapacityRadioButton->isChecked())
    {
        header.resize(currentIndex + 1);
        header[currentIndex] = "Pb";
        currentIndex ++;
    }

    if (ui->selectModelComboBox->currentIndex() == 2)
    {
        header.resize(currentIndex + 1);
        header[currentIndex] = "model";
    }
    return header;
}

void MainWindow::fillVectors(QVector<QVector<QString>> data, QVector<QString> header)
{
    int rows, columns;
    bool tFound, NFound, PbFound, modelFound;

    rows = data.size();
    columns = header.size();
    aErl.resize(rows);
    aEng.resize(rows);
    aErlEng.resize(rows);
    b.resize(rows);
    t0.resize(rows);
    t.resize(rows);
    pbin.resize(rows);
    tFound = false;
    NFound = false;
    PbFound = false;
    modelFound = false;

    for (int i = 0; i < columns; i++)
    {
        if (header[i] == "a")
            for (int j = 0; j < rows; j++)
            {
                aErl[j] = data[j][i].toDouble();
                aEng[j] = data[j][i].toDouble();
                aErlEng[j] = data[j][i].toDouble();
            }
        else if (header[i] == "b")
            for (int j = 0; j < rows; j++)
                b[j] = data[j][i].toInt();
        else if (header[i] == "t")
        {
            tFound = true;
            for (int j = 0; j < rows; j++)
                t[j] = data[j][i].toInt();
        }
        else if (header[i] == "N")
        {
            NFound = true;
            for (int j = 0; j < rows; j++)
            {
                nEng[j] = data[j][i].toInt();
                nErlEng[j] = data[j][i].toInt();
                aErl[j] = 0;
            }
        }
        else if (header[i] == "Pb")
        {
            PbFound = true;
            for (int j = 0; j < rows; j++)
                pbin[j] = data[j][i].toDouble();
        }
        else if (header[i] == "model")
        {
            modelFound = true;
            for (int j = 0; j < rows; j++)
                modelType[j] = data[j][i];
        }
    }

    if (tFound == false)
        for (int i = 0; i < rows; i++)
            t[i] = 0 ;

    if (NFound == false)
    {
        for (int i = 0; i < rows; i++)
        {
            aEng[i] = 0;
            aErlEng[i] = 0;
        }
    }
    else
    {
        if (modelFound == false)
        {
            for (int i = 0; i < rows; i++)
            {
                aErlEq[i] = aEng[i] * nEng[i];
                nErlEng[i] = 0;
                aErl[i] = 0;
                aErlEng[i] = 0;
            }
        }
        else
        {
            for (int i = 0; i < rows; i++)
            {
                if (modelType[i] == "Erlang")
                    aErlEq[i] = aErlEng[i];
                else if (modelType[i] == "Engset")
                    aErlEq[i] = aErlEng[i] * nErlEng[i];

                nEng[i] = 0;
                aErl[i] = 0;
                aEng[i] = 0;
            }
        }
    }

    if (PbFound == false)
        for (int i = 0; i < rows; i++)
            pbin[i] = 0 ;
}

