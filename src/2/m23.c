//
// Created by pengy on 2019/4/27.
//
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "model/model.h"
#include "model/user.h"
#include "2/m23.h"

int m23_call_back(char username[]);

int m23_click_question(User *user, char username[]) {
    int cmd = 0;
    if (!User_scarch(user, username)) {
        printf("\n�û���������\n");
    } else {
        printf("%s:\n", user->question);
        printf("������𰸣�");
        char an[128];
        fflush(stdin);
        gets(an);
        cmd = click_password(an, user->an);
    }
    return cmd;
}

int m23_show_window() {
    char username[128];
    show_head(UNLOGIN);
    printf("�������û���\n");
    fflush(stdin);
    gets(username);
    fflush(stdin);
    m23_call_back(username) ? printf("�޸ĳɹ��������µ�¼\n�����������") : printf("�޸�ʧ��\n�����������");
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
            printf("������������\n");
            fflush(stdin);
            gets(password);
            printf("��ȷ������\n");
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