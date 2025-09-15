/*
============================================================================
Name: 28.c

Author: Aditya Lahkar

Description:  Write a program to get maximum and minimum real time priority.

Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT
    maximum real time priority value of fifo: 99
    minimum real time priority value of fifo: 1
    maximum real time priority value of round robin: 99
    minimum real time priority value of round robin: 1*/

#include<stdio.h>
#include<sched.h>

int main(){
    printf("maximum real time priority value of fifo: %d\n", sched_get_priority_max(SCHED_FIFO));
    printf("minimum real time priority value of fifo: %d\n", sched_get_priority_min(SCHED_FIFO));
    printf("maximum real time priority value of round robin: %d\n", sched_get_priority_max(SCHED_RR));
    printf("minimum real time priority value of round robin: %d\n", sched_get_priority_min(SCHED_RR));
    return 0;
}