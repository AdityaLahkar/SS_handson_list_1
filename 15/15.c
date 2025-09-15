/*
============================================================================
Name: 15.c

Author: Aditya Lahkar

Description: Write a program to display the environmental variable of the 
user (use environ).

Date: 7th sept, 2025.
============================================================================
*/

/*
    SAMPLE OUTPUT
    SHELL=/bin/bash
    SESSION_MANAGER=local/asus-tuf-a15:@/tmp/.ICE-unix/3546,unix/asus-tuf-a15:/tmp/.ICE-unix/3546
    QT_ACCESSIBILITY=1
    COLORTERM=truecolor
    XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
    NVM_INC=/home/aditya-lahkar/.nvm/versions/node/v22.17.0/include/node
    XDG_MENU_PREFIX=gnome-
    TERM_PROGRAM_VERSION=1.102.1
    GNOME_DESKTOP_SESSION_ID=this-is-deprecated
    CONDA_EXE=/home/aditya-lahkar/miniconda3/bin/conda
    _CE_M=
    GNOME_SHELL_SESSION_MODE=ubuntu
    SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
    .
    .
    .
    .
    .
*/

#include<stdio.h>

int main(){
    extern char **environ;
    int i = 0;
    while(environ[i]){
        printf("%s\n", environ[i]);
        i++;
    }
    return 0;
}