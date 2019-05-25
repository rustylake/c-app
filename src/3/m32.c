//
// Created by pengy on 2019/5/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

#include "3/m32.h"
#include "model/goods.h"
#include "model/model.h"
#include "model/list.h"

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
        printf("��Ʒ���ƣ�%-5s  �ۼۣ�%-3d  ��棺%-3d\n  ",
               good.name,
               good.outprize,
               good.count);
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
            Good_change(good.id,
                        Good_COUNT,
                        good.count - counts);
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
            Good_change(good.id,
                        Good_COUNT,
                        good.count + list->good[i].count);
            printf("ɾ���ɹ�\n");
            return 1;
        }
    }
    printf("δ�������Ʒ\n");
    return 0;
}

int m32_all(List list) {
    int totle = 0;
    for (int i = 0; i < list.count; i++) {
        totle += list.good[i].total;
    }
    int money = 0;
    User user;
    if (User_scarch(&user, list.username)) {//�����ȷ��Ӧ��Ƕ����ô���ģ���������Ԫ���ʽ�ò���
        printf("��ǰ���֣�%4d", user.point);
        if (user.point >= 100) {
            if (YN("Ҫʹ�û��ֵ���һ���ָ�����")) {
                money = user.point / 100;
                if (money > totle) {
                    money = totle;
                    user.point -= money * 100;
                } else {
                    user.point %= 100;
                }
            } else {
                user.point += totle;
            }
        } else {
            user.point += totle;
        }
        User_change_point(user.username, user.point);
        list.money = money;
    } else {
        strcpy(user.username, UNLOGIN);
    }
    List_add(list);
    system("del ..\\goods1.db");
    printf("\n\n�ܽ��Ϊ��%4dԪ\n", totle);
    printf("���ֵ���: %4dԪ\n", money);
    printf("ʵ���  %4dԪ\n", totle - money);
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
    printf("                                             �ϼƣ�%4dԪ\n\n", totle);
    printf("---------------------------------------------------------\n");
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
        if (list->count == 20) {
            printf("\n���ﳵ����\n");
        } else {
            m32_add_goods(list);
        }
    }
    if (cmd == 2) {
        m32_delate_goods(list);
    }
    if (cmd == 3) {
        printf("\n---------------------------------------------------------\n");
        m32_all(*list);
    }
    if (cmd == M32_EXIT) {
        system("del ..\\goods.db ");
        system("rename ..\\goods1.db goods.db");
    }
    if (cmd > 0 && cmd < 4) {
        printf("\n�����������\n");
        fflush(stdin);
        getch();
    }
    return 0;
}

BOOL HandlerRoutine(int CtrlType) {
    switch (CtrlType) {
        case CTRL_CLOSE_EVENT: //�û�Ҫ�ر�Console��
            system("del ..\\goods.db ");
            system("rename ..\\goods1.db goods.db");
            break;
    }
    return 0;
}

int m32(char username[]) {
    int cmd = CMD;
    system("copy ..\\goods.db ..\\goods1.db");
    BOOL bRet;
    bRet = SetConsoleCtrlHandler((PHANDLER_ROUTINE) &HandlerRoutine, TRUE);
    if (bRet == FALSE)
        printf("\n���Ӱ�װʧ�ܣ������˳����ﳵģ����ٹرճ���\n\n");
    List list;
    List_init(&list, username);
    while (1) {
        cmd = m32_show_window(username, list);
        m32_call_back(&list, cmd);
        if (cmd == M32_EXIT || cmd == 3) {
            SetConsoleCtrlHandler((PHANDLER_ROUTINE) &HandlerRoutine, FALSE);
            break;
        }
    }
    return 0;
}