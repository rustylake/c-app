//
// Created by pengy on 2019/5/12.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "model/model.h"
#include "model/goods.h"
#include "4/m42.h"

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
    if (Good_scarch(&good, id) == Good_FAIL) {
        printf("��Ʒ������");
        return 0;
    }
    int cmd = CMD;
    printf("��Ʒ��Ϣ��\n");
    printf("��Ʒ���ƣ�%-5s  ���ۣ�%-3d  �ۼۣ�%-3d  ��棺%-3d  �ܼۣ�%-3d\n",
           good.name,
           good.inprize,
           good.outprize,
           good.count,
           good.total);
    printf("�������޸���Ŀ��\n");
    printf("        �޸����ƣ�1\n");
    printf("        �޸Ľ��ۣ�2\n");
    printf("        �޸��ۼۣ�3\n");
    printf("        �޸Ŀ�棺4\n");
    printf("        ȡ����0\n");
    while (cmd > 4 || cmd < 0) {
        while (!scanf("%d", &cmd))
            fflush(stdin);
    }
    switch (cmd) {//�Ҿ����Ƕ�д��switchҲ����ȥ�ĺ궨���  ^-^_^-^
        case 1:
            printf("������������");
            fflush(stdin);
            char new[128];
            gets(new);
            Good_change_Name(good.id, new);
            return 1;
        case 2:
            cmd = Good_INPRIZE;
            break;
        case 3:
            cmd = Good_OUTPRIZE;
            break;
        case 4:
            cmd = Good_COUNT;
            break;
        default:
            return 0;
    }
    int new;
    do {
        printf("�������µ���ֵ");
        fflush(stdin);
        scanf("%d", &new);
    } while (new < 0);
    Good_change(good.id, cmd, new);
    printf("�޸ĳɹ�\n");
    return 1;
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
    if (Good_add(good)) {
        printf("\n��Ʒ��ӳɹ�");
        return 1;
    } else {
        printf("\n��Ʒ���ʧ��");
        return 0;
    }
}

int m42_show_window(char username[]) {
    int cmd = CMD;
    show_head(username);
    printf("��ѡ��Ҫִ�еĲ�����\n");
    printf("     �鿴������Ʒ��1\n");
    printf("     �����Ʒ��2\n");
    printf("     ɾ����Ʒ��3\n");
    printf("     ������Ʒ��Ϣ��4\n");
    printf("     ��Ʒ��ѯ��5\n");
    printf("     ��ѯ��Ʒ���룺6\n");
    printf("     �˳���0\n");
    while (!scanf("%d", &cmd))
        fflush(stdin);
    return cmd;
}

int m42_call_back(int cmd, char username[]) {
    if (cmd == APP_M42_LIST) {
        goods();
    }
    if (cmd == APP_M42_ADD) {
        m42_add_goods();
    }
    if (cmd == APP_M42_DELATE) {
        int id;
        printf("������Ҫɾ������Ʒ����\n");
        while (!scanf("%d", &id)) {
            fflush(stdin);
        }
        Good good;
        if (Good_scarch(&good, id)) {
            printf("��Ʒ���ƣ�%-5s  ���ۣ�%-3d  �ۼۣ�%-3d  ��棺%-3d  �ܼۣ�%-3d\n",
                   good.name,
                   good.inprize,
                   good.outprize,
                   good.count,
                   good.total);
            if (YN("ȷ��Ҫɾ����\n")) {
                Good_delate(id);
            }
        } else {
            printf("��Ʒ������\n");
        }
    }
    if (cmd == APP_M42_CHANGE) {
        m42_change_goods();
    }
    if (cmd == APP_M42_SCARCH) {
        int id = isTheDemo();
        Good good;
        Good_scarch(&good, id) ?
        printf("��Ʒ���ƣ�%-5s  ���ۣ�%-3d  �ۼۣ�%-3d  ��棺%-3d  �ܼۣ�%-3d\n",
               good.name,
               good.inprize,
               good.outprize,
               good.count,
               good.total) : printf("��Ʒ�����ڣ�\n");
    }
    if (cmd == APP_M42_SCARCHDEMO) {
        printf("��������Ʒ���ƣ�\n");
        char name[128];
        fflush(stdin);
        gets(name);
        int id = Good_getId(name);
        id == Good_FAIL ? printf("\n��Ʒ������") : printf("\n����Ʒ����Ϊ��%d", id);
    }
    if (cmd > 0 && cmd <= 6) {
        printf("\n�����������\n");
        fflush(stdin);
        getch();
    }
    return cmd;
}

int m42(char username[]) {
    int cmd = CMD;
    while (1) {
        cmd = m42_show_window(username);
        m42_call_back(cmd, username);
        if (APP_M42_EXIT == cmd)break;
    }
    return 0;
}