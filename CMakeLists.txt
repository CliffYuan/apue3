cmake_minimum_required(VERSION 3.1)
project(apue3)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c")

set(SOURCE_FILES
    src/process/process.c
    src/process/process.h
    src/apue3.c)

add_executable(apue3 ${SOURCE_FILES} src/process/setjmp_longjmp.h src/process/setjmp_longjmp.c src/process/getrlimit_setrlimit.h src/process/getrlimit_setrlimit.c src/process_controle/fork.h src/process_controle/fork.c src/process_controle/process_controle.h src/process_controle/process_controle.c src/process_controle/vfork.h src/process_controle/vfork.c src/process_controle/wait_waitpid.h src/process_controle/wait_waitpid.c src/process_controle/race_condition.h src/process_controle/race_condition.c src/process_controle/exec.h src/process_controle/exec.c src/process_controle/times_.h src/process_controle/times_.c src/signal/signal_user.h src/signal/signal_user.c src/signal/main_signal.h src/signal/main_signal.c src/signal/signal_longjmp.h src/signal/signal_longjmp.c src/thread/main_pthread.h src/thread/main_pthread.c src/thread/start_pthread.h src/thread/start_pthread.c src/thread/pthread_join.h src/thread/pthread_join.c src/thread/pthread_join_error.h src/thread/pthread_join_error.c src/thread/pthread_cleanup.h src/thread/pthread_cleanup.c)

TARGET_LINK_LIBRARIES(apue3 pthread)