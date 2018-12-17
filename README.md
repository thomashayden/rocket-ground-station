# rocket-ground-station
The ground station software for the Battle of the Rockets competition

This software runs on a Raspberry Pi and communicates with the payload. It commands it to start actions using physical buttons, and recieves images which are displayed on the screen.

## Compiling for the pi
Because the raspberry pi runs an arm chip, the version qt creator compiles on your computer doesn't work. There is a way to cross compile, but thats complicated and this program is quite simple, so I wanted to just compile it on the pi itself. To do this, first make sure the following is installed on the pi:

    sudo apt-get install qt5-default
    sudo apt-get install qtcreator

Once those are installed, it can be compiled and run using the following commands:

    make
    qmake
    ./GroundStation

Note that in order to start it (and just it, no DE) when there is no x server running, use the startx command:

    startx ./GroundStation
