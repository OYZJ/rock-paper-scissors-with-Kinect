#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <thread.h>
#include <iostream>
#include "global.h"

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

//#include "com.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include<QApplication>
#include<QTime>


void sleep(unsigned int msec)
   {
    QTime reachTime=QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}




using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    initStyle();
   connect(&oythread,SIGNAL(oySignal(int)),this,SLOT(on_gesture(int)));


   // connect(&timer,SIGNAL(timeout()),this,SLOT(updateReceive()));
   // timer.start(1);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    oythread.start();
    ui->pushButton->setEnabled(true);


if(m_serialPort.open(QIODevice::ReadWrite))
{

}
m_serialPort.write("3");
sleep(500);
HS_robot=rand()%3;

      //HS_robot=rand()%3;

      QString str = QString::number(HS_robot);
  //    QString str = ui->textEdit->document()->toPlainText();

     // sendData = str.toLatin1();
    QByteArray sendData = str.toUtf8();

     m_serialPort.write(sendData);

     // sendCout += str.count();
      //ui->label_10->setText(tr("发送：") + QString::number(sendCout));


      switch(HS_robot-HS_person)
      {
      case -2: case 1:

              ui->label_2->setText("draw!");
          break;
      case -1:
              ui->label_2->setText("you win!");
           sumhuman++;break;
      case 0: case -3:
          ui->label_2->setText("you lose!");
           sumrobot++;break;
      }

}
void MainWindow::on_gesture(int x)
{
    HS_person=x;
   // cout<<x<<endl;
    switch (x)
    {
    case HAND_CLOSE:
        ui->label->setText("Person_close");
        break;
    case HAND_OPEN:
        ui->label->setText("Person_open");
        break;
    case HAND_LASSO:
        ui->label->setText("Person_lasso");
        break;
    default:
        break;
    }
    switch (HS_robot) {
    case 0:
        ui->label_3->setText("Robot_close");
        break;
    case 1:
        ui->label_3->setText("Robot_lasso");
        break;
    case 2:
        ui->label_3->setText("Robot_open");
        break;
    default:
        break;
    }
    QString strr = QString::number(sumrobot);
  QByteArray sendDatarobot = strr.toUtf8();
  QString strrr = QString::number(sumhuman);
QByteArray sendDatahuman = strrr.toUtf8();
    ui->label_4->setText(sendDatarobot);
    ui->label_5->setText(sendDatahuman);
}

void MainWindow::initStyle()
{   QString qss;
    QFile qssFile(":/rc/stylesheet.qss");
     qssFile.open(QFile::ReadOnly);
     if(qssFile.isOpen())
     {   qss = QLatin1String(qssFile.readAll());
         qApp->setStyleSheet(qss);
         qssFile.close();
     }
     ui->label->setAlignment(Qt::AlignCenter);
}




void MainWindow::on_pushButton_2_clicked()
{
    static bool btnflag = false;
    if(btnflag == false)
    {
    m_serialPort.setPortName("COM6");
    m_serialPort.setBaudRate(9600);
    m_serialPort.setDataBits(QSerialPort::Data8);

    m_serialPort.setStopBits(QSerialPort::OneStop);
    m_serialPort.setParity(QSerialPort::NoParity);
    timer.start(1);

    btnflag = true;
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    sumrobot=0;
    sumhuman=0;
}


void MainWindow::on_pushButton_4_clicked()
{
    if(m_serialPort.open(QIODevice::ReadWrite))
    {

    }
    m_serialPort.write("4");

}
