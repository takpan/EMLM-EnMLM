/********************************************************************************
** Form generated from reading UI file 'plotoutputdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTOUTPUTDIALOG_H
#define UI_PLOTOUTPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "plotgraphs.h"

QT_BEGIN_NAMESPACE

class Ui_PlotOutputDialog
{
public:
    QGridLayout *gridLayout_8;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox;
    QWidget *layoutWidget_2;
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
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *numOfStepsLineEdit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLabel *capacityLabel;
    QLabel *label_3;
    QLabel *modelTypeLabel;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QTableWidget *inputTableWidget;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_2;
    PlotGraphs *plotWidget;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QComboBox *pbComboBox;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *servClassLabel;
    QComboBox *plotServClassComboBox;
    QSpacerItem *horizontalSpacer;
    QCheckBox *plotShowCheckBox;
    QLabel *label_8;
    QComboBox *scatterComboBox;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *rescalePushButton;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *exportPushButton;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_3;
    QTableWidget *aStepsTableWidget;
    QTableWidget *pbOutTableWidget;
    QTableWidget *e_uTableWidget;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *exportTablesPushButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *backPushButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *plotPushButton;

    void setupUi(QWidget *PlotOutputDialog)
    {
        if (PlotOutputDialog->objectName().isEmpty())
            PlotOutputDialog->setObjectName(QStringLiteral("PlotOutputDialog"));
        PlotOutputDialog->resize(1157, 768);
        PlotOutputDialog->setMinimumSize(QSize(640, 480));
        QIcon icon;
        icon.addFile(QStringLiteral("logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        PlotOutputDialog->setWindowIcon(icon);
        gridLayout_8 = new QGridLayout(PlotOutputDialog);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(PlotOutputDialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(640, 480));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1155, 766));
        gridLayout_10 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(491, 285));
        groupBox_3->setMaximumSize(QSize(16777215, 291));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        groupBox_3->setFont(font);
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 70, 471, 211));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setWeight(50);
        groupBox->setFont(font1);
        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 20, 176, 121));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        label->setFont(font2);

        horizontalLayout_4->addWidget(label);

        selServClassComboBox = new QComboBox(layoutWidget_2);
        selServClassComboBox->setObjectName(QStringLiteral("selServClassComboBox"));
        selServClassComboBox->setMinimumSize(QSize(50, 0));
        selServClassComboBox->setMaximumSize(QSize(50, 16777215));
        selServClassComboBox->setFont(font2);

        horizontalLayout_4->addWidget(selServClassComboBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font2);

        horizontalLayout_5->addWidget(label_4);

        aMinLineEdit = new QLineEdit(layoutWidget_2);
        aMinLineEdit->setObjectName(QStringLiteral("aMinLineEdit"));
        aMinLineEdit->setMinimumSize(QSize(50, 0));
        aMinLineEdit->setMaximumSize(QSize(50, 16777215));
        aMinLineEdit->setFont(font2);

        horizontalLayout_5->addWidget(aMinLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font2);

        horizontalLayout_6->addWidget(label_6);

        stepLlineEdit = new QLineEdit(layoutWidget_2);
        stepLlineEdit->setObjectName(QStringLiteral("stepLlineEdit"));
        stepLlineEdit->setMinimumSize(QSize(50, 0));
        stepLlineEdit->setMaximumSize(QSize(50, 16777215));
        stepLlineEdit->setFont(font2);

        horizontalLayout_6->addWidget(stepLlineEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 180, 71, 23));
        pushButton->setMinimumSize(QSize(0, 0));
        pushButton->setMaximumSize(QSize(100, 16777215));
        pushButton->setFont(font2);
        aTableWidget = new QTableWidget(groupBox);
        if (aTableWidget->columnCount() < 4)
            aTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        aTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        aTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        aTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        aTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        aTableWidget->setObjectName(QStringLiteral("aTableWidget"));
        aTableWidget->setGeometry(QRect(200, 20, 259, 181));
        aTableWidget->setFont(font2);
        setPushButton = new QPushButton(groupBox);
        setPushButton->setObjectName(QStringLiteral("setPushButton"));
        setPushButton->setGeometry(QRect(110, 180, 71, 23));
        setPushButton->setMinimumSize(QSize(0, 0));
        setPushButton->setMaximumSize(QSize(100, 16777215));
        setPushButton->setFont(font2);
        layoutWidget_3 = new QWidget(groupBox_3);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(20, 30, 171, 22));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font2);

        horizontalLayout_7->addWidget(label_7);

        numOfStepsLineEdit = new QLineEdit(layoutWidget_3);
        numOfStepsLineEdit->setObjectName(QStringLiteral("numOfStepsLineEdit"));
        numOfStepsLineEdit->setMinimumSize(QSize(50, 0));
        numOfStepsLineEdit->setMaximumSize(QSize(50, 16777215));
        numOfStepsLineEdit->setFont(font2);

        horizontalLayout_7->addWidget(numOfStepsLineEdit);


        gridLayout_4->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(341, 291));
        groupBox_2->setMaximumSize(QSize(16777215, 291));
        groupBox_2->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 20));
        label_5->setMaximumSize(QSize(70, 25));
        label_5->setFont(font2);

        horizontalLayout->addWidget(label_5);

        capacityLabel = new QLabel(groupBox_2);
        capacityLabel->setObjectName(QStringLiteral("capacityLabel"));
        capacityLabel->setMinimumSize(QSize(40, 0));
        capacityLabel->setMaximumSize(QSize(1000, 16777215));
        capacityLabel->setFont(font);
        capacityLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(capacityLabel);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 20));
        label_3->setMaximumSize(QSize(40, 16777215));
        label_3->setFont(font2);

        horizontalLayout->addWidget(label_3);

        modelTypeLabel = new QLabel(groupBox_2);
        modelTypeLabel->setObjectName(QStringLiteral("modelTypeLabel"));
        modelTypeLabel->setFont(font);

        horizontalLayout->addWidget(modelTypeLabel);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 1, 3, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        inputTableWidget = new QTableWidget(groupBox_2);
        if (inputTableWidget->columnCount() < 5)
            inputTableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        inputTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        inputTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        inputTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        inputTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        inputTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem8);
        inputTableWidget->setObjectName(QStringLiteral("inputTableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inputTableWidget->sizePolicy().hasHeightForWidth());
        inputTableWidget->setSizePolicy(sizePolicy);
        inputTableWidget->setMinimumSize(QSize(319, 0));
        inputTableWidget->setMaximumSize(QSize(319, 16777215));
        inputTableWidget->setFont(font2);
        inputTableWidget->horizontalHeader()->setStretchLastSection(false);
        inputTableWidget->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(inputTableWidget, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);

        groupBox_5 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy1);
        groupBox_5->setMinimumSize(QSize(843, 401));
        groupBox_5->setFont(font);
        verticalLayout_2 = new QVBoxLayout(groupBox_5);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        plotWidget = new PlotGraphs(groupBox_5);
        plotWidget->setObjectName(QStringLiteral("plotWidget"));
        plotWidget->setMinimumSize(QSize(0, 0));
        plotWidget->setFont(font2);

        verticalLayout_2->addWidget(plotWidget);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font2);

        horizontalLayout_10->addWidget(label_9);

        pbComboBox = new QComboBox(groupBox_5);
        pbComboBox->setObjectName(QStringLiteral("pbComboBox"));
        pbComboBox->setFont(font2);

        horizontalLayout_10->addWidget(pbComboBox);


        horizontalLayout_8->addLayout(horizontalLayout_10);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        servClassLabel = new QLabel(groupBox_5);
        servClassLabel->setObjectName(QStringLiteral("servClassLabel"));
        servClassLabel->setMinimumSize(QSize(65, 20));
        servClassLabel->setMaximumSize(QSize(65, 20));
        servClassLabel->setFont(font2);

        horizontalLayout_2->addWidget(servClassLabel);

        plotServClassComboBox = new QComboBox(groupBox_5);
        plotServClassComboBox->setObjectName(QStringLiteral("plotServClassComboBox"));
        plotServClassComboBox->setMinimumSize(QSize(50, 20));
        plotServClassComboBox->setMaximumSize(QSize(50, 20));
        plotServClassComboBox->setFont(font2);

        horizontalLayout_2->addWidget(plotServClassComboBox);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        plotShowCheckBox = new QCheckBox(groupBox_5);
        plotShowCheckBox->setObjectName(QStringLiteral("plotShowCheckBox"));
        plotShowCheckBox->setMinimumSize(QSize(48, 17));
        plotShowCheckBox->setMaximumSize(QSize(48, 17));
        plotShowCheckBox->setFont(font2);

        horizontalLayout_2->addWidget(plotShowCheckBox);

        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font2);

        horizontalLayout_2->addWidget(label_8);

        scatterComboBox = new QComboBox(groupBox_5);
        scatterComboBox->setObjectName(QStringLiteral("scatterComboBox"));
        scatterComboBox->setMinimumSize(QSize(50, 20));
        scatterComboBox->setMaximumSize(QSize(50, 20));
        scatterComboBox->setFont(font2);

        horizontalLayout_2->addWidget(scatterComboBox);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        rescalePushButton = new QPushButton(groupBox_5);
        rescalePushButton->setObjectName(QStringLiteral("rescalePushButton"));
        rescalePushButton->setMinimumSize(QSize(50, 23));
        rescalePushButton->setMaximumSize(QSize(50, 23));
        rescalePushButton->setFont(font2);

        horizontalLayout_2->addWidget(rescalePushButton);

        horizontalSpacer_7 = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        exportPushButton = new QPushButton(groupBox_5);
        exportPushButton->setObjectName(QStringLiteral("exportPushButton"));
        exportPushButton->setMinimumSize(QSize(75, 23));
        exportPushButton->setMaximumSize(QSize(75, 23));
        exportPushButton->setFont(font2);

        horizontalLayout_2->addWidget(exportPushButton);


        horizontalLayout_8->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(horizontalLayout_8);


        gridLayout_5->addWidget(groupBox_5, 1, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(100, 701));
        groupBox_4->setMaximumSize(QSize(550, 16777215));
        groupBox_4->setFont(font);
        gridLayout_9 = new QGridLayout(groupBox_4);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        aStepsTableWidget = new QTableWidget(groupBox_4);
        if (aStepsTableWidget->columnCount() < 2)
            aStepsTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        aStepsTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        aStepsTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        aStepsTableWidget->setObjectName(QStringLiteral("aStepsTableWidget"));
        aStepsTableWidget->setFont(font2);

        gridLayout_3->addWidget(aStepsTableWidget, 0, 0, 1, 1);

        pbOutTableWidget = new QTableWidget(groupBox_4);
        if (pbOutTableWidget->columnCount() < 1)
            pbOutTableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        pbOutTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        pbOutTableWidget->setObjectName(QStringLiteral("pbOutTableWidget"));
        pbOutTableWidget->setFont(font2);

        gridLayout_3->addWidget(pbOutTableWidget, 1, 0, 1, 1);

        e_uTableWidget = new QTableWidget(groupBox_4);
        if (e_uTableWidget->columnCount() < 1)
            e_uTableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        e_uTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        e_uTableWidget->setObjectName(QStringLiteral("e_uTableWidget"));

        gridLayout_3->addWidget(e_uTableWidget, 2, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_3, 0, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);

        exportTablesPushButton = new QPushButton(groupBox_4);
        exportTablesPushButton->setObjectName(QStringLiteral("exportTablesPushButton"));
        exportTablesPushButton->setMinimumSize(QSize(75, 23));
        exportTablesPushButton->setMaximumSize(QSize(75, 23));
        exportTablesPushButton->setFont(font2);

        horizontalLayout_9->addWidget(exportTablesPushButton);


        gridLayout_9->addLayout(horizontalLayout_9, 1, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_4, 0, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        backPushButton = new QPushButton(scrollAreaWidgetContents);
        backPushButton->setObjectName(QStringLiteral("backPushButton"));
        backPushButton->setMinimumSize(QSize(75, 23));
        backPushButton->setMaximumSize(QSize(75, 23));

        horizontalLayout_3->addWidget(backPushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        plotPushButton = new QPushButton(scrollAreaWidgetContents);
        plotPushButton->setObjectName(QStringLiteral("plotPushButton"));
        plotPushButton->setMinimumSize(QSize(75, 23));
        plotPushButton->setMaximumSize(QSize(75, 23));
        plotPushButton->setFont(font2);

        horizontalLayout_3->addWidget(plotPushButton);


        gridLayout_7->addLayout(horizontalLayout_3, 1, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_7, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_8->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(PlotOutputDialog);

        QMetaObject::connectSlotsByName(PlotOutputDialog);
    } // setupUi

    void retranslateUi(QWidget *PlotOutputDialog)
    {
        PlotOutputDialog->setWindowTitle(QApplication::translate("PlotOutputDialog", "EMLM - EnMLM Plot", 0));
        groupBox_3->setTitle(QApplication::translate("PlotOutputDialog", "Plot parameters", 0));
        groupBox->setTitle(QApplication::translate("PlotOutputDialog", "x axis - step", 0));
        label->setText(QApplication::translate("PlotOutputDialog", "Select service class:", 0));
        label_4->setText(QApplication::translate("PlotOutputDialog", "a, min value:", 0));
        label_6->setText(QApplication::translate("PlotOutputDialog", "Step:", 0));
        pushButton->setText(QApplication::translate("PlotOutputDialog", "Remove", 0));
        QTableWidgetItem *___qtablewidgetitem = aTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PlotOutputDialog", "Serv. class", 0));
        QTableWidgetItem *___qtablewidgetitem1 = aTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PlotOutputDialog", "a (min)", 0));
        QTableWidgetItem *___qtablewidgetitem2 = aTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("PlotOutputDialog", "step", 0));
        QTableWidgetItem *___qtablewidgetitem3 = aTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("PlotOutputDialog", "a (max)", 0));
        setPushButton->setText(QApplication::translate("PlotOutputDialog", "Set", 0));
        label_7->setText(QApplication::translate("PlotOutputDialog", "Number of steps:", 0));
        groupBox_2->setTitle(QApplication::translate("PlotOutputDialog", "Input parameters", 0));
        label_5->setText(QApplication::translate("PlotOutputDialog", "Capacity, C:", 0));
        capacityLabel->setText(QString());
        label_3->setText(QApplication::translate("PlotOutputDialog", "Model:", 0));
        modelTypeLabel->setText(QString());
        QTableWidgetItem *___qtablewidgetitem4 = inputTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("PlotOutputDialog", "Serv. class", 0));
        QTableWidgetItem *___qtablewidgetitem5 = inputTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("PlotOutputDialog", "a", 0));
        QTableWidgetItem *___qtablewidgetitem6 = inputTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("PlotOutputDialog", "b", 0));
        QTableWidgetItem *___qtablewidgetitem7 = inputTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("PlotOutputDialog", "t", 0));
        QTableWidgetItem *___qtablewidgetitem8 = inputTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem8->setText(QApplication::translate("PlotOutputDialog", "N", 0));
        groupBox_5->setTitle(QApplication::translate("PlotOutputDialog", "Plot", 0));
        label_9->setText(QApplication::translate("PlotOutputDialog", "Y - Axis:", 0));
        pbComboBox->clear();
        pbComboBox->insertItems(0, QStringList()
         << QApplication::translate("PlotOutputDialog", "Blocking probability (Pb)", 0)
         << QApplication::translate("PlotOutputDialog", "Mean number of calls (En)", 0)
         << QApplication::translate("PlotOutputDialog", "Link utilization (U)", 0)
        );
        servClassLabel->setText(QApplication::translate("PlotOutputDialog", "Service class:", 0));
        plotShowCheckBox->setText(QApplication::translate("PlotOutputDialog", "show", 0));
        label_8->setText(QApplication::translate("PlotOutputDialog", "Scatter shape:", 0));
        scatterComboBox->clear();
        scatterComboBox->insertItems(0, QStringList()
         << QApplication::translate("PlotOutputDialog", "\342\227\217", 0)
         << QApplication::translate("PlotOutputDialog", "o", 0)
         << QApplication::translate("PlotOutputDialog", "x", 0)
         << QApplication::translate("PlotOutputDialog", "+", 0)
         << QApplication::translate("PlotOutputDialog", "\342\226\241", 0)
         << QApplication::translate("PlotOutputDialog", "*", 0)
         << QApplication::translate("PlotOutputDialog", "\316\224", 0)
         << QApplication::translate("PlotOutputDialog", "\342\210\207", 0)
        );
        rescalePushButton->setText(QApplication::translate("PlotOutputDialog", "Rescale", 0));
        exportPushButton->setText(QApplication::translate("PlotOutputDialog", "Export", 0));
        groupBox_4->setTitle(QApplication::translate("PlotOutputDialog", "Output tables", 0));
        QTableWidgetItem *___qtablewidgetitem9 = aStepsTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("PlotOutputDialog", "Step", 0));
        QTableWidgetItem *___qtablewidgetitem10 = aStepsTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("PlotOutputDialog", "a1", 0));
        QTableWidgetItem *___qtablewidgetitem11 = pbOutTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("PlotOutputDialog", "Step", 0));
        QTableWidgetItem *___qtablewidgetitem12 = e_uTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QApplication::translate("PlotOutputDialog", "Step", 0));
        exportTablesPushButton->setText(QApplication::translate("PlotOutputDialog", "Export", 0));
        backPushButton->setText(QApplication::translate("PlotOutputDialog", "< Back", 0));
        plotPushButton->setText(QApplication::translate("PlotOutputDialog", "Plot", 0));
    } // retranslateUi

};

namespace Ui {
    class PlotOutputDialog: public Ui_PlotOutputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTOUTPUTDIALOG_H
