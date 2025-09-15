/*
============================================================================
Name: 26b.c

Author: Aditya Lahkar

Description: Write a program to execute an executable program.

b. pass some input to an executable program. 
(for example execute an executable of $./a.out name)

Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT for ./26b.out 26a.out
    26a.c  26a.out  26b.c  26b.out
*/


#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    if(execv(argv[1], &argv[1]) == -1){
        perror("exec failed\n");
        return -1;
    }
}