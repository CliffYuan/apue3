//
// Created by xnd on 15-5-10.
//

#ifndef APUE3_PTHREAD_JOIN_ERROR_H
#define APUE3_PTHREAD_JOIN_ERROR_H

struct foo{
    int a,b,c,d;
};

void * thr_error_fn(void * arg);
void * thr_error_fn2(void * arg);
void printf_foo(const char* s, const struct foo *ft);
void main_pthread_join_error();
#endif //APUE3_PTHREAD_JOIN_ERROR_H
