/*
============================================================================
Name: 25.c

Author: Aditya Lahkar

Description: Write a program to create three child processes. The parent should 
wait for a particular child (use waitpid system call)

Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT
    2
    child1: pid = 22687 parent pid = 22686
    2
    child2: pid = 22688 parent pid = 22686
    parent process: waited for child process with pid: 22688
    4
    child3: pid = 22689 parent pid = 3190
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    
    int pid_1, pid_2, pid_3;
    
    pid_1 = fork();
    if(!pid_1){
        getchar();
        printf("child1: pid = %d parent pid = %d\n", getpid(), getppid());
        return 0;
    }
    
    pid_2 = fork();
    if(!pid_2){
        getchar();
        printf("child2: pid = %d parent pid = %d\n", getpid(), getppid());
        return 0;
    }

    pid_3 = fork();
    if(!pid_3){
        getchar();
        printf("child3: pid = %d parent pid = %d\n", getpid(), getppid());
        return 0;
    }

    waitpid(pid_2, NULL, 0);
    printf("parent process: waited for child process with pid: %d\n", pid_2);
    return 0;
}