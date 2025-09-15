/*
============================================================================
Name : 5.c
Author : Aditya Lahkar

Description :  Write a program to create five new files with infinite loop. 
Execute the program in the background and check the file descriptor table at 
/proc/pid/fd.

Date: 7th sept, 2025.
============================================================================
*/

/*
    run ./a.out & 
    copy the pid and type the path ls /proc/<pid>/fd
    SAMPLE OUTPUT
    0  1  103  2  3  4  40  41  42  5  6  7
*/

#include<stdio.h>
#include<fcntl.h>

void main(){
    for(int i = 0; i<5; i++){
        char file_name[10];
        snprintf(file_name, 10, "%d.txt",i);
        if(open(file_name,O_CREAT, 0666) != -1){
            printf("%d.txt created successsfully\n", i);
        }
    }
    while(1);
}