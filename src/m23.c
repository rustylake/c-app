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
        printf("\n�û���������\n");
    } else {
        printf("%s:\n", user.question);
        printf("������𰸣�");
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
    printf("                                                  �̵����۹���ϵͳ\n");
    printf("                                                         v 1.1\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("�������û���");
    fflush(stdin);
    gets(username);
    fflush(stdin);
    m23_call_back(username) ? printf("�޸ĳɹ��������µ�¼\n�����������") : printf("�޸�ʧ��\n�����������");
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
            printf("������������\n");
            gets(password);
            fflush(stdin);
            printf("��ȷ������\n");
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