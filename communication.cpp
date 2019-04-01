// Might have to disable serial console: https://www.raspberrypi.org/forums/viewtopic.php?p=600981#p600981

#include "communication.h"

Communication::Communication()
{

}

bool Communication::Write(char* data)
{
    std::string base = "python3 ";
    std::string debug_location = QCoreApplication::applicationDirPath().toUtf8().constData();
    std::string result = base.append(debug_location.substr(0, debug_location.size()-33)).append("GroundStation/write.py ").append(data);
    system(result.c_str());

    return true;
}

bool Communication::SaveImage(char* save_location)
{
    std::string base = "python3 ";
    std::string debug_location = QCoreApplication::applicationDirPath().toUtf8().constData();
    std::string result = base.append(debug_location.substr(0, debug_location.size()-33)).append("GroundStation/save_image.py ").append(save_location);
    system(result.c_str());

    return true;
}
