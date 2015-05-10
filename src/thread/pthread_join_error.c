//
// Created by xnd on 15-5-10.
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "pthread_join_error.h"

void printf_foo(const char* s, const struct foo *ft){
    printf("-------------printf_foo %s\n",s);
    printf("structure at 0x%lx\n",(
    unsigned long) ft);

    printf("foo.a=%d\n",ft->a);
    printf("foo.b=%d\n",ft->b);
    printf("foo.c=%d\n",ft->c);
    printf("foo.d=%d\n",ft->d);
}
void * thr_error_fn(void * arg){
    struct foo foo1={1,2,3,4};

    printf_foo("thread 1:",&foo1);
    pthread_exit((void *)&foo1);
}
void * thr_error_fn2(void * arg){
    printf("thread 2 :ID is %lu\n",(
    unsigned long)pthread_self());
    pthread_exit((void *)0);
}

void main_pthread_join_error(){
    int err;
    pthread_t tid1,tid2;

    struct foo *ft;

    err=pthread_create(&tid1,NULL,thr_error_fn,NULL);
    if(err!=0){
        printf("crate thread 1 fail\n");
        return;
    }

    err=pthread_join(tid1,&ft);
    if(err!=0){
        printf("pthread_join thread 1 fail\n");
        return;
    }

    sleep(1);
    printf("parent starting second thread\n");


    err=pthread_create(&tid2,NULL,thr_error_fn2,NULL);
    if(err!=0){
        printf("crate thread 2 fail\n");
        return;
    }

    sleep(1);
    printf_foo("parent:",ft);
    return;
}