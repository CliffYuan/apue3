/*
 * process.c
 *
 *  Created on: 2015年4月18日
 *      Author: xnd
 */
#include<stdlib.h>
#include<stdio.h>
#include "process.h"
#include "setjmp_longjmp.h"
#include "getrlimit_setrlimit.h"

//环境表
extern char **environ;

void main_process() {
	//终止处理函数 exit hook
	atexit_();
	//设置获取显示环境
	get_set_environ();

	setjmp_longjmp();

	getrlimit_setrlimit();

	//退出函数
	exit_();

}
//------------------
void exit_() {
	exit(1);
}
//------------------
void atexit_() {
	if (atexit(my_exit1_hook) == 0) {
		printf("add my_exit1_hook hook success\n");
	} else {
		printf("add my_exit1_hook hook fail\n");
	}

	if (atexit(my_exit2_hook) == 0) {
		printf("add my_exit2_hook hook success\n");
	} else {
		printf("add my_exit2_hook hook fail\n");
	}
}
void my_exit1_hook() {
	printf("invoke my_exit1_hook\n");
}
void my_exit2_hook() {
	printf("invoke my_exit2_hook\n");
}
//---------------------
void get_set_environ() {
	//设置和获取环境变量
	putenv("MX4=MEIZU 4 PHONE");
	printf("getenv(MX4)=%s\n",getenv("MX4"));

	setenv("MX4PRO","MEIZU 4 PRO PHONE",0);
	printf("getenv(MX4PRO)=%s\n",getenv("MX4PRO"));

	unsetenv("MX4PRO");
	printf("getenv(MX4PRO)=%s\n",getenv("MX4PRO"));

	//遍历 todo 这样写错误了
//	for (; environ != NULL; environ++) {
//		printf("environ:%s\n", *environ);
//	}
}
