/*
============================================================================
Name : 3.c
Author : Aditya Lahkar

Description : Write a program to create a file and print the file descriptor 
value. Use creat ( ) system call 

Date: 7th sept, 2025.
============================================================================
*/

/*  SAMPLE OUTPUT
    the file descrriptor value of myfile.txt is 3
*/

#include<stdio.h>
#include<fcntl.h>

void main(){
    int fd = creat("./myfile.txt", 0666);
    printf("the file descrriptor value of myfile.txt is %d", fd);
    close(fd);
}