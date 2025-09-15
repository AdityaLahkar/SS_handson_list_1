/*
============================================================================
Name : 14.c
Author : Aditya Lahkar

Description :  Write a program to find the type of a file.

a. Input should be taken from command line.  

b. program should be able to identify any type of a file. 

Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT for ./a.out myfifo
    fifo file

    SAMPLE OUTPUT for ./a.out file.txt
    regular file
*/


#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    
    struct stat st;
    if(stat(argv[1], &st) == -1) {
        perror("stat error"); 
        return -1;
    }
    if ((st.st_mode & __S_IFMT) == __S_IFREG ) {
        printf("regular file\n");
    }
    else if ((st.st_mode & __S_IFMT) == __S_IFSOCK){
        printf("socket file\n");
    }
    else if ((st.st_mode & __S_IFMT) == __S_IFLNK){
        printf("symbolic link file\n");
    }
    else if ((st.st_mode & __S_IFMT) == __S_IFDIR){
        printf("directory file\n");
    }
    else if ((st.st_mode & __S_IFMT) == __S_IFCHR){
        printf("character device file\n");
    }
    else if ((st.st_mode & __S_IFMT) == __S_IFIFO){
        printf("fifo file\n");
    }
    return 0;
}