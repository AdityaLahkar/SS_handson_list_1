/*
============================================================================
Name : 13.c
Author : Aditya Lahkar

Description :  Write a program to wait for a STDIN for 10 seconds using select. 
Write a proper print statement to verify whether the data is available 
within 10 seconds or not (check in $man 2 select)

Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT(if input not given within 10 seconds)
    enter input within 10 seconds: 
    timeout
    
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/select.h>

int main(){
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    struct timeval time;
    time.tv_sec = 10;
    time.tv_usec = 0;

    printf("enter input within 10 seconds: ");
    fflush(stdout);

    int flag = select(1, &rfds, NULL, NULL, &time);

    if(flag == -1){
        perror("error");
        return -1;
    }
    else if(flag == 0){
        printf("\ntimeout\n");
    }
    else{
        char buff[512];
        int n = read(0, buff, 512);
        write(1, buff, n);
    }
    return 0;
}