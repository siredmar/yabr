#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    void RegisterParentClass(MainWindow *_parent);
    void SetCurrentBaudrateIndex(int index);
    void SetCurrentSerialIndex(int index);
    ~SettingsDialog();

private slots:
    void on_btn_Cancel_clicked();
    void on_cB_Baudrate_currentIndexChanged(int index);
    void on_cB_SerialPorts_currentIndexChanged(int index);
    void on_btn_Ok_clicked();

private:
    bool initDone = false;
    int NumberOfSerialPorts = -1;
    QString comPortName;
    int SelectedBaudrateIndex = -1;
    int SelectedSerialPortIndex = -1;
    MainWindow *parent;
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
