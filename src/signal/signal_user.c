//
// Created by xnd on 15-4-26.
//

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "signal_user.h"


void exec_user_signal(){

    printf("kill current pid=%d\n",getpid());

    if(signal(SIGUSR1,signal_usr)==SIG_ERR){
        printf("can't catch SIGUSR1\n");
    }
    if(signal(SIGUSR2,signal_usr)==SIG_ERR){
        printf("can't catch SIGUSR2\n");
    }


    for(;;){
        pause();
    }

}

void signal_usr(int status){
    if(status==SIGUSR1){
        printf("received SIGUSR1\n");
    } else if(status==SIGUSR2){
        printf("received SIGUSR2\n");
    } else{
        printf("received %d signal\n",status);
    }
}