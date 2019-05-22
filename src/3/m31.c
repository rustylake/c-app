//
// Created by pengy on 2019/5/12.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "model/model.h"
#include "model/user.h"
#include "3/m31.h"

int m31_show_window(User user) {
    int cmd = CMD;
    show_head(user.username);
    printf("个人资料：\n");
    printf("     姓名：%s", user.username);
    printf("\n     密保问题：%s", user.question);
    printf("\n     问题答案：%s\n", user.an);
    printf("\n修改问题：1");
    printf("\n修改答案：2");
    printf("\n返回：0\n");
    while (!scanf("%d", &cmd))fflush(stdin);
    return cmd;
}

int m31_call_back(int cmd, User user) {
    if (cmd == APP_M31_QUESTION) {
        printf("请输入新的密保问题：\n");
        char question[128];
        fflush(stdin);
        gets(question);
        if (YN()) {
            User_change(user.username, USER_QUESTION, question);
            printf("\n修改成功");
            printf("\n按任意键继续\n");
            getch();
        }
    }
    if (cmd == APP_M31_ANSWER) {
        printf("请输入新的问题答案：\n");
        char question[128];
        fflush(stdin);
        gets(question);
        if (YN()) {
            User_change(user.username, USER_AN, question);
            printf("\n修改成功");
            printf("\n按任意键继续\n");
            getch();
        }
    }
    return cmd;
}

int m31(char username[]) {
    int cmd = CMD;
    User user;
    while (1) {
        User_scarch(&user, username);
        cmd = m31_show_window(user);
        m31_call_back(cmd, user);
        if (APP_M31_EXIT == cmd)break;
    }
    return 0;
}