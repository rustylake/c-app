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
        printf("ȷ��Ҫ������Y/N��\n");
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
        printf("\n�����������벻һ�£�����������");
        return M22_FAILD;
    } else {
        if (click_username(user, username) == 0) {
            printf("\n�û����Ѵ���");
            return M22_FAILD;
        }
    }
    fflush(stdin);
    printf("\n����д�ܱ�����\n");
    gets(user.question);
    fflush(stdin);
    printf("����д�����\n");
    gets(user.an);
    User_add(user);
    return 1;
}

int login(char username[], char password[]) {
    int cmd = 0;
    User user;
    if (!User_scarch(&user, username)) {
        printf("�û���������\n�����������");
        getch();
    } else {
        if (!click_password(user.password, password)) {
            printf("�������\n�����������");
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
    fp = fopen(DB_USER, "ab+");
    if (fp == NULL) {
        printf("\n�ļ���ʧ�ܣ�����ϵ����Ա");
        return 0;
    }
    printf("    ����    ����    ����    ��\n");
    while (fread(&user, sizeof(User), 1, fp)) {
        printf("     %s       %s       %s       %s\n", user.username, user.password, user.question, user.an);
    }

    return 1;
}

int goods(void) {
    Good good;
    FILE *fp = NULL;
    fp = fopen(DB_Good, "ab+");
    if (fp == NULL) {
        printf("\n�ļ���ʧ�ܣ�����ϵ����Ա");
        return 0;
    }
    printf("��Ʒ����    ����    ����    ����    �ܼ�\n");
    while (fread(&good, sizeof(Good), 1, fp)) {
        printf("%c         %s       %c       %c       %c\n", good.id, good.name, good.prize, good.count, good.total);
    }
    return 1;
}