/*
============================================================================
Name: 18a.c

Author: Aditya Lahkar

Description: Write a program to perform Record locking.    

a. Implement write lock    
b. Implement read lock Create three records in a file. Whenever you access a particular 
record, first lock it then modify/access to avoid race condition.


Date: 7th sept, 2025.
============================================================================
*/


/*
    SAMPLE OUTPUT
    enter record no: 3
    acquirig lock....
    lock acquired
    enter new value: 4
    lock released
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
    //open file
    int fd = open("store.txt", O_WRONLY);
    if(fd < 0){
        perror("file open error\n");
        return -1;
    }

    //taking input
    int line;
    printf("enter record no: ");
    scanf("%d", &line);
    line--;

    //acquiring lock
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (line)*2;
    lock.l_len = 2;

    printf("acquirig lock....\n");
    if(fcntl(fd, F_SETLKW, &lock) < 0){
        perror("acquiring lock error\n");
        return -1;
    }
    printf("lock acquired\n");

    //writing new record val
    char val;
    printf("enter new value: ");
    scanf(" %c", &val);
    lseek(fd, (line)*2, SEEK_SET);
    write(fd, &val, 1);
    

    //releasing lock
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    close(fd);
    printf("lock released\n");
    return 0;
}