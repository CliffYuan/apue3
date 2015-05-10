//
// Created by xnd on 15-5-10.
//

#ifndef APUE3_PTHREAD_CLEANUP_H
#define APUE3_PTHREAD_CLEANUP_H

void cleanup(void * arg);
void * thr_cleanup_fn(void * arg);
void * thr_cleanup_fn2(void * arg);

void main_pthread_cleanup();


#endif //APUE3_PTHREAD_CLEANUP_H
