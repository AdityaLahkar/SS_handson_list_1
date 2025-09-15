/*
============================================================================
Name: 24.c

Author: Aditya Lahkar

Description: Write a program to create an orphan process. 

Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT
    child process: pid = 22261, parent pid = 22260
    child process: parent id now = 3190
*/

#include<stdio.h>
#include<unistd.h>

int main(){
    int pid = fork();
    if(pid){
        sleep(1);
        return 0;
    }
    else{
        printf("child process: pid = %d, parent pid = %d\n", getpid(), getppid());
        sleep(2);
        printf("child process: parent id now = %d\n", getppid());
        return 0;
    }
}