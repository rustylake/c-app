//
// Created by pengy on 2019/5/12.
//

#include <stdio.h>
#include <stdlib.h>

#include "4/m41.h"
#include "model/model.h"
#include "model/user.h"

int m41_show_window(char username[]) {
    int cmd = CMD;
    system("CLS");
    printf("当前用户：%s", username);
    printf("\n\n\n\n");
    printf("                                                  商店零售管理系统\n");
    printf("                                                         %s\n", VERSION);
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    users();
    printf("请选择要执行的操作：\n");
    printf("     修改用户信息：1");
    printf("\n     退出：0\n");
    while (!scanf("%d", &cmd))fflush(stdin);
    return cmd;
}

int m41_call_back(int cmd, char username[]) {
    if (cmd == 1) {

    }
    return cmd;
}

int m41(char username[]) {
    int cmd = CMD;
    while (1) {
        cmd = m41_show_window(username);
        m41_call_back(cmd, username);
        if (0 == cmd)break;
    }
    return 0;
}