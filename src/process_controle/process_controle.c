//
// Created by xnd on 15-4-19.
//

#include <stdio.h>
#include "process_controle.h"
#include "fork.h"
#include "vfork.h"
#include "wait_waitpid.h"
#include "race_condition.h"
#include "exec.h"
#include "times_.h"

void main_process_controle(){

    printf("------------------------process_controle------------------------start\n");

    fork_var();

    vfork_var();

    waitpid_use();

    race_condition();

    exec_main();

    exe_times();

    printf("------------------------process_controle------------------------end\n");
}