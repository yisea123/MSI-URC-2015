#!/bin/bash

SCRIPT=$(readlink -f $0)
DIR=`dirname $SCRIPT`/ros_ws

cat /usr/share/gazebo/setup.sh | grep $DIR &>/dev/null
if [ $? -ne 0 ]; then
  sudo echo "export GAZEBO_RESOURCE_PATH=$GAZEBO_RESOURCE_PATH:$DIR/gazebo" >> /usr/share/gazebo-4.0/setup.sh
  sudo echo "export GAZEBO_PLUGIN_PATH=$GAZEBO_PLUGIN_PATH:$DIR/gazebo/plugins" >> /usr/share/gazebo-4.0/setup.sh
  sudo echo "export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:$DIR/gazebo/models" >> /usr/share/gazebo-4.0/setup.sh
  sudo echo "export GAZEBO_RESOURCE_PATH=$GAZEBO_RESOURCE_PATH:$DIR/gazebo" >> /usr/share/gazebo/setup.sh
  sudo echo "export GAZEBO_PLUGIN_PATH=$GAZEBO_PLUGIN_PATH:$DIR/gazebo/plugins" >> /usr/share/gazebo/setup.sh
  sudo echo "export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:$DIR/gazebo/models" >> /usr/share/gazebo/setup.sh
fi
source /usr/share/gazebo/setup.sh

echo "#define PACKAGE_PATH \"$DIR/src/msi_rover/\"" > $DIR/src/msi_rover/include/msi_rover.h
cd $DIR
catkin_make

echo -e "\e[01;36m"
printf '%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' '#'
echo -e "\nEnvironment setup complete :)."

cat ~/.bash_aliases | grep "alias @urc='cd $DIR;source $DIR/devel/setup.sh'" &>/dev/null
if [ $? -ne 0 ]; then
 echo "alias @urc='cd $DIR;source $DIR/devel/setup.sh'" >> ~/.bash_aliases
 echo -e "Alias @urc created to change ROS workspace to MSI-URC-2015."
 echo -e "Restart the terminal or source ~/.bashrc to enable it."
fi

printf '\n%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' '#'
echo -e "\e[0m"

