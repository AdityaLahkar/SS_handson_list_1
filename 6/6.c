/*
============================================================================
Name : 6.c
Author : Aditya Lahkar

Description : Write a program to take input from STDIN and display on STDOUT. 
Use only read/write system calls

Date: 7th sept, 2025.
============================================================================
*/

/*
    run ./a.out
    hello
    SAMPLE OUTPUT
    hello
*/

#include<stdio.h>
#include<unistd.h>
int main(){
    char buff[5];
    int n = read(0, buff, 5);
    if(n<0){
        return -1;
    }
    write(1, buff, n);
}