#!/bin/bash

pid=$1
timestamp=$2

readable_time=$(date -d "@$timestamp" "+%Y-%m-%d %H:%M:%S")
echo "Daemon PID: $pid ran script at $readable_time" >> ~/Desktop/iiitb/Sem1/SS/OS/handsonlist1/30/daemon_log.txt