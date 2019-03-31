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
static char admin[256];
static char password[256];

int m21_YN(int* cmd){
    printf("确定要登录吗（Y/N）\n");
    char login;
    int re=0;
    login=getchar();
    fflush(stdin);
    if(login=='Y'||login=='y'){*cmd=1;re=1;}
    if(login=='n'||login=='N'){*cmd=0;re=1;}
    return re;
}
//检验账号密码
int login(int* cmd){
    if(0){}
    return 0;
}


int m21_show_window(){
    system("CLS");
    printf("012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    printf("\n\n\n\n");
    printf("                                                  商店零售管理系统\n");
    printf("                                                         v 1.0\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("登录账户\n");
    printf("    请输入账号\n");
    scanf("%s",&admin[0]);
    fflush(stdin);
    printf("\n    请输入密码\n");
    scanf("%s",&password[0]);
    fflush(stdin);
    int cmd=0,re=0;
    while(re!=1){re=m21_YN(&cmd);}
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
        cmd=m21_show_window();
        cmd=m21_call_back(cmd);
        if (cmd==2){
            //进入系统
        }
        if (cmd==0)break;
    }
    return cmd;
}
