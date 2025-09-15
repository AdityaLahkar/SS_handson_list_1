/*
============================================================================
Name: 19.c

Author: Aditya Lahkar

Description: Write a program to find out time taken to execute getpid system call. 
Use time stamp counter. 


Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT
    process id : 19886
    time taken to run getpid system call: 0.000009118 seconds
*/


#include<stdio.h>
#include<unistd.h>
#include<stdint.h>
#include<x86intrin.h>

int main(){
    unsigned long long start, end;
    int pid;

    start = __rdtsc();
    pid = getpid();
    end =__rdtsc();

    printf("process id : %d\n", pid);
    printf("time taken to run getpid system call: %.9f seconds\n", (end - start)/2.5e9);
}