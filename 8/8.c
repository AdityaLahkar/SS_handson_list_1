/*
============================================================================
Name : 8.c
Author : Aditya Lahkar

Description : Write a program to open a file in read only mode, read line by 
line and display each line as it is read. Close the file when end of file is 
reached.

Date: 7th sept, 2025.
============================================================================
*/

/*  SAMPLE OUTPUT
    hello 
    how are you?
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    //created a file.txt file using shell in the same directory

    int fd = open("file.txt", O_RDONLY);
    if(fd<0){
        perror("open");
        return -1;
    }
    char c;
    while(read(fd,&c, 1) == 1){
        write(1,&c, 1);
    }
    close(fd);
    return 0;
}