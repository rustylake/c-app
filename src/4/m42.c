//
// Created by pengy on 2019/5/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "4/m42.h"
#include "model/model.h"

int m42_show_window(char username[]) {
    int cmd = CMD;
    system("CLS");
    printf("��ǰ�û���%s", username);
    printf("\n\n\n\n");
    printf("                                                  �̵����۹���ϵͳ\n");
    printf("                                                         %s\n", VERSION);
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("��ѡ��Ҫִ�еĲ�����\n");
    printf("     �鿴��Ʒ��1\n");
    printf("     �����Ʒ��2\n");
    printf("     ɾ����Ʒ��3\n");
    printf("     ������Ʒ��Ϣ��4\n");
    printf("     �˳���0\n");
    while (!scanf("%d", &cmd))fflush(stdin);
    return cmd;
}

int m42_call_back(int cmd, char username[]) {
    if (cmd == 1) {
        goods();
        fflush(stdin);
        printf("\n�����������");
        getch();
    }
    return cmd;
}

int m42(char username[]) {
    int cmd = CMD;
    while (1) {
        cmd = m42_show_window(username);
        m42_call_back(cmd, username);
        if (0 == cmd)break;
    }
    return 0;
}