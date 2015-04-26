//
// Created by xnd on 15-4-22.
//

#include <utmpx.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "exec.h"


void exec_main(){
    char * env_init[]={"USER=unknown","PATH=/tmp",NULL};

    pid_t pid;

    if((pid=fork())<0){
        printf("fork fail\n");
    } else if(pid==0){
        //children
        if(execle("/home/xnd/workspace/apue3/src/process_controle/echoall","echoall","myarg1","MY ARG2",(char*)0,env_init)<0){
            printf("execle error\n");
        }
    }

    if(waitpid(pid,NULL,0)<0){
        printf("waitpid error\n");
    }

    if((pid=fork())<0){
        printf("fork error\n");
    } else if(pid==0){
        if(execlp("/home/xnd/workspace/apue3/src/process_controle/echoall","echoall","only 1 arg",(char*)0)<0){
            printf("execlp error\n");
        }
    }

}