//
// Created by xnd on 15-5-1.
//

#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "signal_longjmp.h"

jmp_buf signal_env_alrm;

void sig_alrm(int signo){
    longjmp(signal_env_alrm,1);
}

void signal_alarm(){
    int n;
    char line[1024];

    if(signal(SIGALRM,sig_alrm)==SIG_ERR){
        printf("signal(SIGALRM) error\n");
    }

    if(setjmp(signal_env_alrm)!=0){
        printf("read timeout,exit\n");
        return;
    }

    printf("alarm start\n");
    alarm(10);
    if((n=read(STDIN_FILENO,line,1024))<0){
        printf("read error\n");
    }
    alarm(0);

    write(STDOUT_FILENO,line,n);

    return;
}