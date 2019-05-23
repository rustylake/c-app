//
// Created by pengy on 2019/5/20.
//

#include <stdio.h>
#include <conio.h>

#include "3/m32.h"
#include "model/goods.h"
#include "model/model.h"
#include "model/list.h"
#include "test.h"

int m32_add_goods(List *list) {
    int id;
    printf("\n请输入商品代码\n");
    while (!scanf("%d", &id))
        fflush(stdin);
    Good good;
    int counts = 0;
    if (Good_view(&good, id) == Good_FAIL)
        printf("商品不存在\n");
    else {
        printf("商品名称：%-5s  售价：%-3d  库存：%-3d\n  ", good.name, good.outprize, good.count);
        printf("请输入购买数量：\n");
        while (1) {
            while (!scanf("%d", &counts))
                fflush(stdin);
            if (counts > good.count || counts < 0) {
                printf("购买数需小于库存\n");
                printf("请重新输入\n");
            } else {
                break;
            }
        }
        if (counts != 0) {
            good.count = counts;
            good.total = counts * good.outprize;
            Good_add_list(list, &good, counts);
            printf("购买成功\n");
        }
    }
    return counts > 0 ? 1 : 0;
}

int m32_delate_goods(List *list) {
    int id;
    printf("\n请输入商品代码\n");
    while (!scanf("%d", &id))
        fflush(stdin);
    Good good;
    int counts = 0;
    if (Good_view(&good, id) == Good_FAIL) {
        printf("商品不存在\n");
        return 0;
    }
    for (int i = 0; i < list->count; i++) {
        if (list->good[i].id == id) {
            Good_delate_list(list, id);
            printf("删除成功\n");
            return 1;
        }
    }
    printf("未购买此商品\n");
    return 0;
}

int m32_all(List list) {
    if (List_add(list) == LIST_FAIL)return 0;
    int totle = 0;
    for (int i = 0; i < list.count; i++) {
        totle += list.good[i].total;
    }
    printf("\n\n总金额为：%4d元\n", totle);
    printf("欢迎您下次光临\n");
    return 1;
}

int m32_show_window(char username[], List list) {
    show_head(username);
    printf("当前购物车中商品(%d/20)件\n\n", list.count);
    List_goods_show(list);
    int totle = 0;
    for (int i = 0; i < list.count; i++) {
        totle += list.good[i].total;
    }
    printf("                                             合计：%4d元\n", totle);
    printf("添加商品：1\n");
    printf("删除商品：2\n");
    printf("    结算：3\n");
    printf("    取消：0\n");
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
        *cmd = M32_EXIT;
    }
    printf("\n按任意键继续\n");
    fflush(stdin);
    getch();
    return 0;
}

int m32(char username[]) {
    int cmd = CMD;
    List list;
    List_init(&list, username);
    while (1) {
//        test();
        cmd = m32_show_window(username, list);
        m32_call_back(&list, &cmd);
        if (cmd == M32_EXIT)
            break;
    }
    return 0;
}