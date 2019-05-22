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
    printf("当前购物车中商品(%d/20)件\n", list.count);
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

int m32_call_back(List *list, int cmd) {
    if (cmd == 1) {
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
        printf("\n按任意键继续\n");
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