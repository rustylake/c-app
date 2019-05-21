//
// Created by pengy on 2019/4/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>

#include "model/user.h"
#include "model/model.h"

int User_add(User user) {
    FILE *fp = NULL;
    fp = fopen(DB_USER, "ab");
    if (fp == NULL) {
        printf("文件打开失败，请联系管理员");
        return USER_FAIL;
    }
    fwrite(&user, sizeof(User), 1, fp);
    fclose(fp);
    return 0;
}

int User_clone(User *user1, User *user2) {
    if (user1 == NULL || user2 == NULL)
        return 0;
    strcpy(user1->username, user2->username);
    strcpy(user1->question, user2->question);
    strcpy(user1->password, user2->password);
    strcpy(user1->an, user2->an);
    return 1;
}

int User_change(char username[], int c, char change[]) {
    if (c != USER_PASSWORD && c != USER_AN && c != USER_QUESTION)return 0;
    User user;
    FILE *fp = NULL;
    fp = fopen(DB_USER, "rb+");
    if (fp == NULL) {
        printf("文件打开失败，请联系管理员");
        return USER_FAIL;
    }
    while (fread(&user, sizeof(User), 1, fp)) {
        if (click_password(user.username, username)) {
            fseek(fp, sizeof(User) * (-1), SEEK_CUR);
            switch (c) {
                case USER_PASSWORD:
                    strcpy(user.password, change);
                    break;
                case USER_QUESTION:
                    strcpy(user.question, change);
                    break;
                case USER_AN:
                    strcpy(user.an, change);
                    break;
            }
            fflush(stdin);
            fwrite(&user, sizeof(User), 1, fp);
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int User_scarch(User *user, char *username) {
    FILE *fp = NULL;
    fp = fopen(DB_USER, "ab+");
    if (fp == NULL) {
        printf("文件打开失败，请联系管理员");
        return USER_FAIL;
    }
    while (fread(user, sizeof(User), 1, fp)) {
        if (click_password(user->username, username)) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;

}
