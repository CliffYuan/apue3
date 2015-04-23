//
// Created by xnd on 15-4-19.
//

#include "process_controle.h"
#include "fork.h"
#include "vfork.h"
#include "wait_waitpid.h"
#include "race_condition.h"

void main_process_controle(){

    fork_var();

    vfork_var();

    waitpid_use();

    race_condition();
}