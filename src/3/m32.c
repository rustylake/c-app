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
    printf("\n请输入商品代码\n");
    while (!scanf("%d", &id))
        fflush(stdin);
    Good good;
    int counts = 0;
    if (Good_scarch(&good, id) == Good_FAIL)
        printf("商品不存在\n");
    else {
        printf("商品名称：%-5s  售价：%-3d  库存：%-3d\n  ",
               good.name,
               good.outprize,
               good.count);
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
            Good_change(good.id,
                        Good_COUNT,
                        good.count - counts);
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
    if (Good_scarch(&good, id) == Good_FAIL) {
        printf("商品不存在\n");
        return 0;
    }
    for (int i = 0; i < list->count; i++) {
        if (list->good[i].id == id) {
            Good_delate_list(list, id);
            Good_change(good.id,
                        Good_COUNT,
                        good.count + list->good[i].count);
            printf("删除成功\n");
            return 1;
        }
    }
    printf("未购买此商品\n");
    return 0;
}

int m32_all(List list) {
    int totle = 0;
    for (int i = 0; i < list.count; i++) {
        totle += list.good[i].total;
    }
    int money = 0;
    User user;
    if (User_scarch(&user, list.username)) {//这里的确不应该嵌套这么多层的，但是我三元表达式用不好
        printf("当前积分：%4d", user.point);
        if (user.point >= 100) {
            if (YN("要使用积分抵消一部分付款吗")) {
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
    printf("\n\n总金额为：%4d元\n", totle);
    printf("积分抵消: %4d元\n", money);
    printf("实付款：  %4d元\n", totle - money);
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
    printf("                                             合计：%4d元\n\n", totle);
    printf("---------------------------------------------------------\n");
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
        if (list->count == 20) {
            printf("\n购物车已满\n");
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
        printf("\n按任意键继续\n");
        fflush(stdin);
        getch();
    }
    return 0;
}

BOOL HandlerRoutine(int CtrlType) {
    switch (CtrlType) {
        case CTRL_CLOSE_EVENT: //用户要关闭Console了
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
        printf("\n钩子安装失败，请在退出购物车模块后再关闭程序！\n\n");
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