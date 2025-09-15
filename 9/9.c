/*
============================================================================
Name : 9.c
Author : Aditya Lahkar

Description :  Write a program to print the following information about a given file.    
a. inode    
b. number of hard links    
c. uid    
d. gid    
e. size    
f. block size    
g. number of blocks    
h. time of last access    
i. time of last modification    
j. time of last change

Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT
    stats for file.txt
    inode no: 10238015
    number of hard links: 1
    uid no 1000
    gid no: 1000
    size: 0
    block size: 4096
    number of blocks: 0
    atime: Sun Sep  7 18:40:27 2025
    mtime: Sun Aug 31 19:47:24 2025
    ctime: Sun Aug 31 19:47:24 2025
*/

#include<stdio.h>
#include<sys/stat.h>
#include<time.h>

int main(){
    struct stat s;
    char *path = "file.txt";
    stat(path, &s);
    printf("stats for %s\n", path);
    printf("inode no: %lu\n", s.st_ino);
    printf("number of hard links: %lu\n", s.st_nlink);
    printf("uid no %u\n", s.st_uid);
    printf("gid no: %u\n", s.st_gid);
    printf("size: %lld\n", s.st_size);
    printf("block size: %lld\n", s.st_blksize);
    printf("number of blocks: %lld\n", s.st_blocks);
    printf("atime: %s", ctime(&s.st_atime));
    printf("mtime: %s", ctime(&s.st_mtime));
    printf("ctime: %s", ctime(&s.st_ctime));
    return 0;
}