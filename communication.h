#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <string>
#include <python2.7/Python.h>
#include <QCoreApplication>

class Communication
{
public:
    Communication();
    bool Move();
    bool Collect();
};

#endif // COMMUNICATION_H
