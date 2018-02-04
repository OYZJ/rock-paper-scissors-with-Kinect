#ifndef PACKET_H
#define PACKET_H

#include <QThread>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>


#include "ihandle.h"



class Packet : public QThread
{
    Q_OBJECT
public:
    Packet();

public:
    bool Start(QSerialPort *serialPort,IHandle *pHandle);
    void Close();

protected:
    void run();

private:
    void ReceivePacket();
    bool SendPacket(quint8 *data,quint8 len);
    void PacketProc(quint8 *data,quint8 len);

private:
    QSerialPort *m_serialPort;
    IHandle *m_pHandle;
};

#endif // PACKET_H
