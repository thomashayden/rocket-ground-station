#!/bin/bash
echo "4" > /sys/class/gpio/export
echo "in" > /sys/class/gpio/gpio4/direction
echo "3" > /sys/class/gpio/export
echo "in" > /sys/class/gpio/gpio3/direction


if [[ $(cat /sys/class/gpio/gpio4/value) == 1 ]]
then
    sleep 0.01
    if [[ $(cat /sys/class/gpio/gpio4/value) == 1 ]]
    then
        rm ./comm/gpio4high
        touch ./comm/gpio4low # These are the wrong way around because it is normally high while open
    fi
else
    sleep 0.01
    if [[ $(cat /sys/class/gpio/gpio4/value) != 1 ]]
    then
        rm ./comm/gpio4low
        touch ./comm/gpio4high
    fi
fi


if [[ $(cat /sys/class/gpio/gpio3/value) == 1 ]]
then
    sleep 0.01
    if [[ $(cat /sys/class/gpio/gpio3/value) == 1 ]]
    then
        rm ./comm/gpio3high
        touch ./comm/gpio3low # These are the wrong way around because it is normally high while open
    fi
else
    sleep 0.01
    if [[ $(cat /sys/class/gpio/gpio3/value) != 1 ]]
    then
        rm ./comm/gpio3low
        touch ./comm/gpio3high
    fi
fi

echo "4" >> /sys/class/gpio/unexport
echo "3" >> /sys/class/gpio/unexport
