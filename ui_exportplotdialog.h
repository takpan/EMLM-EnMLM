/********************************************************************************
** Form generated from reading UI file 'exportplotdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTPLOTDIALOG_H
#define UI_EXPORTPLOTDIALOG_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExportPlotDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *folderNameLineEdit;
    QPushButton *browsePushButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *fileNameLineEdit;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *fileTypeComboBox;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpinBox *widthSpinBox;
    QLabel *label_6;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QSpinBox *heightSpinBox;
    QLabel *label_7;

    void setupUi(QDialog *ExportPlotDialog)
    {
        if (ExportPlotDialog->objectName().isEmpty())
            ExportPlotDialog->setObjectName(QStringLiteral("ExportPlotDialog"));
        ExportPlotDialog->resize(573, 231);
        QIcon icon;
        icon.addFile(QStringLiteral("logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        ExportPlotDialog->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(ExportPlotDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(220, 190, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget_2 = new QWidget(ExportPlotDialog);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 150, 551, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        folderNameLineEdit = new QLineEdit(layoutWidget_2);
        folderNameLineEdit->setObjectName(QStringLiteral("folderNameLineEdit"));

        horizontalLayout_2->addWidget(folderNameLineEdit);

        browsePushButton = new QPushButton(layoutWidget_2);
        browsePushButton->setObjectName(QStringLiteral("browsePushButton"));
        browsePushButton->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_2->addWidget(browsePushButton);

        layoutWidget = new QWidget(ExportPlotDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 120, 551, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        fileNameLineEdit = new QLineEdit(layoutWidget);
        fileNameLineEdit->setObjectName(QStringLiteral("fileNameLineEdit"));

        horizontalLayout_3->addWidget(fileNameLineEdit);

        layoutWidget_3 = new QWidget(ExportPlotDialog);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 10, 131, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget_3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        fileTypeComboBox = new QComboBox(layoutWidget_3);
        fileTypeComboBox->setObjectName(QStringLiteral("fileTypeComboBox"));

        horizontalLayout->addWidget(fileTypeComboBox);

        layoutWidget_4 = new QWidget(ExportPlotDialog);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 50, 133, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(35, 0));

        horizontalLayout_4->addWidget(label_2);

        widthSpinBox = new QSpinBox(layoutWidget_4);
        widthSpinBox->setObjectName(QStringLiteral("widthSpinBox"));
        widthSpinBox->setMinimumSize(QSize(50, 0));
        widthSpinBox->setMaximum(10000);

        horizontalLayout_4->addWidget(widthSpinBox);

        label_6 = new QLabel(layoutWidget_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        layoutWidget_5 = new QWidget(ExportPlotDialog);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 80, 131, 22));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(35, 0));

        horizontalLayout_5->addWidget(label_3);

        heightSpinBox = new QSpinBox(layoutWidget_5);
        heightSpinBox->setObjectName(QStringLiteral("heightSpinBox"));
        heightSpinBox->setMinimumSize(QSize(50, 0));
        heightSpinBox->setMaximum(10000);

        horizontalLayout_5->addWidget(heightSpinBox);

        label_7 = new QLabel(layoutWidget_5);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);


        retranslateUi(ExportPlotDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ExportPlotDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ExportPlotDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ExportPlotDialog);
    } // setupUi

    void retranslateUi(QDialog *ExportPlotDialog)
    {
        ExportPlotDialog->setWindowTitle(QApplication::translate("ExportPlotDialog", "Export", 0));
        label_5->setText(QApplication::translate("ExportPlotDialog", "Create in:", 0));
        browsePushButton->setText(QApplication::translate("ExportPlotDialog", "Browse ..", 0));
        label_4->setText(QApplication::translate("ExportPlotDialog", "File name:", 0));
        label->setText(QApplication::translate("ExportPlotDialog", "File format:", 0));
        fileTypeComboBox->clear();
        fileTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("ExportPlotDialog", "Pdf", 0)
         << QApplication::translate("ExportPlotDialog", "Png", 0)
         << QApplication::translate("ExportPlotDialog", "Jpg", 0)
         << QApplication::translate("ExportPlotDialog", "Bmp", 0)
        );
        label_2->setText(QApplication::translate("ExportPlotDialog", "Width:", 0));
        label_6->setText(QApplication::translate("ExportPlotDialog", "px", 0));
        label_3->setText(QApplication::translate("ExportPlotDialog", "Height:", 0));
        label_7->setText(QApplication::translate("ExportPlotDialog", "px", 0));
    } // retranslateUi

};

namespace Ui {
    class ExportPlotDialog: public Ui_ExportPlotDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTPLOTDIALOG_H
