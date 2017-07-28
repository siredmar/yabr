#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <qextserialport.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int BaudrateIndex = 0;
    int SerialPortIndex = 0;
    int SerialPortBaudrate = 0;
    QString SerialPortName = "";
    void SetSelctedBaudrateLabel(int index);
    void SetSelectedSerialPortLabel(QString port, int index);

private slots:
    void on_actionSettings_triggered();
    void on_actionQuit_triggered();
    void on_actionStart_triggered();
    void on_actionStop_triggered();
    void onReadyRead();

private:

    struct MeasurementResponse
    {
        QString str;
        int timestamp;
        quint8 value;
    };

    bool SerialPortOpen;
    QextSerialPort *port;
    void OpenSettingsWindow(void);
    void ConnectToSerial(void);
    Ui::MainWindow *ui;
    QString CalculateBaudrateFromIndex(int index);
    MeasurementResponse ParseSerialData(QByteArray *buf);
};

#endif // MAINWINDOW_H
