//
// Created by xnd on 15-4-19.
//

#include <unistd.h>
#include <stdio.h>
#include "vfork.h"

int globval_v=6;

void vfork_var(){

    int var;

    pid_t pid;

    var=88;

    printf("before vfork\n");
    char * p;
    if((pid=vfork())<0){
        printf("vfork fail");
    } else if(pid==0){
        globval_v++;
        var++;
        p="children";
        printf("vfork %s,pid=%ld,glob=%d,var=%d \n",p,(long)getpid(),globval_v,var);
        _exit(0);
    } else{
        p="parent";
    }

    printf("vfork %s,pid=%ld,glob=%d,var=%d \n",p,(long)getpid(),globval_v,var);

    return;
}



