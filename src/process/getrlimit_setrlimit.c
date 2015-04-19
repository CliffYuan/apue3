//
// Created by xnd on 15-4-19.
//
#include <sys/resource.h>
#include <stdio.h>
#include "getrlimit_setrlimit.h"


void getrlimit_setrlimit(){
    doit(RLIMIT_DATA);
    doit(RLIMIT_NOFILE);
    doit(RLIMIT_NPROC);
    doit(RLIMIT_STACK);
    doit(RLIMIT_CPU);
}


void pr_limit(char * name,int resource){

    struct rlimit limit;

    unsigned long long lim;
    if(getrlimit(resource,&limit)<0){
        printf("getrlimit %s fail \n",name);
    }

    printf("%-14s ",name);

    if(limit.rlim_cur==RLIM_INFINITY){
        printf("(infinite) ");
    } else{
        lim=limit.rlim_cur;
        printf("%10lld ",lim);
    }


    if(limit.rlim_max==RLIM_INFINITY){
        printf("(infinite) ");
    } else{
        lim=limit.rlim_max;
        printf("%10lld ",lim);
    }
    putchar((int)'\n');
}