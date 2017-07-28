#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include "qextserialport.h"
#include "qextserialenumerator.h"
#include <QListView>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();

    int portIndex = -1;
    NumberOfSerialPorts = ports.size();
    for (int i = 0; i < ports.size(); i++)
    {
        ui->cB_SerialPorts->addItem(ports.at(i).portName.toLocal8Bit().constData());
    }
    initDone = true;
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}
/* Button callbacks */
void SettingsDialog::on_btn_Cancel_clicked()
{
    this->close();
}


void SettingsDialog::on_btn_Ok_clicked()
{
    parent->SetSelctedBaudrateLabel(SelectedBaudrateIndex);
    this->parent->SetSelectedSerialPortLabel(comPortName, SelectedSerialPortIndex);
    this->close();
}

/* Combobox callbacks */

void SettingsDialog::on_cB_Baudrate_currentIndexChanged(int index)
{
    SelectedBaudrateIndex = index;
}

void SettingsDialog::on_cB_SerialPorts_currentIndexChanged(int index)
{
    SelectedSerialPortIndex = index;
    if(initDone == true)
    {
        comPortName = this->ui->cB_SerialPorts->currentText();
    }
}

/* Setting configuration helper functions */
void SettingsDialog::RegisterParentClass(MainWindow *_parent)
{
    this->parent = _parent;
}

void SettingsDialog::SetCurrentBaudrateIndex(int index)
{
    ui->cB_Baudrate->setCurrentIndex(index);
}

void SettingsDialog::SetCurrentSerialIndex(int index)
{
    if(index <= NumberOfSerialPorts)
    {
        this->ui->cB_SerialPorts->setCurrentIndex(index);
    }
    else
    {
        this->ui->cB_SerialPorts->setCurrentIndex(0);
        this->ui->cB_Baudrate->setCurrentIndex(0);
    }
}



