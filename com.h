#ifndef COM_H
#define COM_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QThread>

#include "packet.h"
#include "ihandle.h"



namespace Ui {
class Com;
}

class Com : public QWidget,public IHandle
{
    Q_OBJECT

public:
    explicit Com(QWidget *parent = 0);
    ~Com();

//private slots:
  //  void on_pushButton_clicked();




private:
    Ui::Com *ui;

public:
    quint32 sendCout;
    //quint32 receiveCout;

public:
   // Packet m_packet;
    QSerialPort m_serialPort;
    QTimer timer;
    QTimer timerAutoSend;
    QThread m_thead;


};

#endif // COM_H
