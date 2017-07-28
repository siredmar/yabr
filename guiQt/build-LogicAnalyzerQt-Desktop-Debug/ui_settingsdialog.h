/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QComboBox *cB_SerialPorts;
    QComboBox *cB_Baudrate;
    QPushButton *btn_Ok;
    QPushButton *btn_Cancel;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
        SettingsDialog->setWindowModality(Qt::ApplicationModal);
        SettingsDialog->resize(226, 113);
        SettingsDialog->setMinimumSize(QSize(226, 113));
        SettingsDialog->setMaximumSize(QSize(226, 113));
        cB_SerialPorts = new QComboBox(SettingsDialog);
        cB_SerialPorts->setObjectName(QString::fromUtf8("cB_SerialPorts"));
        cB_SerialPorts->setGeometry(QRect(100, 10, 91, 22));
        cB_Baudrate = new QComboBox(SettingsDialog);
        cB_Baudrate->setObjectName(QString::fromUtf8("cB_Baudrate"));
        cB_Baudrate->setGeometry(QRect(100, 40, 91, 22));
        btn_Ok = new QPushButton(SettingsDialog);
        btn_Ok->setObjectName(QString::fromUtf8("btn_Ok"));
        btn_Ok->setGeometry(QRect(120, 80, 81, 22));
        btn_Cancel = new QPushButton(SettingsDialog);
        btn_Cancel->setObjectName(QString::fromUtf8("btn_Cancel"));
        btn_Cancel->setGeometry(QRect(20, 80, 81, 22));
        label = new QLabel(SettingsDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 81, 16));
        label_2 = new QLabel(SettingsDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 42, 81, 20));

        retranslateUi(SettingsDialog);

        cB_Baudrate->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Settings", 0, QApplication::UnicodeUTF8));
        cB_Baudrate->clear();
        cB_Baudrate->insertItems(0, QStringList()
         << QApplication::translate("SettingsDialog", "9600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "19200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "38400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "57600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "115200", 0, QApplication::UnicodeUTF8)
        );
        btn_Ok->setText(QApplication::translate("SettingsDialog", "Ok", 0, QApplication::UnicodeUTF8));
        btn_Cancel->setText(QApplication::translate("SettingsDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SettingsDialog", "Serial Port", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SettingsDialog", "Baudrate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
