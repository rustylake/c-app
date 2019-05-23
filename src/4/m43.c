//
// Created by pengy on 2019/5/23.
//

#include <stdio.h>
#include <conio.h>

#include "4/m43.h"
#include "model/model.h"


int m43_show_window(char username[]) {
    show_head(username);
    printf("\n请选择操作：\n");
    printf("    查看所有订单：1\n");
    printf("    订单查询：2\n");
    printf("    返回：0\n");
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
        printf("请输入顾客姓名：\n");
        char name[128];
        fflush(stdin);
        gets(name);
        List list;
        if (List_scarch(&list, name) == LIST_SUCCESS) {
            printf("\n该顾客最近一次的订单为：\n");
            printf("\n顾客姓名：%s\n", list.username);
            printf("购买时间：%s\n", list.time);
            printf("购买商品：\n");
            printf("商品代号     名  称      售  价       数  量       总  价\n");
            int totle = 0;
            for (int i = 0; i < list.count; i++) {
                totle += list.good[i].total;
                printf("   %-2d        %-10.10s    %-3d           %-3d         %-3d\n", list.good[i].id,
                       list.good[i].name,
                       list.good[i].outprize, list.good[i].count, list.good[i].total);
            }
            printf("\n                                             合计：%4d元\n", totle);
        } else {
            printf("\n未查询到该顾客\n");
        }
    }
    if (cmd > 0 && cmd <= 2) {
        fflush(stdin);
        printf("按任意键继续");
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
