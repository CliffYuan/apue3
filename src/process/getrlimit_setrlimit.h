//
// Created by xnd on 15-4-19.
//

#ifndef APUE3_GETRLIMIT_SETRLIMIT_H
#define APUE3_GETRLIMIT_SETRLIMIT_H

#define doit(name) pr_limit(#name,name)

void pr_limit(char *,int);

void getrlimit_setrlimit();

#endif //APUE3_GETRLIMIT_SETRLIMIT_H
