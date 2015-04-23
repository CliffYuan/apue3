// 竞争条件
// Created by xnd on 15-4-22.
//

#include <utmpx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "race_condition.h"


void charatatime(char * str){

    char * ptr;
    int c;
    setbuf(stdout,NULL);

    for (ptr = str;(c=*ptr++)!=0; ) {
        sleep(1);//使产生竞争条件
        putc(c,stdout);
    }

}
void race_condition(){

    pid_t  pid;

    if((pid=fork())<0){
        printf("race condition fork error");
    }else if(pid==0){
        charatatime("output from children\n");
        exit(0);
    } else{
        charatatime("output from parent\n");
    }

    return ;

}
