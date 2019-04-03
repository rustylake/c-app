//
// Created by pengy on 2019/3/31.
//

#include <stdio.h>
#include <stdlib.h>
#include "m22.h"
#include "model.h"



//*************************************************************
int m22_window_show(int cmd){

    char username[128];
    char password[256];
    char password2[256];
    system("CLS");
    printf("012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    printf("\n\n\n\n");
    printf("                                                  商店零售管理系统\n");
    printf("                                                         v 1.0\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("注册账户\n");
    printf("    请输入账号\n");
    fflush(stdin);
    gets(username);
    fflush(stdin);
    printf("\n    请输入密码\n");
    gets(password);
    fflush(stdin);
    printf("\n    请确认密码\n");
    gets(password2);
    fflush(stdin);
    cmd = YN(cmd);
    return cmd;
}
int m22_call_back(int cmd,char username[],char password[],char password2[]){
    if (cmd == 0)return 0;
    regist(username,password,password2);
    return 0;
}

int m22(){
    int cmd=0;
    while (1){
        cmd=m22_window_show(cmd);
        cmd=m22_call_back(cmd);
        if(cmd==0)break;
    }
    return 0;
}
