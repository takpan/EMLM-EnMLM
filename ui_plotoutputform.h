/********************************************************************************
** Form generated from reading UI file 'plotoutputform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTOUTPUTFORM_H
#define UI_PLOTOUTPUTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "plotgraphs.h"

QT_BEGIN_NAMESPACE

class Ui_PlotOutputForm
{
public:
    QGroupBox *groupBox_2;
    QTableWidget *inputTableWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLabel *capacityLabel;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *selServClassComboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *aMinLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *stepLlineEdit;
    QPushButton *pushButton;
    QTableWidget *aTableWidget;
    QPushButton *setPushButton;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *numOfStepsLineEdit;
    QGroupBox *groupBox_4;
    QTableWidget *aStepsTableWidget;
    QTableWidget *pbOutTableWidget;
    QGroupBox *groupBox_5;
    PlotGraphs *plotWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *plotServClassComboBox;
    QSpacerItem *horizontalSpacer;
    QCheckBox *plotShowCheckBox;
    QPushButton *plotPushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *PlotOutputForm)
    {
        if (PlotOutputForm->objectName().isEmpty())
            PlotOutputForm->setObjectName(QStringLiteral("PlotOutputForm"));
        PlotOutputForm->resize(1153, 816);
        groupBox_2 = new QGroupBox(PlotOutputForm);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(510, 10, 281, 311));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        groupBox_2->setFont(font);
        inputTableWidget = new QTableWidget(groupBox_2);
        if (inputTableWidget->columnCount() < 4)
            inputTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        inputTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        inputTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        inputTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        inputTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        inputTableWidget->setObjectName(QStringLiteral("inputTableWidget"));
        inputTableWidget->setGeometry(QRect(10, 70, 259, 221));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inputTableWidget->sizePolicy().hasHeightForWidth());
        inputTableWidget->setSizePolicy(sizePolicy);
        inputTableWidget->setMinimumSize(QSize(259, 0));
        inputTableWidget->setMaximumSize(QSize(259, 16777215));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        inputTableWidget->setFont(font1);
        inputTableWidget->horizontalHeader()->setStretchLastSection(false);
        inputTableWidget->verticalHeader()->setStretchLastSection(false);
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 118, 21));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 0));
        label_5->setMaximumSize(QSize(70, 25));
        label_5->setFont(font1);

        horizontalLayout->addWidget(label_5);

        capacityLabel = new QLabel(layoutWidget);
        capacityLabel->setObjectName(QStringLiteral("capacityLabel"));
        capacityLabel->setMinimumSize(QSize(40, 0));
        capacityLabel->setMaximumSize(QSize(1000, 16777215));
        capacityLabel->setFont(font);
        capacityLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(capacityLabel);

        groupBox_3 = new QGroupBox(PlotOutputForm);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 491, 311));
        groupBox_3->setFont(font);
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 70, 471, 231));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setWeight(50);
        groupBox->setFont(font2);
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 176, 121));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        horizontalLayout_4->addWidget(label);

        selServClassComboBox = new QComboBox(layoutWidget1);
        selServClassComboBox->setObjectName(QStringLiteral("selServClassComboBox"));
        selServClassComboBox->setMinimumSize(QSize(50, 0));
        selServClassComboBox->setMaximumSize(QSize(50, 16777215));
        selServClassComboBox->setFont(font1);

        horizontalLayout_4->addWidget(selServClassComboBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_5->addWidget(label_4);

        aMinLineEdit = new QLineEdit(layoutWidget1);
        aMinLineEdit->setObjectName(QStringLiteral("aMinLineEdit"));
        aMinLineEdit->setMinimumSize(QSize(50, 0));
        aMinLineEdit->setMaximumSize(QSize(50, 16777215));
        aMinLineEdit->setFont(font1);

        horizontalLayout_5->addWidget(aMinLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout_6->addWidget(label_6);

        stepLlineEdit = new QLineEdit(layoutWidget1);
        stepLlineEdit->setObjectName(QStringLiteral("stepLlineEdit"));
        stepLlineEdit->setMinimumSize(QSize(50, 0));
        stepLlineEdit->setMaximumSize(QSize(50, 16777215));
        stepLlineEdit->setFont(font1);

        horizontalLayout_6->addWidget(stepLlineEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 200, 71, 23));
        pushButton->setMinimumSize(QSize(0, 0));
        pushButton->setMaximumSize(QSize(100, 16777215));
        pushButton->setFont(font1);
        aTableWidget = new QTableWidget(groupBox);
        if (aTableWidget->columnCount() < 4)
            aTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        aTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        aTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        aTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        aTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        aTableWidget->setObjectName(QStringLiteral("aTableWidget"));
        aTableWidget->setGeometry(QRect(200, 20, 259, 201));
        aTableWidget->setFont(font1);
        setPushButton = new QPushButton(groupBox);
        setPushButton->setObjectName(QStringLiteral("setPushButton"));
        setPushButton->setGeometry(QRect(110, 200, 71, 23));
        setPushButton->setMinimumSize(QSize(0, 0));
        setPushButton->setMaximumSize(QSize(100, 16777215));
        setPushButton->setFont(font1);
        layoutWidget2 = new QWidget(groupBox_3);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 30, 171, 22));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);

        horizontalLayout_7->addWidget(label_7);

        numOfStepsLineEdit = new QLineEdit(layoutWidget2);
        numOfStepsLineEdit->setObjectName(QStringLiteral("numOfStepsLineEdit"));
        numOfStepsLineEdit->setMinimumSize(QSize(50, 0));
        numOfStepsLineEdit->setMaximumSize(QSize(50, 16777215));
        numOfStepsLineEdit->setFont(font1);

        horizontalLayout_7->addWidget(numOfStepsLineEdit);

        groupBox_4 = new QGroupBox(PlotOutputForm);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(800, 10, 341, 761));
        groupBox_4->setFont(font);
        aStepsTableWidget = new QTableWidget(groupBox_4);
        if (aStepsTableWidget->columnCount() < 2)
            aStepsTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        aStepsTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        aStepsTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        aStepsTableWidget->setObjectName(QStringLiteral("aStepsTableWidget"));
        aStepsTableWidget->setGeometry(QRect(10, 30, 319, 350));
        aStepsTableWidget->setFont(font1);
        pbOutTableWidget = new QTableWidget(groupBox_4);
        if (pbOutTableWidget->columnCount() < 1)
            pbOutTableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        pbOutTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        pbOutTableWidget->setObjectName(QStringLiteral("pbOutTableWidget"));
        pbOutTableWidget->setGeometry(QRect(10, 400, 321, 350));
        pbOutTableWidget->setFont(font1);
        groupBox_5 = new QGroupBox(PlotOutputForm);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 330, 771, 441));
        groupBox_5->setFont(font);
        plotWidget = new PlotGraphs(groupBox_5);
        plotWidget->setObjectName(QStringLiteral("plotWidget"));
        plotWidget->setGeometry(QRect(20, 20, 741, 381));
        plotWidget->setFont(font1);
        groupBox_5->raise();
        groupBox_5->raise();
        widget = new QWidget(groupBox_5);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(560, 410, 201, 22));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        plotServClassComboBox = new QComboBox(widget);
        plotServClassComboBox->setObjectName(QStringLiteral("plotServClassComboBox"));
        plotServClassComboBox->setMinimumSize(QSize(50, 0));
        plotServClassComboBox->setMaximumSize(QSize(50, 16777215));
        plotServClassComboBox->setFont(font1);

        horizontalLayout_2->addWidget(plotServClassComboBox);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        plotShowCheckBox = new QCheckBox(widget);
        plotShowCheckBox->setObjectName(QStringLiteral("plotShowCheckBox"));
        plotShowCheckBox->setFont(font1);

        horizontalLayout_2->addWidget(plotShowCheckBox);

        plotPushButton = new QPushButton(PlotOutputForm);
        plotPushButton->setObjectName(QStringLiteral("plotPushButton"));
        plotPushButton->setGeometry(QRect(1060, 780, 75, 23));
        plotPushButton->setFont(font);
        pushButton_2 = new QPushButton(PlotOutputForm);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(970, 780, 75, 23));
        pushButton_2->setFont(font);

        retranslateUi(PlotOutputForm);

        QMetaObject::connectSlotsByName(PlotOutputForm);
    } // setupUi

    void retranslateUi(QWidget *PlotOutputForm)
    {
        PlotOutputForm->setWindowTitle(QApplication::translate("PlotOutputForm", "Form", 0));
        groupBox_2->setTitle(QApplication::translate("PlotOutputForm", "Input parameters", 0));
        QTableWidgetItem *___qtablewidgetitem = inputTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PlotOutputForm", "Serv. class", 0));
        QTableWidgetItem *___qtablewidgetitem1 = inputTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PlotOutputForm", "b", 0));
        QTableWidgetItem *___qtablewidgetitem2 = inputTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("PlotOutputForm", "t", 0));
        QTableWidgetItem *___qtablewidgetitem3 = inputTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("PlotOutputForm", "a", 0));
        label_5->setText(QApplication::translate("PlotOutputForm", "Capacity, C:", 0));
        capacityLabel->setText(QString());
        groupBox_3->setTitle(QApplication::translate("PlotOutputForm", "Plot parameters", 0));
        groupBox->setTitle(QApplication::translate("PlotOutputForm", "Set x axis", 0));
        label->setText(QApplication::translate("PlotOutputForm", "Select service class:", 0));
        label_4->setText(QApplication::translate("PlotOutputForm", "a, min value:", 0));
        label_6->setText(QApplication::translate("PlotOutputForm", "Step:", 0));
        pushButton->setText(QApplication::translate("PlotOutputForm", "Remove", 0));
        QTableWidgetItem *___qtablewidgetitem4 = aTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("PlotOutputForm", "Serv. class", 0));
        QTableWidgetItem *___qtablewidgetitem5 = aTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("PlotOutputForm", "a (min)", 0));
        QTableWidgetItem *___qtablewidgetitem6 = aTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("PlotOutputForm", "step", 0));
        QTableWidgetItem *___qtablewidgetitem7 = aTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("PlotOutputForm", "a (max)", 0));
        setPushButton->setText(QApplication::translate("PlotOutputForm", "Set", 0));
        label_7->setText(QApplication::translate("PlotOutputForm", "Number of steps:", 0));
        groupBox_4->setTitle(QApplication::translate("PlotOutputForm", "Output tables", 0));
        QTableWidgetItem *___qtablewidgetitem8 = aStepsTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("PlotOutputForm", "Step", 0));
        QTableWidgetItem *___qtablewidgetitem9 = aStepsTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("PlotOutputForm", "a1", 0));
        QTableWidgetItem *___qtablewidgetitem10 = pbOutTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("PlotOutputForm", "Step", 0));
        groupBox_5->setTitle(QApplication::translate("PlotOutputForm", "Plot", 0));
        label_2->setText(QApplication::translate("PlotOutputForm", "Service class:", 0));
        plotShowCheckBox->setText(QApplication::translate("PlotOutputForm", "show", 0));
        plotPushButton->setText(QApplication::translate("PlotOutputForm", "Plot", 0));
        pushButton_2->setText(QApplication::translate("PlotOutputForm", "Export", 0));
    } // retranslateUi

};

namespace Ui {
    class PlotOutputForm: public Ui_PlotOutputForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTOUTPUTFORM_H
