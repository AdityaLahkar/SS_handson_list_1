/*
============================================================================
Name : 4.c
Author : Aditya Lahkar

Description : Write a program to open an existing file with read write mode.
Try O_EXCL flag also.

Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT
    file descriptor of the opened file is 3 (for the first run)
    file descriptor of the opened file is -1(after the first run)
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void main(){
    int fd;
    fd = open("./file.txt", O_CREAT | O_EXCL, 0666); 
    printf("file descriptor of the opened file is %d\n", fd);
    close(fd);
}