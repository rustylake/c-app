//文件名：m1.c
//作者：peny
//日期：20190330
//
//描述：帮助页面
//
//操作
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "../header/m1.h"
int m1_window_show(){
  //  clrscr();
    system("CLS");
    printf("012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    printf("\n\n\n\n");
    printf("                                                  商店零售管理系统\n");
    printf("                                                         v 1.0\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("    帮助页面\n");
    printf("    1  。。。。。\n");
    printf("    2  。。。。。\n");
    printf("    1  。。。。。\n");
    printf("    1  。。。。。\n");
    printf("    1  。。。。。\n");
    printf("    1  。。。。。\n");
    printf("    按任意键退出\n");
    getch();
    return 0;
}

int m1_call_back(){
    return 0;
}

int m1(){
    int cmd=0;
    while (1){
        m1_window_show();
        m1_call_back();
        break;
    }
    return 0;
}