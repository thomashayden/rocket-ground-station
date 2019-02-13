// Might have to disable serial console: https://www.raspberrypi.org/forums/viewtopic.php?p=600981#p600981

#include "communication.h"

Communication::Communication()
{

}

bool Communication::Write(const std::string* data)
{
    // Run python writing program with the given argument
}

bool Communication::SaveImage(const std::string* save_location)
{
    // Run python reading program which saves the recieved image to the specified location
}
