/*
============================================================================
Name: 27d.c

Author: Aditya Lahkar

Description:  Write a program to execute ls -Rl by the following system calls

d. execv

Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT for ./d27 ls -Rl
    .:
    total 100
    -rw-rw-r-- 1 aditya-lahkar aditya-lahkar   505 Sep  7 23:38 27a.c
    -rw-rw-r-- 1 aditya-lahkar aditya-lahkar   515 Sep  7 23:40 27b.c
    -rw-rw-r-- 1 aditya-lahkar aditya-lahkar   522 Sep  7 23:40 27c.c
    -rw-rw-r-- 1 aditya-lahkar aditya-lahkar   500 Sep  7 23:40 27d.c
    -rw-rw-r-- 1 aditya-lahkar aditya-lahkar   500 Sep  7 23:40 27e.c
    -rwxrwxr-x 1 aditya-lahkar aditya-lahkar 15960 Sep  7 16:12 a27
    -rwxrwxr-x 1 aditya-lahkar aditya-lahkar 15960 Sep  7 16:15 b27
    -rwxrwxr-x 1 aditya-lahkar aditya-lahkar 15960 Sep  7 16:16 c27
    -rwxrwxr-x 1 aditya-lahkar aditya-lahkar 15960 Sep  7 16:19 d27
    -rwxrwxr-x 1 aditya-lahkar aditya-lahkar 15960 Sep  7 16:20 e27
*/
#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    execv("/bin/ls", &argv[1]);
}