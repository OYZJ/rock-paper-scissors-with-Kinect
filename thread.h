#ifndef THREAD
#define THREAD
#include <QThread>
#include "myKinect.h"
class Thread :public QThread
{
    Q_OBJECT

signals:
   void  oySignal(int x);
public:
    virtual  void run();
    Thread();



};

#endif // THREAD

