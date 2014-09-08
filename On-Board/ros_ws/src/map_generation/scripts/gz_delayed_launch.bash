#!/bin/bash
. ~/.bashrc
@msi
rosrun map_generation opencv_node &
if [ $2 -ne 1 ]; then
rosrun gazebo_ros gzserver worlds/$1.world --verbose
else
rosrun gazebo_ros gazebo worlds/$1.world --verbose
fi
