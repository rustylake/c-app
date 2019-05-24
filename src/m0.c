//文件名：m0.c
//作者：peny
//日期：20190330
//
//描述：开始模块
//
//操作
//

#include <stdio.h>
#include <stdlib.h>

#include "1/m1.h"
#include "2/m2.h"
#include "3/m32.h"
#include "4/m4.h"
#include "model/model.h"
#include "test.h"
#include "m0.h"


int m0_window_show() {
    int cmd = CMD;
    show_head(UNLOGIN);
    printf("请输入相应数字：\n");
    printf("    1  帮助页面\n");
    printf("    2  登录系统\n");
    printf("    3  管理系统\n");
    printf("    4  游客购买\n");
    printf("    0  退出\n");
    while (!scanf("%d", &cmd))fflush(stdin);
    return cmd;
}

int m0_call_back(int cmd) {
    if (cmd == APP_M0_HELP) {//帮助
        m1();
    }
    if (cmd == APP_M0_LOGIN) {//登录
        m2();
    }
    if (cmd == APP_M0_ADMIN) {//登录
        m40();
    }
    if (cmd == APP_M0_BUY) {//测试
        m32("游客");
    }
    if (cmd == APP_M0_TEST) {//测试
        test();
    }
    return cmd;
}

int m0() {
    int cmd = CMD;
    while (1) {
        cmd = m0_window_show();
        m0_call_back(cmd);
        if (cmd == APP_M0_EXIT)
            break;
    }
    return 0;

}