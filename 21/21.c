
/*
============================================================================
Name: 21.c

Author: Aditya Lahkar

Description: Write a program, call fork and print the parent and child 
process id 

Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT
    child process:  pid = 21108, parent pid = 21107
    parent process: pid = 21107
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int pid = fork();
    if(pid < 0){
        perror("fork failed");
        return -1;
    }

    else if(pid == 0){
        printf("child process:  pid = %d, parent pid = %d\n", getpid(), getppid());
    }
    else{
        wait(NULL);
        printf("parent process: pid = %d\n", getpid());
    }
    return 0;
}