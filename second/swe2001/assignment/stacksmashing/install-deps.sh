#!/bin/bash


if [ $(lsb_release -si) == "Ubuntu" ]; then
   sudo apt install gdb tmux python3 python3-pip -y
else
    echo "If you're using something other than ubuntu, you probably know what you're doing. So you're on your own :) Install gdb, tmux, python3, pip, and python library pwntools "
fi

pip3 install pwntools



