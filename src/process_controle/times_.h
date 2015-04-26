//
// Created by xnd on 15-4-26.
//

#ifndef APUE3_TIMES_H
#define APUE3_TIMES_H


#include <time.h>

void do_cmd(char *);

void pre_times_(clock_t,struct tms *, struct tms *);

void exe_times();

#endif //APUE3_TIMES_H
