//
// Created by pengy on 2019/5/12.
//

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#include "4/m41.h"
#include "model/model.h"
#include "model/user.h"

int m41_show_window(char username[]) {
    int cmd = CMD;
    show_head(username);
    users();
    printf("��ѡ��Ҫִ�еĲ�����\n");
    printf("     �޸��û���Ϣ��1");
    printf("\n     �˳���0\n");
    while (!scanf("%d", &cmd))
        fflush(stdin);
    return cmd;
}

int m41_call_back(int cmd) {
    if (cmd == 1) {
        char username[128];
        printf("Ҫ�޸ĵ��û������ǣ�");
        fflush(stdin);
        gets(username);
        User user;
        User_scarch(&user, username);
        printf("\n������%s   ���룺%s   ���⣺%s  �𰸣�%s\n", user.username, user.password, user.question, user.an);
        printf("ѡ��Ҫ���ĵ���Ŀ��0.ȡ��\n                  1.����\n                  2.����\n                  3.��\n");
        int n = 0;
        while (scanf("%d", &n) ? !(n <= 3 && n >= 0) : 1)
            fflush(stdin);
        char change[10] = {0};
        switch (n) {
            case 0:
                return 0;
            case 1:
                n = USER_PASSWORD;
                strcat(change, "����");
                break;
            case 2:
                n = USER_QUESTION;
                strcat(change, "����");
                break;
            case 3:
                n = USER_AN;
                strcat(change, "��");
                break;
            default:
                break;
        }
        printf("��������%s��", change);
        char new[128];
        fflush(stdin);
        gets(new);
        if (!YN())return 0;
        User_change(username, n, new);
        printf("\n�޸ĳɹ�\n�����������");
        fflush(stdin);
        getch();
    }
    return cmd;
}

int m41(char username[]) {
    int cmd = CMD;
    while (1) {
        cmd = m41_show_window(username);
        m41_call_back(cmd);
        if (0 == cmd)break;
    }
    return 0;
}