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
#include "model/list.h"

int YN(char it[]) {
    int cmd = 0;
    int re = 0;
    while (re != 1) {
        printf("%s（Y/N）\n", it);
        char login;
        fflush(stdin);
        login = getchar();
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

int click_username(User user, char username[]) {//User封装后发现好像没什么用
    if (User_scarch(&user, username))
        return 0;
    return 1;
}

int click_password(char password1[], char password2[]) {//也感觉没什么用
    return !strcmp(password1, password2);
}

int regist(User user, char *username, char *password, char *password2) {
    if (click_password(password2, password) == 0) {         //检查两次密码是否一致
        printf("\n两次密码输入不一致，请重新输入");
        return M22_FAILD;
    } else {
        if (click_username(user, username) == 0) {          //检验用户名是否存在
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
    user.point = 0;//初始化积分为0
    User_add(user);//添加用户到数据库
    return 1;
}

int login(char username[], char password[]) {
    int cmd = 0;
    User user;
    if (!User_scarch(&user, username)) {//检验用户名是否存在
        printf("用户名不存在\n按任意键继续");
        getch();
    } else {
        if (!click_password(user.password, password)) {//检查密码是否相同
            printf("密码错误\n按任意键继续");
            getch();
        } else {
            cmd = LOGIN;
        }
    }
    return cmd;//0
}

int users(void) {
    User user;
    FILE *fp = NULL;
    fp = fopen(DB_USER, "rb+");
    if (fp == NULL) {
        printf("\n文件打开失败，请联系管理员");
        return 0;
    }
    printf("        姓名        密码        问题        答案        积分\n");//表头
    while (fread(&user, sizeof(User), 1, fp)) {
        printf("         %s           %s           %s           %s           %d\n",
               user.username,
               user.password,
               user.question,
               user.an,
               user.point);             //打印出所有用户信息
    }
    fclose(fp);
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
    printf("商品代号       名  称        售  价         进  价         数  量         总  价\n");//表头
    while (fread(&good, sizeof(Good), 1, fp)) {
        printf("   %-2d        %-10.10s         %-3d            %-3d            %-3d            %-3d\n",
               good.id,
               good.name,
               good.outprize,
               good.inprize,
               good.count,
               good.total);     //商品信息
    }
    fclose(fp);
    return 1;
}

int show_head(char username[]) {//通用界面
    system("CLS");
    if (strcmp(username, UNLOGIN))
        printf("当前用户：%s", username);        //登录后显示
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
    return 1;
}

int List_goods_show(List list) {
    if (list.count != 0)
        printf("商品代号       名  称        售  价         数  量         总  价\n");
    for (int i = 0; i < list.count; i++) {
        printf("   %-2d            %-6.10s      %-3d             %-3d          %-3d\n",
               list.good[i].id,
               list.good[i].name,
               list.good[i].outprize,
               list.good[i].count,
               list.good[i].total);
    }
    return 1;
}

int lists(void) {
    List list;
    FILE *fp = NULL;
    fp = fopen(DB_LIST, "rb+");
    if (fp == NULL) {
        printf("\n文件打开失败，请联系管理员");
        return 0;
    }
    while (fread(&list, sizeof(List), 1, fp)) {
        printf("\n顾客姓名：%s\n", list.username);
        printf("购买时间：%s\n", list.time);
        printf("购买商品：\n");
        printf("商品代号       名  称        售  价         数  量         总  价\n");
        int totle = 0;
        for (int i = 0; i < list.count; i++) {
            totle += list.good[i].total;
            printf("   %-2d          %-6.10s          %-3d           %-3d           %-3d\n",
                   list.good[i].id,
                   list.good[i].name,
                   list.good[i].outprize,
                   list.good[i].count,
                   list.good[i].total);
        }
        printf("\n                                             合计：%4d元\n", totle);
        printf("                                             优惠：%4d元\n", list.money);
        printf("                                             实付：%4d元\n", totle - list.money);
        printf("--------------------------------------------------------\n");
    }
    fclose(fp);
    return 1;
}