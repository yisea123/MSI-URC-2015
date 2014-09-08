#!/bin/bash
. ~/.bashrc
@msi
rosrun map_generation opencv_node &
rosrun gazebo_ros gzserver worlds/$1.world --verbose
