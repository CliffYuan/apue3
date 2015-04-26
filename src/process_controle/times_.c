//
// Created by xnd on 15-4-26.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sys/times.h"


void do_cmd(char * cmd){
    struct tms tmsstart,tmsend;
    clock_t  start,end;
    int status;

    printf("\n command: s% \n",cmd);

    if((start=times(&tmsstart))==-1){
        printf("times error");
    }

    if((status=system(cmd))<0){
        printf("system() error");
    }

    if((end=times(&tmsend))==-1){
        printf("times error");
    }

    pre_times_(end-start,&tmsstart,&tmsend);
}


void pre_times_(clock_t real,struct tms * tmsstart, struct tms * tmsend){
    static long clktck=0;

    if(clktck==0){
        if((clktck=sysconf(_SC_CLK_TCK))<0){
            printf("sysconf() error");
        }
    }


    printf(" real: %7.2f\n",real/(double)clktck);
    printf(" user: %7.2f\n",(tmsend->tms_utime-tmsstart->tms_utime)/(double)clktck);
    printf(" sys: %7.2f\n",(tmsend->tms_stime-tmsstart->tms_stime)/(double)clktck);
    printf(" child user: %7.2f\n",(tmsend->tms_cutime-tmsstart->tms_cutime)/(double)clktck);
    printf(" child sys: %7.2f\n",(tmsend->tms_cstime-tmsstart->tms_cstime)/(double)clktck);
}

void exe_times(){
    do_cmd("sleep 5");
    do_cmd("date");
    do_cmd("man bash >/dev/null");
}