/*
 ============================================================================
 Name        : apue3.c
 Author      : xnd
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "process/process.h"
#include "process_controle/process_controle.h"

int main(int argc, char *argv[]) {
	//命令行参数
	int i = 0;
	for (i = 0; i < argc; i++) {
		printf("命令行参数argv[%d]:%s\n", i, argv[i]);
	}

    main_process_controle();

    main_process();

	return EXIT_SUCCESS;
}
