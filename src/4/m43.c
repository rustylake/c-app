//
// Created by pengy on 2019/5/23.
//

#include <stdio.h>
#include <conio.h>

#include "4/m43.h"
#include "model/model.h"


int m43_show_window(char username[]) {
    show_head(username);
    printf("\n��ѡ�������\n");
    printf("    �鿴���ж�����1\n");
    printf("    ������ѯ��2\n");
    printf("    ���أ�0\n");
    int cmd = CMD;
    while (!scanf("%d", &cmd)) {
        fflush(stdin);
    }
    return cmd;
}

int m43_call_back(int cmd) {
    if (cmd == 1) {
        lists();
    }
    if (cmd == 2) {

    }
    if (cmd > 0 && cmd <= 2) {
        fflush(stdin);
        printf("�����������");
        getch();
    }
}

int m43(char username[]) {
    int cmd = CMD;
    while (1) {
        cmd = m43_show_window(username);
        m43_call_back(cmd);
        if (cmd == 0)
            break;
    }
    return 0;
}
