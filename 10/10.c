/*
============================================================================
Name : 10.c
Author : Aditya Lahkar

Description : Write a program to open a file with read write mode, write 10 
bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.  

a. check the return value of lseek 

b. open the file with od and check the empty spaces in between the data.

Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT 10a
    return value of lseek: 20

    SAMPLE OUTPUT 10b
    run: od -c file.txt
    0000000   a   b   c   d   e   f   g   h   i   j  \0  \0  \0  \0  \0  \0
    0000020  \0  \0  \0  \0   a   b   c   d   e   f   g   h   i   j
    0000036
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fd = open("file.txt", O_CREAT |O_RDWR);
    char buff[10] = "abcdefghij"; //10bytes
    write(fd, buff, 10);
    int val = lseek(fd,10, SEEK_CUR);
    printf("return value of lseek: %d", val);
    write(fd, buff, 10);
    close(fd);
}