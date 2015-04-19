cmake_minimum_required(VERSION 3.1)
project(apue3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c")

set(SOURCE_FILES
    src/process/process.c
    src/process/process.h
    src/apue3.c)

add_executable(apue3 ${SOURCE_FILES} src/process/setjmp_longjmp.h src/process/setjmp_longjmp.c src/process/getrlimit_setrlimit.h src/process/getrlimit_setrlimit.c src/process_controle/fork.h src/process_controle/fork.c src/process_controle/process_controle.h src/process_controle/process_controle.c src/process_controle/vfork.h src/process_controle/vfork.c src/process_controle/wait_waitpid.h src/process_controle/wait_waitpid.c)