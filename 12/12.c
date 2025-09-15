/*
============================================================================
Name : 12.c
Author : Aditya Lahkar

Description : 12. Write a program to find out the opening mode of a file. 
Use fcntl.

Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT
    read write mode
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
    int fd;
    //create a file
    fd = creat("myfile.txt", 0644);
    close(fd);
    // open file
    fd = open("myfile.txt", O_RDWR);
    int flag = fcntl(fd, F_GETFL);
    close(fd);
    //decode and print
    if((flag & 3) == 0) printf("read only mode\n");
    if((flag & 3) == 1) printf("write only mode\n");
    if((flag & 3) == 2) printf("read write mode\n");
    return 0;
}