//
// Created by pengy on 2019/4/2.
//

#include "model.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <direct.h>

int YN() {
    int cmd=0;
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

int click_username(char username[]) {
    int i = 0;
    char user[128];
    FILE *fp = NULL;
    fp = fopen(DB_USER, "ab+");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�����ϵ����Ա");
        return M22_FAILD;
    }
    while (1) {
        if (fread(user, sizeof(char), 128, fp) != 128) {
            i = 1;
            break;
        };
        if (click_password(user, username))break;
    }
    fclose(fp);
    return i;
}

int click_password(char password1[], char password2[]){
    return !strcmp(password1,password2);
}

int regist(char *username, char *password, char *password2){
    if(click_password(password2,password)==0){
        printf("�����������벻һ�£�����������");
        return M22_FAILD;
    } else{
        if (click_username(username)==0){
            printf("�û����Ѵ���");
            return M22_FAILD;
        }
    }
    FILE* fp=NULL;
    fp = fopen(DB_USER, "ab");
    if (fp==NULL) {
        printf("�ļ���ʧ�ܣ�����ϵ����Ա");
        return M22_FAILD;
    }
    fwrite(username, sizeof(char), 128, fp);
    fwrite(password, sizeof(char), 128, fp);
    fclose(fp);
    return 1;
}

int login(char username[], char password[]) {
    char user[128];
    char pas[128];
    int cmd = 0;
    FILE *fp = NULL;
    fp = fopen(DB_USER, "rb");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�����ϵ����Ա");
        return M22_FAILD;
    }
    while (1) {
        if (fread(user, sizeof(char), 128, fp) != 128)break;
        fread(pas, sizeof(char), 128, fp);
        if (click_password(user, username)) {
            if (click_password(pas, password)) {
                cmd = 1;
            } else {
                printf("�������\n�����������");
                getch();
            }
        } else {
            printf("�û���������\n�����������");
            getch();
        }
            break;

    }
    return cmd;
}