//
// Created by pengy on 2019/5/12.
//

#include <stdio.h>
#include <stdlib.h>
#include "model/model.h"
#include "4/m4.h"
#include "4/m41.h"
#include "4/m42.h"
int m4_show_window(char username[]) {
    int cmd = CMD;
    show_head(username);
    printf("��ѡ��Ҫִ�еĲ�����\n");
    printf("     �û�����1");
    printf("\n     ��Ʒ����2");
    printf("\n     ������ѯ��3");
    printf("\n     �˳���0\n");
    while (!scanf("%d", &cmd))fflush(stdin);
    return cmd;
}

int m4_call_back(int cmd, char username[]) {
    if (cmd == APP_M4_USER) {
        m41(username);
    }
    if (cmd == APP_M4_GOODS) {
        m42(username);
    }
    if (cmd == APP_M4_LIST) {

    }
    return cmd;
}

int m4(char username[]) {
    int cmd = CMD;
    while (1) {
        cmd = m4_show_window(username);
        m4_call_back(cmd, username);
        if (APP_M4_EXIT == cmd)break;
    }
    return 0;
}