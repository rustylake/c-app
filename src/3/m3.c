//
// Created by pengy on 2019/4/14.
//
#include <stdio.h>
#include <stdlib.h>
#include "3/m3.h"
#include "model/model.h"
#include "3/m31.h"

int m3_show_window(char username[]) {
    int cmd = CMD;
    show_head(username);
    printf("请选择要执行的操作：\n");
    printf("     购买商品：1");
    printf("\n     个人资料：2");
    printf("\n     退出：0\n");
    while (!scanf("%d", &cmd))
        fflush(stdin);
    return cmd;
}

int m3_call_back(int cmd, char username[]) {
    if (cmd == M3_BUY) {
        //购买
    }
    if (cmd == M3_MATION) {
        m31(username);
    }
    return cmd;
}

int m3(char username[]) {
    int cmd = CMD;
    while (1) {
        cmd = m3_show_window(username);
        m3_call_back(cmd, username);
        if (0 == cmd)break;
    }
    return 0;
}