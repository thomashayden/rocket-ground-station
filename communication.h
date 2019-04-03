#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <string>
#include <python2.7/Python.h>
#include <QCoreApplication>

class Communication
{
public:
    Communication();
    bool Write();
    bool SaveImage();
};

#endif // COMMUNICATION_H
