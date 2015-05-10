//
// Created by xnd on 15-5-10.
//

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "start_pthread.h"


void * thread_fn(void * arg){
    printids("new thread:");
    return ((void*)0);
}

void printids(const char *s){
    pid_t pid;
    pthread_t tid;
    pid=getpid();
    tid=pthread_self();
    printf("%s pid %lu tid %lu (0x%lx)\n",s,(
    unsigned long)pid,(
    unsigned long)tid,(
    unsigned long)tid );
}

void start_pthread(){
    int err;
    pthread_t ntid;
    err=pthread_create(&ntid,NULL,thread_fn,NULL);
    if(err!=0){
        printf("can't create thread %d \n",err);
    }

    printids("main thread:");
    sleep(1);
    return ;
}