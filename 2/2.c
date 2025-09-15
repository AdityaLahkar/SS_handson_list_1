/*
============================================================================
Name : 2.c
Author : Aditya Lahkar

Description : Write a simple program to execute in an infinite loop at the 
background. Go to /proc directory and identify all the process related 
information in the corresponding proc directory

Date: 7th sept, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


void main(){    
    while(1);
}

/* in the shell run ./a.out & copy the <PID> and then run cat /proc/<PID>/status */