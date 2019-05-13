//
// Created by pengy on 2019/4/2.
//

#include "model/model.h"

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <direct.h>

int YN() {
    int cmd = 0;
    int re = 0;
    while (re != 1) {
        printf("确定要继续吗（Y/N）\n");
        char login;
        login = getchar();
        fflush(stdin);
        if (login == 'Y' || login == 'y') {
            cmd = 1;
            re = 1;
        }
        if (login == 'n' || login == 'N') {
            cmd = 0;
            re = 1;
        }
    }
    return cmd;
}

int click_username(User user, char username[]) {
    if (User_scarch(&user, username))
        return 0;
    return 1;
}

int click_password(char password1[], char password2[]) {
    return !strcmp(password1, password2);
}

int regist(User user, char *username, char *password, char *password2) {
    if (click_password(password2, password) == 0) {
        printf("\n两次密码输入不一致，请重新输入");
        return M22_FAILD;
    } else {
        if (click_username(user, username) == 0) {
            printf("\n用户名已存在");
            return M22_FAILD;
        }
    }
    fflush(stdin);
    printf("\n请填写密保问题\n");
    gets(user.question);
    fflush(stdin);
    printf("请填写问题答案\n");
    gets(user.an);
    User_add(user);
    return 1;
}

int login(char username[], char password[]) {
    int cmd = 0;
    User user;
    if (!User_scarch(&user, username)) {
        printf("用户名不存在\n按任意键继续");
        getch();
    } else {
        if (!click_password(user.password, password)) {
            printf("密码错误\n按任意键继续");
            getch();
        } else {
            cmd = LOGIN;
        }
    }
    return cmd;
}

int users(void) {
    User user;
    FILE *fp = NULL;
    fp = fopen(DB_USER, "rb+");
    if (fp == NULL) {
        printf("\n文件打开失败，请联系管理员");
        return 0;
    }
    printf("    姓名    密码    问题    答案\n");
    while (fread(&user, sizeof(User), 1, fp)) {
        printf("     %s       %s       %s       %s\n", user.username, user.password, user.question, user.an);
    }

    return 1;
}

int goods(void) {
    Good good;
    FILE *fp = NULL;
    fp = fopen(DB_Good, "rb+");
    if (fp == NULL) {
        printf("\n文件打开失败，请联系管理员");
        return 0;
    }
    printf("商品代号     名  称      单  价       售  价       数  量       总  价\n");
    while (fread(&good, sizeof(Good), 1, fp)) {
        printf("   %-2d      %-10.10s       %-3d          %-3d          %-3d          %-3d\n", good.id, good.name,
               good.outprize, good.inprize, good.count, good.total);
        return 1;
    }
}