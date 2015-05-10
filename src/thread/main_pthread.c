//
// Created by xnd on 15-5-10.
//

#include <pthread.h>
#include <stdio.h>
#include "main_pthread.h"
#include "start_pthread.h"
#include "pthread_join.h"
#include "pthread_join_error.h"
#include "pthread_cleanup.h"


void main_pthread(){
    pthread_t pid=pthread_self();
    printf("main pthread process id %d \n",pid);

    start_pthread();

    main_pthread_join();

    main_pthread_join_error();

    main_pthread_cleanup();
}
