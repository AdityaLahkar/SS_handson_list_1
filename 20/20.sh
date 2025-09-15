#!/bin/bash

./20.out &

PID=$!

echo "current nice value:"
ps -o pid,ni,comm | grep " $PID "

renice -n 10 -p $PID

echo "new nice value:"
ps -o pid,ni,comm | grep " $PID "

kill $PID