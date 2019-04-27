//
// Created by pengy on 2019/4/27.
//
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "m23.h"
#include "model.h"
#include "user.h"

int m23_call_back(char username[]);

int m23_click_quetion(User user, char username[]) {
    int cmd = 0;
    if (!User_view(&user, username)) {
        printf("\n用户名不存在\n");
    } else {
        printf("%s:\n", user.question);
        printf("请输入答案：");
        char an[128];
        fflush(stdin);
        gets(an);
        cmd = click_password(an, user.an);
    }
    return cmd;
}

int m23_show_window() {
    char username[128];
    system("CLS");
    printf("012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    printf("\n\n\n\n");
    printf("                                                  商店零售管理系统\n");
    printf("                                                         v 1.1\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("请输入用户名");
    fflush(stdin);
    gets(username);
    fflush(stdin);
    m23_call_back(username) ? printf("修改成功，请重新登录\n按任意键继续") : printf("修改失败\n按任意键继续");
    getch();
    return 0;
}

int m23_call_back(char username[]) {
    int cmd = 0;
    User user;
    if (m23_click_quetion(user, username)) {
        char password[128];
        char password2[128];
        do {
            fflush(stdin);
            printf("请输入新密码\n");
            gets(password);
            fflush(stdin);
            printf("请确认密码\n");
            gets(password2);
        } while (!click_password(password, password2));
        User_change(username, USER_PASSWORD, user.password);
        cmd = 1;
    }
    return cmd;
}

int m23() {
    m23_show_window();
    return 0;
}