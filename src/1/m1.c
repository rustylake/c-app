//文件名：m1.c
//作者：peny
//日期：20190330
//
//描述：帮助页面
//
//接口及作用请参照头文件
//操作
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include "1/m1.h"
#include "model/model.h"

int m1_window_show() {
    show_head(UNLOGIN);
    system("..\\help.png");
    fflush(stdin);
    printf("    按任意键退出\n");
    getch();
    return 0;
}

int m1() {
    m1_window_show();
    return 0;
}
