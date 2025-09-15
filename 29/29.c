/*
============================================================================
Name: 29.c

Author: Aditya Lahkar

Description:  Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,  
SCHED_RR).

Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT for sudo ./a.out
    current scheduling policy is : SCHED_OTHER
    enter 0 for sched other, 1 for sched fifo, 2 for sched rr
    2
    current scheduling policy is : SCHED_RR
*/

#include<stdio.h>
#include<unistd.h>
#include<sched.h>

void get_sched(){
    int policy = sched_getscheduler(0);
    if(policy == 0){
        printf("current scheduling policy is : SCHED_OTHER\n");
    }
    else if(policy == 1){
        printf("current scheduling policy is : SCHED_FIFO\n");
    }
    else{
        printf("current scheduling policy is : SCHED_RR\n");
    }
}

int main(){
    get_sched(); 
    int choice;
    printf("enter 0 for sched other, 1 for sched fifo, 2 for sched rr\n");
    scanf("%d", &choice);
    
    struct sched_param param;
    if(choice == 1 || choice == 2){
        param.sched_priority = 1;
    }
    sched_setscheduler(0,choice, &param);
    get_sched();
}