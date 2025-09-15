/*
============================================================================
Name : 11b.c
Author : Aditya Lahkar

Description : Write a program to open a file, duplicate the file descriptor and 
append the file with both the descriptors and check whether the file is updated 
properly or not. 

b. use dup2 

Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT
    file before any write
    file after write by both fd and f_dup
    written by fd
    written by f_dup2
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fd = open("file1.txt", O_CREAT | O_APPEND | O_RDWR, 0666);
    int f_dup2 = dup2(fd, 100);
    printf("file before any write\n");
    write(fd, "written by fd\n",14);
    write(f_dup2, "written by f_dup2\n",17);
    printf("file after write by both fd and f_dup\n");
    char c;
    lseek(fd,0,SEEK_SET);
    while(read(fd,&c,1)>0)
        write(1,&c,1);
    close(fd);
    close(f_dup2);
}
