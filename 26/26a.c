/*
============================================================================
Name: 26a.c

Author: Aditya Lahkar

Description: Write a program to execute an executable program.

a. use some executable program

Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT
    26a.c  26a.out  26b.c  26b.out
*/

#include<stdio.h>
#include<unistd.h>

int main(){
    if(execlp("ls", "-l", NULL) == -1){
        perror("exec failed\n");
        return -1;
    }
}