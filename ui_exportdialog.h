/********************************************************************************
** Form generated from reading UI file 'exportdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTDIALOG_H
#define UI_EXPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExportDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QRadioButton *txtRadioButton;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *csvRadioButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *selDelimComboBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *folderNameLineEdit;
    QPushButton *pushButton;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *fileNameLineEdit;

    void setupUi(QDialog *ExportDialog)
    {
        if (ExportDialog->objectName().isEmpty())
            ExportDialog->setObjectName(QStringLiteral("ExportDialog"));
        ExportDialog->resize(587, 235);
        buttonBox = new QDialogButtonBox(ExportDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(230, 190, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(ExportDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 0, 224, 101));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        txtRadioButton = new QRadioButton(layoutWidget);
        txtRadioButton->setObjectName(QStringLiteral("txtRadioButton"));

        horizontalLayout->addWidget(txtRadioButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        csvRadioButton = new QRadioButton(layoutWidget);
        csvRadioButton->setObjectName(QStringLiteral("csvRadioButton"));

        horizontalLayout_4->addWidget(csvRadioButton);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        selDelimComboBox = new QComboBox(layoutWidget);
        selDelimComboBox->setObjectName(QStringLiteral("selDelimComboBox"));
        selDelimComboBox->setMinimumSize(QSize(50, 0));
        selDelimComboBox->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(selDelimComboBox);


        verticalLayout->addLayout(horizontalLayout_4);

        layoutWidget1 = new QWidget(ExportDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 150, 551, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        folderNameLineEdit = new QLineEdit(layoutWidget1);
        folderNameLineEdit->setObjectName(QStringLiteral("folderNameLineEdit"));

        horizontalLayout_2->addWidget(folderNameLineEdit);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_2->addWidget(pushButton);

        layoutWidget2 = new QWidget(ExportDialog);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 120, 551, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        fileNameLineEdit = new QLineEdit(layoutWidget2);
        fileNameLineEdit->setObjectName(QStringLiteral("fileNameLineEdit"));

        horizontalLayout_3->addWidget(fileNameLineEdit);


        retranslateUi(ExportDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ExportDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ExportDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ExportDialog);
    } // setupUi

    void retranslateUi(QDialog *ExportDialog)
    {
        ExportDialog->setWindowTitle(QApplication::translate("ExportDialog", "Export to file", 0));
        label->setText(QApplication::translate("ExportDialog", "Select export file type:", 0));
        txtRadioButton->setText(QApplication::translate("ExportDialog", "txt", 0));
        csvRadioButton->setText(QApplication::translate("ExportDialog", "csv", 0));
        label_2->setText(QApplication::translate("ExportDialog", "delimeter:", 0));
        selDelimComboBox->clear();
        selDelimComboBox->insertItems(0, QStringList()
         << QApplication::translate("ExportDialog", ",", 0)
         << QApplication::translate("ExportDialog", ";", 0)
        );
        label_4->setText(QApplication::translate("ExportDialog", "Create in:", 0));
        pushButton->setText(QApplication::translate("ExportDialog", "Browse ..", 0));
        label_3->setText(QApplication::translate("ExportDialog", "File name:", 0));
    } // retranslateUi

};

namespace Ui {
    class ExportDialog: public Ui_ExportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTDIALOG_H
