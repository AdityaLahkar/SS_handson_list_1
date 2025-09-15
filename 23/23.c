/*
============================================================================
Name: 23.c

Author: Aditya Lahkar

Description: Write a program to create a Zombie state of the running program. 

Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT
    parent process: pid = 21961, child pid = 21962
*/

#include<stdio.h>
#include<unistd.h>

int main(){
    int pid = fork();
    if(pid){
        printf("parent process: pid = %d, child pid = %d\n", getpid(), pid);
        sleep(30);
        return 0;
    }
    else{
        return 0;
    }
}