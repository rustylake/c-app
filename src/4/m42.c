//
// Created by pengy on 2019/5/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "4/m42.h"
#include "model/model.h"

int isTheDemo() {
    printf("��������Ʒ����\n");
    int id = 0;
    if (!scanf("%d", &id)) {
        fflush(stdin);
        printf("��������Ʒ���룡\n");
    }
    return id;
}

int m42_change_goods(void) {
    int id = isTheDemo();
    Good good;
    Good_view(&good, id);
    printf("��Ʒ��Ϣ��\n");
    printf("��Ʒ���ƣ����ۣ��ۼۣ���棺�ܼۣ�");
}

int m42_add_goods(void) {
    char name[128];
    int inprize;
    int outprize;
    printf("\n��������Ʒ����\n");
    fflush(stdin);
    gets(name);
    printf("��������Ʒ��������(��λ/Ԫ)\n");
    fflush(stdin);
    while (!scanf("%d", &inprize))
        fflush(stdin);
    printf("��������Ʒ��������(��λ/Ԫ)\n");
    fflush(stdin);
    while (!scanf("%d", &outprize))
        fflush(stdin);
    Good good;
    Good_init(&good, name, 0, inprize, outprize);
    Good_add(good) ? printf("\n��Ʒ��ӳɹ�") : printf("\n��Ʒ���ʧ��");
    getch();
    printf("\n�����������");
}

int m42_show_window(char username[]) {
    int cmd = CMD;
    system("CLS");
    printf("��ǰ�û���%s", username);
    printf("\n\n\n\n");
    printf("                                                  �̵����۹���ϵͳ\n");
    printf("                                                         %s\n", VERSION);
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("��ѡ��Ҫִ�еĲ�����\n");
    printf("     �鿴������Ʒ��1\n");
    printf("     �����Ʒ��2\n");
    printf("     ɾ����Ʒ��3\n");
    printf("     ������Ʒ��Ϣ��4\n");
    printf("     ��Ʒ��ѯ��5\n");
    printf("     �˳���0\n");
    while (!scanf("%d", &cmd))
        fflush(stdin);
    return cmd;
}

int m42_call_back(int cmd, char username[]) {
    if (cmd == APP_M42_LIST) {
        goods();
        fflush(stdin);
        printf("\n�����������");
        getch();
    }
    if (cmd == APP_M42_ADD) {
        m42_add_goods();
    }
    if (cmd == APP_M42_DELATE) {
        //ɾ��
    }
    if (cmd == APP_M42_CHANGE) {
        //����
    }
    if (cmd == APP_M42_SCARCH) {
        int id = isTheDemo();
        Good good;
        Good_view(&good, id) ? printf("��Ʒ���ƣ�%-5s  ���ۣ�%-3d  �ۼۣ�%-3d  ��棺%-3d  �ܼۣ�%-3d\n", good.name, good.inprize,
                                      good.outprize, good.count, good.total) : printf("��Ʒ�����ڣ�\n");
        fflush(stdin);
        printf("�����������");
        getch();
    }
    return cmd;
}

int m42(char username[]) {
    int cmd = CMD;
    while (1) {
        cmd = m42_show_window(username);
        m42_call_back(cmd, username);
        if (M22_EXIT == cmd)break;
    }
    return 0;
}