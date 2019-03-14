#!/bin/bash
clear
echo "Verifying Dependencies..."
DIR="`pwd`"
BIN="/usr/bin"
LOCAL="/usr/share/Chaos_V0.1"
LAUNCHER="/home/$USER/.local/share/applications"
ans="find /usr/bin/ -iname root*"
if [ "${ans:-NULL}" = "NULL" ]; 
then
    echo "You need install ROOT framework!"
else
    echo "ROOT is Installed!"
    ans="`dpkg -l | grep octave`"
    if [ "${ans:-NULL}" = "NULL" ]; 
    then
	echo "You need install Octave package!"
	echo "For install execute:"
	echo "$sudo apt install octave"
    else
	echo "Octave is Installed!"
        ans="`dpkg -l | grep xutils-dev`"
	if [ "${ans:-NULL}" = "NULL" ]; 
	then
	    echo "You need install xutils-dev package!"
	    echo "For install execute:"
	    echo "$sudo apt install xutils-dev"
	else
	    echo "xutils-dev is Installed!"
	    echo " "
	    echo " "
	    echo "Verifying Successful!"
	    echo " "
	    echo "Compiling ..."
	    echo "For continue the installation, you need to be root user!"
	    # Create LOCAL FILES
	    sudo mkdir $LOCAL
	    sudo cp -r icon/* $LOCAL
	    sudo cp -r images/* $LOCAL
	    sudo cp -r include/* $LOCAL
	    sudo cp -r src/* $LOCAL
	    sudo cp -r Chaos.cxx $LOCAL
	    echo "Create Local Files!"
	    make
	    make clean	   
	    echo " "
	    echo " "
	    echo "Compiling Successful!"
	    echo " "
	    echo "Creating link!"
	    sudo cp $DIR/Chaos $LOCAL/Chaos
	    echo "here1"
	    sudo ln -d -s -f $LOCAL/Chaos $BIN/Chaos
	    echo $LAUNCHER
	    echo "here2"
	    sudo cp $DIR/files/Chaos.desktop $LAUNCHER
	    #Add Permisions 	
	    echo "here3"
	    sudo chmod ugo+xwr -R $LOCAL
	    sudo chmod u+xwr $BIN/Chaos
	    sudo chmod a+wxr $LAUNCHER/Chaos.desktop
	    echo "Installation Successful!"
	    echo "For running Chaos from terminal execute:"
	    echo "$ Chaos"
	fi
    fi
fi
