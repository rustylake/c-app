//�ļ�����main.c
//���ߣ�peny
//���ڣ�20190330
//
//��������¼ϵͳģ��
//
//����
//
#include "2/m23.h"
#include "2/m2.h"
#include "2/m21.h"
#include "2/m22.h"
#include "3/m3.h"

#include <stdlib.h>
#include <stdio.h>

int m2_show_window(int cmd) {
    system("CLS");
    printf("\n\n\n\n");
    printf("                                                  �̵����۹���ϵͳ\n");
    printf("                                                         v 1.1\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("��¼ϵͳ��\n");
    printf("    1  ��¼\n");
    printf("    2  �û�ע��\n");
    printf("    3. ��������\n");
    printf("    0  ����\n");
    scanf("%d", &cmd);
    return cmd;
}

int m2_call_back(int cmd) {
    switch (cmd) {
        case APP_M2_EXIT://����������
            break;
        case APP_M2_LOGIN://��¼
            m21();
            break;
        case APP_M2_REGIST://ע��
            m22();
            break;
        case APP_M2_FORGITE://��������
            m23();
            break;
        default:
            break;

    }
    return cmd;
}


int m2() {
    int cmd = 1;
    while (1) {
        cmd = m2_show_window(cmd);
        cmd = m2_call_back(cmd);
        if (cmd == 0)break;
    }
    return cmd;
}