/*
============================================================================
Name: 30.c

Author: Aditya Lahkar

Description: Write a program to run a script at a specific time using a Daemon 
process.

Date: 7th sept, 2025.
============================================================================
*/

/*
    to get it to work change the path in line number 42 for srcipt.sh
    and change the path for daemon_log.txt in the script.sh file
    every 30 seconds the daemon process logs into the daemon_log.txt file
*/


#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
    if(daemon(0,0) == -1){
        perror("daemon failed");
        exit(1);
    }

    int daemon_pid = getpid();

    while(1){
        int child_pid = fork();

        if(child_pid == 0){

            char pid_str[50], time_str[50];
            snprintf(pid_str, sizeof(pid_str), "%d", daemon_pid);
            snprintf(time_str, sizeof(time_str), "%ld", time(NULL));

            char *argv[] = {"/home/aditya-lahkar/Desktop/iiitb/Sem1/SS/OS/handsonlist1/30/script.sh", pid_str, time_str, NULL};
            if(execv(argv[0], &argv[0]) == -1){
                perror("execv");
                exit(1);
            }
            exit(0);
        }
        else if(child_pid > 0){
            waitpid(child_pid, NULL, 0);
            sleep(30);
        }
        else{
            perror("fork");
        }
    }
    return 0;
}