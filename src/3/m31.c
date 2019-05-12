//
// Created by pengy on 2019/5/12.
//

#include <stdio.h>
#include <stdlib.h>
#include "3/m31.h"
#include "model/model.h"
#include "model/user.h"

int m31_show_window(User user) {
    int cmd = CMD;
    system("CLS");
    printf("��ǰ�û���%s", user.username);
    printf("\n\n\n\n");
    printf("                                                  �̵����۹���ϵͳ\n");
    printf("                                                         %s\n", VERSION);
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("�������ϣ�\n");
    printf("     ������%s", user.username);
    printf("\n     �ܱ����⣺%s", user.question);
    printf("\n     ����𰸣�%s\n", user.an);
    printf("     �޸����⣺1");
    printf("\n     �޸Ĵ𰸣�2");
    printf(" \n    ���أ�0\n");
    while (!scanf("%d", &cmd))fflush(stdin);
    return cmd;
}

int m31_call_back(int cmd) {
    if (cmd == APP_M31_ANSWER) {
        //
    }
    if (cmd == APP_M31_QUESTION) {
        //
    }
    return cmd;
}

int m31(char username[]) {
    int cmd = CMD;
    User user;
    User_scarch(&user, username);
    while (1) {
        cmd = m31_show_window(user);
        m31_call_back(cmd);
        if (APP_M31_EXIT == cmd)break;
    }
    return 0;
}