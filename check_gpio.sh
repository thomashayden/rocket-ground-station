#!/bin/bash
echo "4" > /sys/class/gpio/export
echo "in" > /sys/class/gpio/gpio4/direction

if [[ $(cat /sys/class/gpio/gpio4/value) == 1 ]]
then
    sleep 0.1
    if [[ $(cat /sys/class/gpio/gpio4/value) == 1 ]]
    then
        rm ./comm/*
        touch ./comm/gpio5high
    fi
else
    sleep 0.1
    if [[ $(cat /sys/class/gpio/gpio4/value) != 1 ]]
    then
        rm ./comm/*
        touch ./comm/gpio4low
    fi
fi

echo "4" >> /sys/class/gpio/unexport
