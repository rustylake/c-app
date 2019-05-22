//
// Created by pengy on 2019/5/12.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "model/model.h"
#include "model/user.h"
#include "3/m31.h"

int m31_show_window(User user) {
    int cmd = CMD;
    show_head(user.username);
    printf("�������ϣ�\n");
    printf("     ������%s", user.username);
    printf("\n     �ܱ����⣺%s", user.question);
    printf("\n     ����𰸣�%s\n", user.an);
    printf("\n�޸����⣺1");
    printf("\n�޸Ĵ𰸣�2");
    printf("\n���أ�0\n");
    while (!scanf("%d", &cmd))fflush(stdin);
    return cmd;
}

int m31_call_back(int cmd, User user) {
    if (cmd == APP_M31_QUESTION) {
        printf("�������µ��ܱ����⣺\n");
        char question[128];
        fflush(stdin);
        gets(question);
        if (YN()) {
            User_change(user.username, USER_QUESTION, question);
            printf("\n�޸ĳɹ�");
            printf("\n�����������\n");
            getch();
        }
    }
    if (cmd == APP_M31_ANSWER) {
        printf("�������µ�����𰸣�\n");
        char question[128];
        fflush(stdin);
        gets(question);
        if (YN()) {
            User_change(user.username, USER_AN, question);
            printf("\n�޸ĳɹ�");
            printf("\n�����������\n");
            getch();
        }
    }
    return cmd;
}

int m31(char username[]) {
    int cmd = CMD;
    User user;
    while (1) {
        User_scarch(&user, username);
        cmd = m31_show_window(user);
        m31_call_back(cmd, user);
        if (APP_M31_EXIT == cmd)break;
    }
    return 0;
}