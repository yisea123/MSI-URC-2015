#! /bin/bash

file="`rospack find rover_control`/status/running"
while [ -f $file ]; do
  age=`expr $(date +%s) - $(date +%s -r $file)`
  echo $age
  if [ $age -lt 5 ]; then
    echo "NEW"
  else
    echo "OLD"
    exit
  fi
  sleep 1
done
