//
// Created by xnd on 15-4-19.
//
#include <stdio.h>
#include <utmpx.h>
#include <unistd.h>
#include "fork.h"

int globval=6;

char buf[]="a write to stdout\n";

void fork_var(){
    int var;
    pid_t pid;

    var=88;

    char * p;
    if((pid=fork())<0){
        printf("fork fail");
    } else if(pid==0){
        globval++;
        var++;
        p="children";
        printf("fork %s,pid=%ld,glob=%d,var=%d \n",p,(long)getpid(),globval,var);
        _exit(0);
    } else{
        sleep(2);
        p="parent";
    }

    printf("fork %s,pid=%ld,glob=%d,var=%d \n",p,(long)getpid(),globval,var);

    return;
}
