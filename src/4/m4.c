//
// Created by pengy on 2019/5/12.
//


//文件名：main.c
//作者：peny
//日期：20190330
//
//描述：登录模块
//
//操作
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "4/m40.h"
#include "model/model.h"
#include "4/m4.h"

static char username[256];
static char password[256];


int m40_show_window(int cmd) {
    show_head(UNLOGIN);
    printf("登录账户\n");
    printf("    请输入账号\n");
    fflush(stdin);
    gets(username);
    printf("    请输入密码\n");
    fflush(stdin);
    gets(password);
    fflush(stdin);
    cmd = YN("确定要登陆吗");
    return cmd;
}

int m40_call_back(int cmd) {
    if (cmd == 1) {
        if ((!abs(strcmp(username, ADMIN)) && !abs(strcmp(password, PASSWORD)))) {
            cmd = LOGIN;
        } else {
            cmd = 0;
            printf("用户名或密码错误\n");
            fflush(stdin);
            printf("按任意键继续");
            getch();
        }
    }
    return cmd;
}

int m40() {
    int cmd = CMD;
    while (1) {
        cmd = m40_show_window(cmd);
        cmd = m40_call_back(cmd);
        if (cmd == LOGIN) {
            m4(username);
            //进入系统
            break;
        }
        if (cmd == APP_M40_EXIT)
            break;
    }
    return cmd;
}
