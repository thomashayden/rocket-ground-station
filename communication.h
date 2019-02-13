#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <string>

class Communication
{
public:
    Communication();
    bool Write(const std::string*);
    bool SaveImage(const std::string*);
};

#endif // COMMUNICATION_H
