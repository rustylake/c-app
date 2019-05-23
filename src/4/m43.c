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
        printf("������˿�������\n");
        char name[128];
        fflush(stdin);
        gets(name);
        List list;
        if (List_scarch(&list, name) == LIST_SUCCESS) {
            printf("\n�ù˿����һ�εĶ���Ϊ��\n");
            printf("\n�˿�������%s\n", list.username);
            printf("����ʱ�䣺%s\n", list.time);
            printf("������Ʒ��\n");
            printf("��Ʒ����     ��  ��      ��  ��       ��  ��       ��  ��\n");
            int totle = 0;
            for (int i = 0; i < list.count; i++) {
                totle += list.good[i].total;
                printf("   %-2d        %-10.10s    %-3d           %-3d         %-3d\n", list.good[i].id,
                       list.good[i].name,
                       list.good[i].outprize, list.good[i].count, list.good[i].total);
            }
            printf("\n                                             �ϼƣ�%4dԪ\n", totle);
        } else {
            printf("\nδ��ѯ���ù˿�\n");
        }
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
