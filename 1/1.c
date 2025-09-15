/*
============================================================================
Name : 1.c
Author : Aditya Lahkar
Description : Create the following types of a files using (i) shell command (ii) system call   

a. soft link (symlink system call)

b. hard link (link system call) 

c. FIFO (mkfifo Library Function or mknod system call)

Date: 7th sept, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

void main(){
    //created a file "original.text"
    int fd = open("original.txt", O_CREAT | O_RDWR , 0666);
    if(fd == -1){
        perror("error creating original file");
        return;
    }
    //wrote to "original.txt"
    char c[50] = "written to org file";
    if(write(fd,c,50) == -1){
        perror("error writing to file");
        return;
    }
    close(fd);
    printf("successfully created original.txt file\n");

    //created hardlink file
    if(link("original.txt", "hardlink.txt") != 0){
        perror("error in creating hardlink");
        return;
    }
    printf("hardlink.txt file created successfully\n");

    //created softlink file
    if(symlink("original.txt", "softlink.txt") != 0){
        perror("error in creating softlink");
        return;
    }
    printf("softlink.txt file created successfully\n");

    //created fifo file
    if(mkfifo("myfifo", 0666) != 0){
        perror("error in creating fifo file\n");
        return;
    }
    printf("myfifo file created\n");
}