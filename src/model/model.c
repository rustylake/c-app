//
// Created by pengy on 2019/4/2.
//
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <direct.h>

#include "2/m22.h"
#include "model/user.h"
#include "model/goods.h"
#include "model/model.h"

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
    }
    fclose(fp);
    return 1;
}

int show_head(char username[]) {
    system("CLS");
    if (strcmp(username, UNLOGIN))
        printf("当前用户：%s", username);
    printf("\n\n\n\n");
    printf("                                         商店零售管理系统\n");
    printf("                                                %s\n", VERSION);
    printf("--------------------------------------------------------------------------------------------------\n");
    return 0;
}

int get_current_time(char times[]) {
    time_t now;
    struct tm *tm_now;
    time(&now);
    tm_now = localtime(&now);
    sprintf(times, "%04d-%02d-%02d %02d:%02d:%02d", tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday,
            tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec);
//    printf("%s",times);
    return 1;
}