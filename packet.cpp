#include "packet.h"

#include <QDebug>

Packet::Packet()
{

}

bool Packet::Start(QSerialPort *serialPort,IHandle *pHandle)
{
    m_serialPort = serialPort;
    m_pHandle = pHandle;
    this->start();
    qDebug()<<"thread start!";
    return true;
}

void Packet::Close()
{
    this->terminate();
    m_serialPort = NULL;
    qDebug()<<"thread terminal!";
}

void Packet::run()
{
    while (true)
    {
        ReceivePacket();
        //this->msleep(20);
    }
}

void Packet::PacketProc(quint8 *data, quint8 len)
{
    quint8 *packet;

    packet = data;
    packet = packet;
    len = len;
}

void Packet::ReceivePacket()
{
    QByteArray receiveData;
    receiveData = m_serialPort->readAll();
    QString str = QString(receiveData);

    if(!receiveData.isEmpty())
    {
        m_pHandle->display(str);
        qDebug()<<str;
    }
    receiveData.clear();
}

bool Packet::SendPacket(quint8 *data, quint8 len)
{
    quint8 *packet;

    packet = data;
    packet = packet;
    len = len;
    return true;
}




















