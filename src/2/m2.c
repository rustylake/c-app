//文件名：main.c
//作者：peny
//日期：20190330
//
//描述：登录系统模块
//
//操作
//
#include "2/m23.h"
#include "2/m2.h"
#include "2/m21.h"
#include "2/m22.h"
#include "3/m3.h"
#include "model/model.h"

#include <stdlib.h>
#include <stdio.h>

int m2_show_window(int cmd) {
    show_head(UNLOGIN);
    printf("登录系统：\n");
    printf("    1  登录\n");
    printf("    2  用户注册\n");
    printf("    3. 忘记密码\n");
    printf("    0  返回\n");
    while (!scanf("%d", &cmd))fflush(stdin);
    return cmd;
}

int m2_call_back(int cmd) {
    switch (cmd) {
        case APP_M2_EXIT://返回主界面
            break;
        case APP_M2_LOGIN://登录
            m21();
            break;
        case APP_M2_REGIST://注册
            m22();
            break;
        case APP_M2_FORGITE://忘记密码
            m23();
            break;
        default:
            break;

    }
    return cmd;
}


int m2() {
    int cmd = CMD;
    while (1) {
        cmd = m2_show_window(cmd);
        cmd = m2_call_back(cmd);
        if (cmd == 0)break;
    }
    return cmd;
}