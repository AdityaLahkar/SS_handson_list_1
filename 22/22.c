/*
============================================================================
Name: 22.c

Author: Aditya Lahkar

Description: Write a program, open a file, call fork, and then write to the 
file by both the child as well as the parent processes. Check output of the 
file.  

Date: 7th sept, 2025.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(){
    int fd = open("file.txt", O_WRONLY);
    int pid = fork();
    if(pid < 0){
        perror("fork");
        return -1;
    }
    else if(pid == 0){
        write(fd, "by child", 8);
    }
    else{
        write(fd, "by parent", 9);
    }
    close(fd);
    return 0;
}