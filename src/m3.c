//
// Created by pengy on 2019/4/14.
//
#include <stdio.h>
#include <stdlib.h>
#include "m3.h"

int m3_show_window(char username[]) {
    int cmd;
    system("CLS");
    printf("012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    printf("��ǰ�û���%s", username);
    printf("\n\n\n\n");
    printf("                                                  �̵����۹���ϵͳ\n");
    printf("                                                         v 1.1\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("��ѡ��Ҫִ�еĲ�����\n");
    printf("     ������Ʒ��1");
    printf("\n     �˳���0\n");
    scanf("%d", &cmd);
    return cmd;
}

int m3_call_back(int cmd) {
    if (cmd == M3_BUY) {
        //
    }
    return cmd;
}

int m3(char username[]) {
    int cmd = 1;
    while (1) {
        cmd = m3_show_window(username);
        m3_call_back(cmd);
        if (0 == cmd)break;
    }
}