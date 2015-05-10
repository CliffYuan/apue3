//
// Created by xnd on 15-5-10.
//

#include <stdio.h>
#include <pthread.h>
#include "pthread_cleanup.h"


void cleanup(void * arg){
    printf("cleanup:%s\n",(
    char *)arg);

}
void * thr_cleanup_fn(void * arg){
    printf("thread 1 start\n");
    pthread_cleanup_push(cleanup,"thread 1 first handler");
    pthread_cleanup_push(cleanup,"thread 1 second handler");
    printf("thread 1 push complete\n");
    if(arg){
        return ((void *)1);
    }
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    return ((void *)1);
}

void * thr_cleanup_fn2(void * arg){
    printf("thread 2 start\n");
    pthread_cleanup_push(cleanup,"thread 2 first handler");
    pthread_cleanup_push(cleanup,"thread 2 second handler");
    printf("thread 2 push complete\n");

    if(arg){
                pthread_exit((
                void *)2);
            }
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    pthread_exit((
                         void *)2);
}

void main_pthread_cleanup(){

    printf("-------pthread_cleanup-----------\n");
    int err;
    pthread_t tid1,tid2;

    void *test;

    err=pthread_create(&tid1,NULL,thr_cleanup_fn,(void *)1);
    if(err!=0){
        printf("crate thread 1 fail\n");
        return;
    }

    err=pthread_create(&tid2,NULL,thr_cleanup_fn2,(void *)1);
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
