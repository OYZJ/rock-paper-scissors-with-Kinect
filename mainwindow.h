#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "thread.h"
#include <QFile>

#define HAND_OPEN 1
#define HAND_CLOSE 2
#define HAND_LASSO 3
#define HAND_NOTHING 0
#include <QTimer>

#include "packet.h"
#include "ihandle.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initStyle(void);
    Thread oythread;
    QSerialPort m_serialPort;
    QTimer timer;
    //quint32 sendCout;
   // QThread m_thead;

private slots:
    void on_pushButton_clicked();
    void on_gesture(int x);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();



    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

//public:
   //
    //quint32 receiveCout;

//public:
   // Packet m_packet;

   // QTimer timer;
    //QTimer timerAutoSend;



};

#endif // MAINWINDOW_H
