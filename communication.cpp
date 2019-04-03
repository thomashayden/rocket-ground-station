// Might have to disable serial console: https://www.raspberrypi.org/forums/viewtopic.php?p=600981#p600981

#include "communication.h"

Communication::Communication()
{

}

bool Communication::Move()
{
    std::string base = "sudo python3 move.py";
    system(base.c_str());

    return true;
}

bool Communication::Collect()
{
    std::string base = "sudo python3 collect.py";
    system(base.c_str());

    return true;
}
