//
// Created by pengy on 2019/3/31.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "m22.h"
#include "model.h"


int m22_call_back(int cmd, char username[], char password[], char password2[]);

//*************************************************************
int m22_window_show(int cmd) {

    char username[128];
    char password[256];
    char password2[256];
    system("CLS");
    printf("012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    printf("\n\n\n\n");
    printf("                                                  �̵����۹���ϵͳ\n");
    printf("                                                         v 1.0\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("ע���˻�\n");
    printf("    �������˺�\n");
    fflush(stdin);
    gets(username);
    fflush(stdin);
    printf("\n    ����������\n");
    gets(password);
    fflush(stdin);
    printf("\n    ��ȷ������\n");
    gets(password2);
    fflush(stdin);
    cmd = YN();
    cmd = m22_call_back(cmd, username, password, password2);
    return cmd;
}

int m22_call_back(int cmd, char username[], char password[], char password2[]) {
    if (cmd == 0)return M22_EXIT;
    cmd = regist(username, password, password2);
    if (cmd == M22_SUCCESS)printf("\nע��ɹ�");
    if (cmd == M22_FAILD)printf("\nע��ʧ�ܣ�������");
    printf("\n�����������");
    getch();
    return cmd;
}

int m22() {
    int cmd = 1;
    cmd = m22_window_show(cmd);
    return cmd;
}
