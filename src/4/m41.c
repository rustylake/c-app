//
// Created by pengy on 2019/5/12.
//

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#include "model/model.h"
#include "model/user.h"
#include "4/m41.h"

int m42_change_user() {
    char username[128];
    printf("Ҫ�޸ĵ��û������ǣ�");
    fflush(stdin);
    gets(username);
    User user;
    if (User_scarch(&user, username) == USER_FAIL) {
        printf("\n�û�������\n");
    } else {
        printf("\n������%s   ���룺%s   ���⣺%s  �𰸣�%s\n",
               user.username,
               user.password,
               user.question,
               user.an);
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
        if (!YN("ȷ��Ҫ�޸���"))return 0;
        User_change(username, n, new);
        printf("\n�޸ĳɹ�");
    }

}

int m41_show_window(char username[]) {
    int cmd = CMD;
    show_head(username);
    users();
    printf("��ѡ��Ҫִ�еĲ�����\n");
    printf("     �޸��û���Ϣ��1\n");
    printf("         ɾ���û���2");
    printf("\n     �˳���0\n");
    while (!scanf("%d", &cmd))
        fflush(stdin);
    return cmd;
}

int m41_call_back(int cmd) {
    if (cmd == 1) {
        m42_change_user();
    }
    if (cmd == 2) {
        char username[128];
        printf("\n������Ҫɾ�����û�����\n");
        fflush(stdin);
        gets(username);
        User user;
        if (!User_scarch(&user, username)) {
            printf("�û�������\n");
        } else {
            if (YN("ȷ��Ҫɾ����")) {
                User_delate(username);
                printf("ɾ���ɹ�\n");
            }
        }
    }
    if (cmd != 0) {
        printf("\n�����������");
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