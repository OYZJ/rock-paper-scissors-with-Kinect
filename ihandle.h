#ifndef IHANDLE_H
#define IHANDLE_H

#include <QByteArray>

class IHandle
{
public:
    virtual void display(QString data)=0;
};

#endif // IHANDLE_H
