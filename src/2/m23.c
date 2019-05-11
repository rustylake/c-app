//
// Created by pengy on 2019/4/27.
//
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "2/m23.h"
#include "model/model.h"
#include "model/user.h"

int m23_call_back(char username[]);

int m23_click_question(User *user, char username[]) {
    int cmd = 0;
    if (!User_scarch(user, username)) {
        printf("\n用户名不存在\n");
    } else {
        printf("%s:\n", user->question);
        printf("请输入答案：");
        char an[128];
        fflush(stdin);
        gets(an);
        cmd = click_password(an, user->an);
    }
    return cmd;
}

int m23_show_window() {
    char username[128];
    system("CLS");
    printf("\n\n\n\n");
    printf("                                                  商店零售管理系统\n");
    printf("                                                         %s\n", VERSION);
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("请输入用户名\n");
    fflush(stdin);
    gets(username);
    fflush(stdin);
    m23_call_back(username) ? printf("修改成功，请重新登录\n按任意键继续") : printf("修改失败\n按任意键继续");
    getch();
    return 0;
}

int m23_call_back(char username[]) {
    int cmd = CMD;
    User user;
    if (m23_click_question(&user, username)) {
        char password[128];
        char password2[128];
        do {
            printf("请输入新密码\n");
            fflush(stdin);
            gets(password);
            printf("请确认密码\n");
            fflush(stdin);
            gets(password2);
        } while (!click_password(password, password2));
        cmd = User_change(username, USER_PASSWORD, password);
    }
    return cmd;
}

int m23() {
    m23_show_window();
    return 0;
}