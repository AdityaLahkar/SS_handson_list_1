/*
============================================================================
Name : 7.c
Author : Aditya Lahkar

Description : Write a program to copy file1 into file2 ($cp file1 file2). 

Date: 7th sept, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
    int fd1, fd2;
    //opened file1.txt
    fd1 = open("file1.txt",  O_RDWR);

    //wrote Hello to file1.txt
    char *msg = "hello";
    write(fd1, msg, 5);

    //opened file2.txt
    fd2 = open("file2.txt", O_APPEND | O_RDWR);

    //read from file1.txt
    char buff[5];
    //set offset to start of file
    lseek(fd1, 0, SEEK_SET);
    read(fd1, buff, 5);

    //wrote to file2.txt;
    write(fd2, buff, 5);
    
    close(fd1);
    close(fd2);
}