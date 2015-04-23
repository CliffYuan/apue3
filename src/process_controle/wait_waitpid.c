//
// Created by xnd on 15-4-19.
//

#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "wait_waitpid.h"


void pre_exit(int status){
    //if(WIFEXITED(status))
        printf("normal termination,");

}

void waitpid_use(){
    pid_t pid;
    if((pid=fork())<0){
        printf("fork error");
    } else if(pid==0){
        //first children
        if((pid=fork())<0){
            printf("chindren fork error");
        } else if(pid>0){
            //parent
            exit(0);
        }

        //second children
        sleep(2);
        printf("second child ,parent pid=%ld\n",pid);
        exit(0);

    }

    if(waitpid(pid,NULL,0)!=pid){
        printf("waitpid error");
    }

    return ;
}