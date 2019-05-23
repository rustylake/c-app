//
// Created by pengy on 2019/5/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "3/m32.h"
#include "model/goods.h"
#include "model/model.h"
#include "model/list.h"
#include "test.h"

int m32_add_goods(List *list) {
    int id;
    printf("\n��������Ʒ����\n");
    while (!scanf("%d", &id))
        fflush(stdin);
    Good good;
    int counts = 0;
    if (Good_view(&good, id) == Good_FAIL)
        printf("��Ʒ������\n");
    else {
        printf("��Ʒ���ƣ�%-5s  �ۼۣ�%-3d  ��棺%-3d\n  ", good.name, good.outprize, good.count);
        printf("�����빺��������\n");
        while (1) {
            while (!scanf("%d", &counts))
                fflush(stdin);
            if (counts > good.count || counts < 0) {
                printf("��������С�ڿ��\n");
                printf("����������\n");
            } else {
                break;
            }
        }
        if (counts != 0) {
            Good_change(good.id, Good_COUNT, good.count - counts);
            Good_add_list(list, &good, counts);
            printf("����ɹ�\n");
        }
    }
    return counts > 0 ? 1 : 0;
}

int m32_delate_goods(List *list) {
    int id;
    printf("\n��������Ʒ����\n");
    while (!scanf("%d", &id))
        fflush(stdin);
    Good good;
    int counts = 0;
    if (Good_view(&good, id) == Good_FAIL) {
        printf("��Ʒ������\n");
        return 0;
    }
    for (int i = 0; i < list->count; i++) {
        if (list->good[i].id == id) {
            Good_delate_list(list, id);
            Good_change(good.id, Good_COUNT, good.count + list->good[i].count);
            printf("ɾ���ɹ�\n");
            return 1;
        }
    }
    printf("δ�������Ʒ\n");
    return 0;
}

int m32_all(List list) {
    if (List_add(list) == LIST_FAIL)return 0;
    int totle = 0;
    for (int i = 0; i < list.count; i++) {
        totle += list.good[i].total;
    }
    system("del ..\\goods1.db");
    printf("\n\n�ܽ��Ϊ��%4dԪ\n", totle);
    printf("��ӭ���´ι���\n");
    return 1;
}

int m32_show_window(char username[], List list) {
    show_head(username);
    printf("��ǰ���ﳵ����Ʒ(%d/20)��\n\n", list.count);
    List_goods_show(list);
    int totle = 0;
    for (int i = 0; i < list.count; i++) {
        totle += list.good[i].total;
    }
    printf("                                             �ϼƣ�%4dԪ\n", totle);
    printf("�����Ʒ��1\n");
    printf("ɾ����Ʒ��2\n");
    printf("    ���㣺3\n");
    printf("    ȡ����0\n");
    fflush(stdin);
    int cmd = CMD;
    while (!scanf("%d", &cmd))
        fflush(stdin);
    return cmd;
}

int m32_call_back(List *list, int *cmd) {
    if (*cmd == 1) {
        m32_add_goods(list);
    }
    if (*cmd == 2) {
        m32_delate_goods(list);
    }
    if (*cmd == 3) {
        m32_all(*list);
        *cmd = M32_TOTLE;
    }
    if (*cmd == M32_EXIT) {
        system("del ..\\goods.db ");
        system("rename ..\\goods1.db goods.db");
    }
    printf("\n�����������\n");
    fflush(stdin);
    getch();
    return 0;
}

int m32(char username[]) {
    int cmd = CMD;
    system("copy ..\\goods.db ..\\goods1.db");
    List list;
    List_init(&list, username);
    while (1) {
        cmd = m32_show_window(username, list);
        m32_call_back(&list, &cmd);
        if (cmd == M32_EXIT || cmd == M32_TOTLE)
            break;
    }
    return 0;
}