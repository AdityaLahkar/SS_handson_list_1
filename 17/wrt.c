/*
============================================================================
Name: wrt.c

Author: Aditya Lahkar

Description:   Write a program to simulate online ticket reservation.  Implement 
write lock  Write a program to open a file, store a ticket number and exit.  Write 
a separate program, to open the file, implement write lock, read the ticket number,
increment the number and print the new ticket number then close the file.


Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT (run ./a)
    trying to acquire lock....
    lock acquired
    enter ticket number: 5
    lock released
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
    int fd = open("store.txt", O_WRONLY | O_CREAT, 0644);
    if(fd < 0){
        perror("file open error\n");
        return -1;
    }
    chmod("store.txt", 02644);

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("trying to acquire lock....\n");
    if(fcntl(fd, F_SETLKW, &lock) < 0){
        perror("lock error\n");
        return -1;
    }
    printf("lock acquired\n");

    int num;
    printf("enter ticket number: ");
    scanf("%d", &num);
    if(write(fd, &num, sizeof(num)) < -1){
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
        perror("write error\n");
        return -1;
    }

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("lock released\n");
    close(fd);
    return 0;
}
