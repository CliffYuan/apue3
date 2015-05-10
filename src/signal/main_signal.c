//
// Created by xnd on 15-4-26.
//

#include "main_signal.h"
#include "signal_user.h"
#include "signal_longjmp.h"


void main_signal(){



    signal_alarm();
    exec_user_signal();
}