//
// Created by pengy on 2019/4/14.
//
#include <stdio.h>
#include <stdlib.h>
#include "m3.h"

int m3_show_window(char username[]) {
    int cmd;
    system("CLS");
    printf("012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    printf("当前用户：%s", username);
    printf("\n\n\n\n");
    printf("                                                  商店零售管理系统\n");
    printf("                                                         v 1.0\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("请选择要执行的操作：\n");
    printf("     购买商品：1");
    printf("\n     退出：0\n");
    scanf("%d", &cmd);
    return cmd;
}

int m3_call_back(int cmd) {
    if (cmd == M3_BUY) {
        //
    }
    return cmd;
}

int m3(char username[]) {
    int cmd = 1;
    while (1) {
        cmd = m3_show_window(username);
        m3_call_back(cmd);
        if (0 == cmd)break;
    }
}