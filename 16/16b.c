/*
============================================================================
Name: 16b.c

Author: Aditya Lahkar

Description:  Write a program to perform mandatory locking.
    
a. Implement read lock

Date: 7th sept, 2025.
============================================================================
*/

/*
    run./a then ./b 
    b will be unable to acquire lock
    
    run b in one shell and run b in another shell both will be able to acquire lock
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(){
    int fd = open("myfile.txt", O_RDONLY | O_CREAT, 0664);
    if(fd < 0){
        perror("file opening\n");
        return -1;
    }
    chmod("myfile.txt", 02664);
    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("trying to acquire lock....\n");
    if(fcntl(fd, F_SETLKW, &lock) < 0){
        perror("lock error\n");
        return 0;
    }
    printf("lock acquired\n");
    char buff[512];
    int n = read(fd, buff, 512);
    write(1, buff, n);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
    printf("lock released\n");
    close(fd);
}