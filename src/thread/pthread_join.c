//
// Created by xnd on 15-5-10.
//

#include <stdio.h>
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include "pthread_join.h"


void * thr_fn(void * arg){
    printf("thread1 exit\n");
    return ((void *)1);
}

void * thr_fn2(void * arg){
    printf("thread2 exit\n");
    return ((void *)2);
}

void main_pthread_join(){
    int err;
    pthread_t tid1,tid2;

    void *test;

    err=pthread_create(&tid1,NULL,thr_fn,NULL);
    if(err!=0){
        printf("crate thread 1 fail\n");
        return;
    }

    err=pthread_create(&tid2,NULL,thr_fn2,NULL);
    if(err!=0){
        printf("crate thread 2 fail\n");
        return;
    }

    err=pthread_join(tid1,&test);
    if(err!=0){
        printf("pthread_join thread 1 fail\n");
        return;
    }

    printf("pthread_join thread 1 exit code %ld\n",(long)test);

    err=pthread_join(tid2,&test);
    if(err!=0){
        printf("pthread_join thread 2 fail\n");
        return;
    }
    printf("pthread_join thread 2 exit code %ld\n",(long)test);
    return;
}
