#!/bin/bash
. ~/.bash_aliases
rosrun msi_rover opencv &
cv=$!
if [ $2 -ne 1 ]; then
rosrun gazebo_ros gzserver worlds/$1.world --verbose
else
rosrun gazebo_ros gazebo worlds/$1.world --verbose
fi
kill $cv &> /dev/null
