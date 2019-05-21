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

#include "4/m4.h"
#include "model/model.h"
#include "4/m40.h"

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
    cmd = YN();
    return cmd;
}

int m40_call_back(int cmd) {
    if (cmd == 0)return 0;
    cmd = login(username, password);
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
