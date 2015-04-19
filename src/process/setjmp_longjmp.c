// 存放在存储器上的变量将具有longjmp时呈现的值
// 而在cpu和浮点寄存器中的变量则恢复为调用setjmp时的值。
// 编写一个使用非局部跳转的可移植程序，则必须使用volatile属性。
// Created by xnd on 15-4-19.
//
#include <setjmp.h>
#include <stdio.h>
#include "setjmp_longjmp.h"

static jmp_buf jmpbuffer;
static int globval;

void setjmp_longjmp(){
    int autoval;
    register int regival;
    volatile int volaval;
    static int statval;

    globval=1;
    autoval=2;
    regival=3;
    volaval=4;
    statval=5;

    if(setjmp(jmpbuffer)!=0){
        //跳转返回后执行
        printf("after longjmp:\n");
        printf("globval=%d,autoval=%d,regival=%d, volaval=%d, statval=%d \n",globval,autoval,regival,volaval,statval);
        return;
    }

    globval=95;
    autoval=96;
    regival=97;
    volaval=98;
    statval=99;

    f1(autoval,regival,volaval,statval);
    return;
}
void f1(int i,int j ,int k,int l){
    printf("in f1 funtion:\n");
    printf("globval=%d,autoval=%d,regival=%d, volaval=%d, statval=%d \n",globval,i,j,k,l);
    f2();
}
void f2(void){
    longjmp(jmpbuffer,5);
}


