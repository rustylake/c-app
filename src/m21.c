//文件名：main.c
//作者：peny
//日期：20190330
//
//描述：登录模块
//
//操作
//
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include "m21.h"
#include "m22.h"
#include "model.h"

static char username[256];
static char password[256];


//检验账号密码
int login(int* cmd){
    if(0){}
    return 0;
}


int m21_show_window(int cmd){
    system("CLS");
    printf("012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    printf("\n\n\n\n");
    printf("                                                  商店零售管理系统\n");
    printf("                                                         v 1.0\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("登录账户\n");
    printf("    请输入账号\n");
    fflush(stdin);
    gets(username);
    printf("\n    请输入密码\n");
    fflush(stdin);
    gets(username);
    fflush(stdin);
    cmd=YN(cmd);
    return cmd;
}

int m21_call_back(int cmd){
    if (cmd==0)return 0;
    login(&cmd);
    return 1;
}

int m21(){
    int cmd=1;
    while (1){
        cmd=m21_show_window(cmd);
        cmd=m21_call_back(cmd);
        if (cmd==2){
            //进入系统
        }
        if (cmd==0)break;
    }
    return cmd;
}
