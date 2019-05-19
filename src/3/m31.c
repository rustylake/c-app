//
// Created by pengy on 2019/5/12.
//

#include <stdio.h>
#include <stdlib.h>
#include "3/m31.h"
#include "model/model.h"
#include "model/user.h"

int m31_show_window(User user) {
    int cmd = CMD;
    show_head(user.username);
    printf("个人资料：\n");
    printf("     姓名：%s", user.username);
    printf("\n     密保问题：%s", user.question);
    printf("\n     问题答案：%s\n", user.an);
    printf("     修改问题：1");
    printf("\n     修改答案：2");
    printf(" \n    返回：0\n");
    while (!scanf("%d", &cmd))fflush(stdin);
    return cmd;
}

int m31_call_back(int cmd) {
    if (cmd == APP_M31_ANSWER) {
        //
    }
    if (cmd == APP_M31_QUESTION) {
        //
    }
    return cmd;
}

int m31(char username[]) {
    int cmd = CMD;
    User user;
    User_scarch(&user, username);
    while (1) {
        cmd = m31_show_window(user);
        m31_call_back(cmd);
        if (APP_M31_EXIT == cmd)break;
    }
    return 0;
}