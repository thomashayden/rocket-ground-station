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

    startx ./GroundStation -- -nocursor
    
Quick rant: I found basically no documentation on using startx to run a single program. This proved frustrating cause basically nowhere was `-nocursor` mentioned. Turns out that `--` is used to separate the arguments form the program and startx. So all the arguments for `./GroundStation` go before `--` and all the arguments for startx go after `--`. It doesn't work if you put `-nocursor` before `./GroundStation`, which doesn't make any sense, but oh well. And I also don't like that `-nocursor` only has one dash and not two. <\endrant>

To start the program after booting into a tty, the following line can be put into the default user's `.bashrc` (with whatever the path to the GroundStation executable is):

    startx ./rocket-ground-station/GroundStation -- -nocursor
