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
        printf("�ļ���ʧ�ܣ�����ϵ����Ա");
        return USER_FAIL;
    }
    fwrite(&user, sizeof(User), 1, fp);
    fclose(fp);
    return 0;
}

int User_clone(User *user1, User *user2) {
    if (user1 == NULL || user2 == NULL)//ָ�봫�����
        return USER_FAIL;
    strcpy(user1->username, user2->username);
    strcpy(user1->question, user2->question);
    strcpy(user1->password, user2->password);
    strcpy(user1->an, user2->an);
    user1->point = user2->point;
    return 1;
}

int User_change(char username[], int c, char change[]) {
    if (c != USER_PASSWORD && c != USER_AN && c != USER_QUESTION && c != USER_POINT)//�жϲ�����ȷ��
        return 0;
    User user;
    FILE *fp = NULL;
    fp = fopen(DB_USER, "rb+");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�����ϵ����Ա");
        return USER_FAIL;
    }
    while (fread(&user, sizeof(User), 1, fp)) {
        if (click_password(user.username, username)) {
            fseek(fp, sizeof(User) * (-1), SEEK_CUR);
            switch (c) {
                case USER_PASSWORD://����
                    strcpy(user.password, change);
                    break;
                case USER_QUESTION://����
                    strcpy(user.question, change);
                    break;
                case USER_AN://��
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
    return USER_FAIL;
}

int User_change_point(char username[], int point) {
    User user;
    FILE *fp = NULL;
    fp = fopen(DB_USER, "rb+");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�����ϵ����Ա");
        return USER_FAIL;
    }
    while (fread(&user, sizeof(User), 1, fp)) {
        if (click_password(user.username, username)) {
            fseek(fp, sizeof(User) * (-1), SEEK_CUR);
            user.point = point;
            fwrite(&user, sizeof(User), 1, fp);
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return USER_FAIL;
}

int User_scarch(User *user, char *username) {
    FILE *fp = NULL;
    fp = fopen(DB_USER, "ab+");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�����ϵ����Ա");
        return USER_FAIL;
    }
    while (fread(user, sizeof(User), 1, fp)) {
        if (click_password(user->username, username)) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return USER_FAIL;

}

int User_delate(char username[]) {
    FILE *fp = NULL;
    fp = fopen(DB_USER, "ab+");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�����ϵ����Ա");
        return USER_FAIL;
    }
    FILE *newfp = NULL;//��ʱ�ļ�
    newfp = fopen("../users1.db", "ab+");
    if (newfp == NULL) {
        printf("�ļ���ʧ�ܣ�����ϵ����Ա");
        return USER_FAIL;
    }
    User user;
    while (fread(&user, sizeof(User), 1, fp)) {
        if (abs(strcmp(user.username, username))) {//��username��ͬ������
            fwrite(&user, sizeof(User), 1, newfp);
        }
    }
    fclose(fp);
    fclose(newfp);
    system("del ..\\users.db");//ɾ��ԭʼ�ļ�
    system("rename ..\\users1.db users.db");//����
    return 1;
}