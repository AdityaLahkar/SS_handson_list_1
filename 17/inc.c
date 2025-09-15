/*
============================================================================
Name: inc.c

Author: Aditya Lahkar

Description:   Write a program to simulate online ticket reservation.  Implement 
write lock  Write a program to open a file, store a ticket number and exit.  Write 
a separate program, to open the file, implement write lock, read the ticket number,
increment the number and print the new ticket number then close the file.


Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT (run ./b)
    trying to acquire lock....
    lock acquired
    new ticket number: 6
    lock released
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>   
#include<sys/stat.h>

int main(){
    //open file
    int fd = open("store.txt", O_RDWR);
    if(fd < 0){
        perror("file open error\n");
        return -1;
    }
    chmod("store.txt", 02644);

    //acquire lock
    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("trying to acquire lock....\n");
    if(fcntl(fd, F_SETLKW, &lock) < 0){
        perror("lock error\n");
        return -1;
    }
    printf("lock acquired\n");

    //read from file
    int num;
    if(read(fd, &num, sizeof(num)) < 0){
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
        perror("read error\n");
        return -1;
    }
    //inc and write to file
    num += 1;
    lseek(fd, 0, SEEK_SET);
    if(write(fd, &num, sizeof(num)) < 0){
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
        perror("write error\n");
        return -1;
    }
    printf("new ticket number: %d\n", num);
    //release lock and close file
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("lock released\n");
    close(fd);
    return 0;
}