/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGroupBox *inputParGroupBox;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QComboBox *selServClassComboBox;
    QHBoxLayout *horizontalLayout_19;
    QLabel *modelTypeLabel;
    QRadioButton *erlangRadioButton;
    QRadioButton *engsetRadioButton;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *setaRadioButton;
    QRadioButton *set_lm_Or_vm_RadioButton;
    QHBoxLayout *horizontalLayout_7;
    QLabel *aLabel;
    QLineEdit *aLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *l_Or_v_Label;
    QLineEdit *l_Or_v_LineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *mLabel;
    QLineEdit *mLineEdit;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_15;
    QLabel *NLabel;
    QLineEdit *NLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *bLineEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *trunkResLabel;
    QLineEdit *trunkResLineEdit;
    QHBoxLayout *horizontalLayout_14;
    QLabel *blockProbLabel;
    QLineEdit *blockProbLineEdit;
    QTableWidget *inputTableWidget;
    QPushButton *pushButton;
    QPushButton *exportInputPushButton;
    QPushButton *importInputPushButton;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_6;
    QLabel *linkCapacityLabel;
    QLineEdit *linkCapacityLineEdit;
    QSpacerItem *inputParHorizontalSpacer_1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QSpinBox *numOfServClassSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *trunkResCheckBox;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_18;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QRadioButton *selBlockProbRadioButton;
    QRadioButton *selLinkCapacityRadioButton;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label;
    QComboBox *selectModelComboBox;
    QGroupBox *groupBox_3;
    QGroupBox *blockProbGroupBox;
    QTableWidget *blockingProbTableWidget;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLabel *linkUtLabel;
    QGroupBox *linkCapacityGroupBox;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_11;
    QLabel *linkCapacityOutLabel;
    QFrame *frame;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QTableWidget *ykjTableWidget;
    QTableWidget *outputTableWidget;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *resultsPushButton;
    QPushButton *plotExportPushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1033, 795);
        MainWindow->setMinimumSize(QSize(640, 480));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral("logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1033, 742));
        gridLayout_5 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        inputParGroupBox = new QGroupBox(scrollAreaWidgetContents);
        inputParGroupBox->setObjectName(QStringLiteral("inputParGroupBox"));
        inputParGroupBox->setMinimumSize(QSize(711, 461));
        inputParGroupBox->setMaximumSize(QSize(711, 1000));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        inputParGroupBox->setFont(font);
        groupBox_2 = new QGroupBox(inputParGroupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 100, 691, 351));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        groupBox_2->setFont(font1);
        layoutWidget_2 = new QWidget(groupBox_2);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 20, 201, 291));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);

        horizontalLayout_9->addWidget(label_8);

        selServClassComboBox = new QComboBox(layoutWidget_2);
        selServClassComboBox->setObjectName(QStringLiteral("selServClassComboBox"));
        selServClassComboBox->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_9->addWidget(selServClassComboBox);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        modelTypeLabel = new QLabel(layoutWidget_2);
        modelTypeLabel->setObjectName(QStringLiteral("modelTypeLabel"));

        horizontalLayout_19->addWidget(modelTypeLabel);

        erlangRadioButton = new QRadioButton(layoutWidget_2);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(erlangRadioButton);
        erlangRadioButton->setObjectName(QStringLiteral("erlangRadioButton"));

        horizontalLayout_19->addWidget(erlangRadioButton);

        engsetRadioButton = new QRadioButton(layoutWidget_2);
        buttonGroup->addButton(engsetRadioButton);
        engsetRadioButton->setObjectName(QStringLiteral("engsetRadioButton"));

        horizontalLayout_19->addWidget(engsetRadioButton);


        verticalLayout->addLayout(horizontalLayout_19);

        line = new QFrame(layoutWidget_2);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        setaRadioButton = new QRadioButton(layoutWidget_2);
        buttonGroup_2 = new QButtonGroup(MainWindow);
        buttonGroup_2->setObjectName(QStringLiteral("buttonGroup_2"));
        buttonGroup_2->addButton(setaRadioButton);
        setaRadioButton->setObjectName(QStringLiteral("setaRadioButton"));
        setaRadioButton->setFont(font1);

        horizontalLayout_3->addWidget(setaRadioButton);

        set_lm_Or_vm_RadioButton = new QRadioButton(layoutWidget_2);
        buttonGroup_2->addButton(set_lm_Or_vm_RadioButton);
        set_lm_Or_vm_RadioButton->setObjectName(QStringLiteral("set_lm_Or_vm_RadioButton"));
        set_lm_Or_vm_RadioButton->setFont(font1);

        horizontalLayout_3->addWidget(set_lm_Or_vm_RadioButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        aLabel = new QLabel(layoutWidget_2);
        aLabel->setObjectName(QStringLiteral("aLabel"));
        aLabel->setMaximumSize(QSize(16777215, 16777215));
        aLabel->setFont(font1);

        horizontalLayout_7->addWidget(aLabel);

        aLineEdit = new QLineEdit(layoutWidget_2);
        aLineEdit->setObjectName(QStringLiteral("aLineEdit"));
        aLineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_7->addWidget(aLineEdit);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        l_Or_v_Label = new QLabel(layoutWidget_2);
        l_Or_v_Label->setObjectName(QStringLiteral("l_Or_v_Label"));
        l_Or_v_Label->setMaximumSize(QSize(16777215, 16777215));
        l_Or_v_Label->setFont(font1);

        horizontalLayout_4->addWidget(l_Or_v_Label);

        l_Or_v_LineEdit = new QLineEdit(layoutWidget_2);
        l_Or_v_LineEdit->setObjectName(QStringLiteral("l_Or_v_LineEdit"));
        l_Or_v_LineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(l_Or_v_LineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        mLabel = new QLabel(layoutWidget_2);
        mLabel->setObjectName(QStringLiteral("mLabel"));
        mLabel->setMaximumSize(QSize(16777215, 16777215));
        mLabel->setFont(font1);

        horizontalLayout_5->addWidget(mLabel);

        mLineEdit = new QLineEdit(layoutWidget_2);
        mLineEdit->setObjectName(QStringLiteral("mLineEdit"));
        mLineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_5->addWidget(mLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        line_2 = new QFrame(layoutWidget_2);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        NLabel = new QLabel(layoutWidget_2);
        NLabel->setObjectName(QStringLiteral("NLabel"));

        horizontalLayout_15->addWidget(NLabel);

        NLineEdit = new QLineEdit(layoutWidget_2);
        NLineEdit->setObjectName(QStringLiteral("NLineEdit"));
        NLineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_15->addWidget(NLineEdit);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        bLineEdit = new QLineEdit(layoutWidget_2);
        bLineEdit->setObjectName(QStringLiteral("bLineEdit"));
        bLineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(bLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        trunkResLabel = new QLabel(layoutWidget_2);
        trunkResLabel->setObjectName(QStringLiteral("trunkResLabel"));
        trunkResLabel->setFont(font1);

        horizontalLayout_10->addWidget(trunkResLabel);

        trunkResLineEdit = new QLineEdit(layoutWidget_2);
        trunkResLineEdit->setObjectName(QStringLiteral("trunkResLineEdit"));
        trunkResLineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_10->addWidget(trunkResLineEdit);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        blockProbLabel = new QLabel(layoutWidget_2);
        blockProbLabel->setObjectName(QStringLiteral("blockProbLabel"));
        blockProbLabel->setFont(font1);

        horizontalLayout_14->addWidget(blockProbLabel);

        blockProbLineEdit = new QLineEdit(layoutWidget_2);
        blockProbLineEdit->setObjectName(QStringLiteral("blockProbLineEdit"));
        blockProbLineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_14->addWidget(blockProbLineEdit);


        verticalLayout->addLayout(horizontalLayout_14);

        inputTableWidget = new QTableWidget(groupBox_2);
        if (inputTableWidget->columnCount() < 7)
            inputTableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        inputTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        inputTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        inputTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        inputTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        inputTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        inputTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        inputTableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        inputTableWidget->setObjectName(QStringLiteral("inputTableWidget"));
        inputTableWidget->setGeometry(QRect(240, 20, 439, 291));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inputTableWidget->sizePolicy().hasHeightForWidth());
        inputTableWidget->setSizePolicy(sizePolicy);
        inputTableWidget->setFont(font1);
        inputTableWidget->horizontalHeader()->setStretchLastSection(false);
        inputTableWidget->verticalHeader()->setStretchLastSection(false);
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(135, 320, 75, 23));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMaximumSize(QSize(100, 16777215));
        pushButton->setFont(font1);
        pushButton->setLayoutDirection(Qt::LeftToRight);
        exportInputPushButton = new QPushButton(groupBox_2);
        exportInputPushButton->setObjectName(QStringLiteral("exportInputPushButton"));
        exportInputPushButton->setGeometry(QRect(330, 320, 75, 23));
        exportInputPushButton->setMaximumSize(QSize(100, 16777215));
        importInputPushButton = new QPushButton(groupBox_2);
        importInputPushButton->setObjectName(QStringLiteral("importInputPushButton"));
        importInputPushButton->setGeometry(QRect(240, 320, 75, 23));
        importInputPushButton->setMaximumSize(QSize(100, 16777215));
        layoutWidget_3 = new QWidget(inputParGroupBox);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(22, 60, 571, 24));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetFixedSize);
        linkCapacityLabel = new QLabel(layoutWidget_3);
        linkCapacityLabel->setObjectName(QStringLiteral("linkCapacityLabel"));
        linkCapacityLabel->setMinimumSize(QSize(85, 0));
        linkCapacityLabel->setMaximumSize(QSize(85, 16777215));
        linkCapacityLabel->setFont(font1);

        horizontalLayout_6->addWidget(linkCapacityLabel);

        linkCapacityLineEdit = new QLineEdit(layoutWidget_3);
        linkCapacityLineEdit->setObjectName(QStringLiteral("linkCapacityLineEdit"));
        linkCapacityLineEdit->setMaximumSize(QSize(50, 16777215));
        linkCapacityLineEdit->setFont(font1);

        horizontalLayout_6->addWidget(linkCapacityLineEdit);

        inputParHorizontalSpacer_1 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(inputParHorizontalSpacer_1);


        horizontalLayout_12->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_6 = new QLabel(layoutWidget_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(135, 0));
        label_6->setMaximumSize(QSize(135, 16777215));
        label_6->setFont(font1);

        horizontalLayout->addWidget(label_6);

        numOfServClassSpinBox = new QSpinBox(layoutWidget_3);
        numOfServClassSpinBox->setObjectName(QStringLiteral("numOfServClassSpinBox"));
        numOfServClassSpinBox->setMaximumSize(QSize(50, 16777215));
        numOfServClassSpinBox->setFont(font1);
        numOfServClassSpinBox->setMinimum(1);
        numOfServClassSpinBox->setMaximum(10000);
        numOfServClassSpinBox->setValue(1);

        horizontalLayout->addWidget(numOfServClassSpinBox);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        horizontalLayout_12->addLayout(horizontalLayout);

        trunkResCheckBox = new QCheckBox(layoutWidget_3);
        trunkResCheckBox->setObjectName(QStringLiteral("trunkResCheckBox"));
        trunkResCheckBox->setMaximumSize(QSize(16777215, 16777215));
        trunkResCheckBox->setFont(font1);

        horizontalLayout_12->addWidget(trunkResCheckBox);

        layoutWidget_4 = new QWidget(inputParGroupBox);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(23, 22, 561, 24));
        horizontalLayout_18 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_10 = new QLabel(layoutWidget_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(52, 0));
        label_10->setMaximumSize(QSize(52, 16777215));
        label_10->setFont(font1);

        horizontalLayout_11->addWidget(label_10);

        selBlockProbRadioButton = new QRadioButton(layoutWidget_4);
        selBlockProbRadioButton->setObjectName(QStringLiteral("selBlockProbRadioButton"));
        selBlockProbRadioButton->setMaximumSize(QSize(220, 16777215));
        selBlockProbRadioButton->setFont(font1);

        horizontalLayout_11->addWidget(selBlockProbRadioButton);

        selLinkCapacityRadioButton = new QRadioButton(layoutWidget_4);
        selLinkCapacityRadioButton->setObjectName(QStringLiteral("selLinkCapacityRadioButton"));
        selLinkCapacityRadioButton->setFont(font1);

        horizontalLayout_11->addWidget(selLinkCapacityRadioButton);

        horizontalSpacer_3 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_3);


        horizontalLayout_18->addLayout(horizontalLayout_11);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label = new QLabel(layoutWidget_4);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(35, 0));
        label->setMaximumSize(QSize(35, 16777215));
        label->setFont(font1);

        horizontalLayout_17->addWidget(label);

        selectModelComboBox = new QComboBox(layoutWidget_4);
        selectModelComboBox->setObjectName(QStringLiteral("selectModelComboBox"));
        selectModelComboBox->setMinimumSize(QSize(160, 0));
        selectModelComboBox->setMaximumSize(QSize(160, 16777215));
        selectModelComboBox->setFont(font1);

        horizontalLayout_17->addWidget(selectModelComboBox);


        horizontalLayout_18->addLayout(horizontalLayout_17);


        gridLayout_2->addWidget(inputParGroupBox, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(291, 461));
        groupBox_3->setMaximumSize(QSize(16777215, 800));
        groupBox_3->setFont(font);
        blockProbGroupBox = new QGroupBox(groupBox_3);
        blockProbGroupBox->setObjectName(QStringLiteral("blockProbGroupBox"));
        blockProbGroupBox->setGeometry(QRect(10, 30, 271, 361));
        blockProbGroupBox->setFont(font1);
        blockingProbTableWidget = new QTableWidget(blockProbGroupBox);
        if (blockingProbTableWidget->columnCount() < 3)
            blockingProbTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        blockingProbTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        blockingProbTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        blockingProbTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        blockingProbTableWidget->setObjectName(QStringLiteral("blockingProbTableWidget"));
        blockingProbTableWidget->setGeometry(QRect(10, 20, 244, 271));
        blockingProbTableWidget->setFont(font1);
        blockingProbTableWidget->setSortingEnabled(false);
        layoutWidget_5 = new QWidget(blockProbGroupBox);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 310, 111, 22));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        QFont font2;
        font2.setBold(false);
        font2.setUnderline(false);
        font2.setWeight(50);
        label_9->setFont(font2);

        horizontalLayout_8->addWidget(label_9);

        linkUtLabel = new QLabel(layoutWidget_5);
        linkUtLabel->setObjectName(QStringLiteral("linkUtLabel"));
        linkUtLabel->setFont(font);
        linkUtLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(linkUtLabel);

        linkCapacityGroupBox = new QGroupBox(groupBox_3);
        linkCapacityGroupBox->setObjectName(QStringLiteral("linkCapacityGroupBox"));
        linkCapacityGroupBox->setGeometry(QRect(10, 400, 271, 51));
        linkCapacityGroupBox->setFont(font1);
        layoutWidget_6 = new QWidget(linkCapacityGroupBox);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(10, 20, 141, 22));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget_6);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMaximumSize(QSize(67, 16777215));
        label_11->setFont(font1);

        horizontalLayout_13->addWidget(label_11);

        linkCapacityOutLabel = new QLabel(layoutWidget_6);
        linkCapacityOutLabel->setObjectName(QStringLiteral("linkCapacityOutLabel"));
        linkCapacityOutLabel->setFont(font);

        horizontalLayout_13->addWidget(linkCapacityOutLabel);

        frame = new QFrame(groupBox_3);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(240, 240, 199, 21));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout_2->addWidget(groupBox_3, 0, 1, 1, 1);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(1011, 221));
        groupBox->setMaximumSize(QSize(16777215, 500));
        groupBox->setFont(font);
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        ykjTableWidget = new QTableWidget(groupBox);
        if (ykjTableWidget->columnCount() < 3)
            ykjTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        ykjTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        ykjTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        ykjTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        ykjTableWidget->setObjectName(QStringLiteral("ykjTableWidget"));
        ykjTableWidget->setMaximumSize(QSize(16777215, 16777215));
        ykjTableWidget->setFont(font1);
        ykjTableWidget->setSortingEnabled(false);

        gridLayout_4->addWidget(ykjTableWidget, 0, 1, 1, 1);

        outputTableWidget = new QTableWidget(groupBox);
        if (outputTableWidget->columnCount() < 3)
            outputTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        outputTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        outputTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        outputTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        outputTableWidget->setObjectName(QStringLiteral("outputTableWidget"));
        outputTableWidget->setMinimumSize(QSize(244, 0));
        outputTableWidget->setMaximumSize(QSize(244, 16777215));
        outputTableWidget->setFont(font1);
        outputTableWidget->setSortingEnabled(false);

        gridLayout_4->addWidget(outputTableWidget, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 2);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(91, 16));
        label_3->setMaximumSize(QSize(91, 16));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_16->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer);

        resultsPushButton = new QPushButton(scrollAreaWidgetContents);
        resultsPushButton->setObjectName(QStringLiteral("resultsPushButton"));
        resultsPushButton->setMinimumSize(QSize(117, 23));
        resultsPushButton->setMaximumSize(QSize(117, 23));
        resultsPushButton->setFont(font1);

        horizontalLayout_16->addWidget(resultsPushButton);

        plotExportPushButton = new QPushButton(scrollAreaWidgetContents);
        plotExportPushButton->setObjectName(QStringLiteral("plotExportPushButton"));
        plotExportPushButton->setMinimumSize(QSize(117, 0));
        plotExportPushButton->setMaximumSize(QSize(117, 23));
        plotExportPushButton->setFont(font1);

        horizontalLayout_16->addWidget(plotExportPushButton);


        gridLayout_3->addLayout(horizontalLayout_16, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1033, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        inputParGroupBox->setTitle(QApplication::translate("MainWindow", "Input parameters", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Set service class parameters", 0));
        label_8->setText(QApplication::translate("MainWindow", "Service class:", 0));
        selServClassComboBox->clear();
        selServClassComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
        );
        modelTypeLabel->setText(QApplication::translate("MainWindow", "Model:", 0));
        erlangRadioButton->setText(QApplication::translate("MainWindow", "Erlang", 0));
        engsetRadioButton->setText(QApplication::translate("MainWindow", "Engset", 0));
        setaRadioButton->setText(QApplication::translate("MainWindow", "set a", 0));
        set_lm_Or_vm_RadioButton->setText(QApplication::translate("MainWindow", "Set \316\273, \316\274", 0));
        aLabel->setText(QApplication::translate("MainWindow", "Traffic load, a:", 0));
        l_Or_v_Label->setText(QApplication::translate("MainWindow", "Call rate, \316\273:", 0));
        mLabel->setText(QApplication::translate("MainWindow", "Termination rate, \316\274:", 0));
        NLabel->setText(QApplication::translate("MainWindow", "Total sources, N:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Service class demand, b:", 0));
        trunkResLabel->setText(QApplication::translate("MainWindow", "Trunk reservation, t:", 0));
        blockProbLabel->setText(QApplication::translate("MainWindow", "Blocking Probability, Pb:", 0));
        QTableWidgetItem *___qtablewidgetitem = inputTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Serv. class", 0));
        QTableWidgetItem *___qtablewidgetitem1 = inputTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "a", 0));
        QTableWidgetItem *___qtablewidgetitem2 = inputTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "b", 0));
        QTableWidgetItem *___qtablewidgetitem3 = inputTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "t", 0));
        QTableWidgetItem *___qtablewidgetitem4 = inputTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "N", 0));
        QTableWidgetItem *___qtablewidgetitem5 = inputTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Pb", 0));
        QTableWidgetItem *___qtablewidgetitem6 = inputTableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "model", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Set", 0));
        exportInputPushButton->setText(QApplication::translate("MainWindow", "Export", 0));
        importInputPushButton->setText(QApplication::translate("MainWindow", "Import", 0));
        linkCapacityLabel->setText(QApplication::translate("MainWindow", "Link capacity, C:", 0));
        label_6->setText(QApplication::translate("MainWindow", "Number of service classes:", 0));
        trunkResCheckBox->setText(QApplication::translate("MainWindow", "Trunk reservation", 0));
        label_10->setText(QApplication::translate("MainWindow", "Calculate:", 0));
        selBlockProbRadioButton->setText(QApplication::translate("MainWindow", "Blocking probabilities etc.", 0));
        selLinkCapacityRadioButton->setText(QApplication::translate("MainWindow", "Link capacity", 0));
        label->setText(QApplication::translate("MainWindow", "Model:", 0));
        selectModelComboBox->clear();
        selectModelComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "EMLM (Kaufman - Roberts)", 0)
         << QApplication::translate("MainWindow", "EnMLM (Stasiak - Glabowski)", 0)
         << QApplication::translate("MainWindow", "EMLM - EnMLM", 0)
        );
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Output results", 0));
        blockProbGroupBox->setTitle(QApplication::translate("MainWindow", "Blocking probabilities / Mean values", 0));
        QTableWidgetItem *___qtablewidgetitem7 = blockingProbTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Serv. class", 0));
        QTableWidgetItem *___qtablewidgetitem8 = blockingProbTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Pbk", 0));
        QTableWidgetItem *___qtablewidgetitem9 = blockingProbTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "E(nk)", 0));
        label_9->setText(QApplication::translate("MainWindow", "Link utilization:", 0));
        linkUtLabel->setText(QString());
        linkCapacityGroupBox->setTitle(QApplication::translate("MainWindow", "Link capacity", 0));
        label_11->setText(QApplication::translate("MainWindow", "C:", 0));
        linkCapacityOutLabel->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Intermediate calculations", 0));
        QTableWidgetItem *___qtablewidgetitem10 = ykjTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "state, j", 0));
        QTableWidgetItem *___qtablewidgetitem11 = ykjTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "y1(j)", 0));
        QTableWidgetItem *___qtablewidgetitem12 = ykjTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "y2(j)", 0));
        QTableWidgetItem *___qtablewidgetitem13 = outputTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "state, j", 0));
        QTableWidgetItem *___qtablewidgetitem14 = outputTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "q(j)", 0));
        QTableWidgetItem *___qtablewidgetitem15 = outputTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "P(j)", 0));
        label_3->setText(QApplication::translate("MainWindow", "\302\251 Panagoulias P.", 0));
        resultsPushButton->setText(QApplication::translate("MainWindow", "Calculate", 0));
        plotExportPushButton->setText(QApplication::translate("MainWindow", "Plot / Export >", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
