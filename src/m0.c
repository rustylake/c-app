//文件名：m0.c
//作者：peny
//日期：20190330
//
//描述：开始模块
//
//操作
//
#include "m0.h"
#include <stdio.h>
#include <stdlib.h>
#include "m1.h"
#include "m2.h"
int m0_window_show(){
    int cmd;
    system("CLS");
    printf("012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    printf("\n\n\n\n");
    printf("                                                  商店零售管理系统\n");
    printf("                                                         v 1.0\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("请输入相应数字：\n");
    printf("    1  帮助页面\n");
    printf("    2  登录系统\n");
    printf("    3  管理系统\n");
    printf("    0  退出\n");
    scanf("%d",&cmd);
    return cmd;
}

int m0_call_back(cmd){
    if (cmd==APP_M0_HELP){
        m1();
    }
    if (cmd==APP_M0_LOGIN){
        m2();
    }

    return cmd;
}

int m0(){
    int cmd;
    while (1) {
        cmd=m0_window_show();
        m0_call_back(cmd);
        if (cmd==APP_M0_EXIT)
            break;
    }
    return 0;

}