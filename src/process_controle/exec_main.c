//
// Created by xnd on 15-4-24.
//

#include <stdio.h>
#include <stdlib.h>
#include "exec_main.h"

int main(int arg, char *argv[]){
    int i;
    char ** ptr;
    extern char **environ;

    for (i=0;i<arg;i++){
        printf("---------------exec argv[%d]:%s\n",i,argv[i]);
    }

    for(ptr=environ;*ptr!=0;ptr++){
        printf("---------------%s\n",*ptr);
    }

    exit(0);

}
