//�ļ�����main.c
//���ߣ�peny
//���ڣ�20190330
//
//��������¼ģ��
//
//����
//
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include "2/m21.h"
#include "2/m22.h"
#include <3/m3.h>
#include "model/model.h"

static char username[256];
static char password[256];


int m21_show_window(int cmd) {
    system("CLS");
    printf("\n\n\n\n");
    printf("                                                  �̵����۹���ϵͳ\n");
    printf("                                                         v 1.1\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("��¼�˻�\n");
    printf("    �������˺�\n");
    fflush(stdin);
    gets(username);
    printf("\n    ����������\n");
    fflush(stdin);
    gets(password);
    fflush(stdin);
    cmd = YN();
    return cmd;
}

int m21_call_back(int cmd) {
    if (cmd == 0)return 0;
    cmd = login(username, password);
    return cmd;
}

int m21() {
    int cmd = 0;
    while (1) {
        cmd = m21_show_window(cmd);
        cmd = m21_call_back(cmd);
        if (cmd == M21_LOGIN) {
            m3(username);
            //����ϵͳ
            break;
        }
        if (cmd == M21_EXIT)break;
    }
    return cmd;
}