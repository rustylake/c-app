//文件名：main.c
//作者：peny
//日期：20190330
//
//描述：登录模块
//
//操作
//

#include "2/m22.h"
#include "3/m3.h"
#include "model/model.h"

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "2/m21.h"


static char username[256];
static char password[256];


int m21_show_window(int cmd) {
    show_head(UNLOGIN);
    printf("登录账户\n");
    printf("    请输入账号\n");
    fflush(stdin);
    gets(username);
    printf("    请输入密码\n");
    fflush(stdin);
    gets(password);
    fflush(stdin);
    cmd = YN("确定要登录吗");
    return cmd;
}

int m21_call_back(int cmd) {
    if (cmd == 0)return 0;
    cmd = login(username, password);
    return cmd;
}

int m21() {
    int cmd = CMD;
    while (1) {
        cmd = m21_show_window(cmd);
        cmd = m21_call_back(cmd);
        if (cmd == M21_LOGIN) {
            m3(username);
            //进入系统
            break;
        }
        if (cmd == M21_EXIT)break;
    }
    return cmd;
}
