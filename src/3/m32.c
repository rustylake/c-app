//
// Created by pengy on 2019/5/20.
//

#include <stdio.h>
#include <conio.h>

#include "3/m32.h"
#include "model/goods.h"
#include "model/model.h"
#include "model/list.h"

int m32_show_window(char username[], List list) {
    show_head(username);
    List_goods_show(list);
    printf("��ǰ���ﳵ����Ʒ(%d/20)��\n", list.count);
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

int m32_call_back(List *list, int cmd) {
    if (cmd == 1) {
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
                } else {
                    break;
                }
            }
            if (counts != 0) {
                good.count = counts;
                good.total = counts * good.outprize;
                Good_add_list(list, &good, counts);
                printf("����ɹ�\n");
            }
        }
        printf("\n�����������\n");
        fflush(stdin);
        getch();
        return counts > 0 ? 1 : 0;
    }
    if (cmd == 2) {

    }
    if (cmd == 3) {

    }
}

int m32(char username[]) {
    int cmd = CMD;
    List list;
    List_init(&list, username);
    while (1) {
        cmd = m32_show_window(username, list);
        m32_call_back(&list, cmd);
        if (cmd == M32_EXIT)
            break;
    }
    return 0;
}