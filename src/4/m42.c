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
    printf("请输入商品代码\n");
    int id = 0;
    if (!scanf("%d", &id)) {
        fflush(stdin);
        printf("请输入商品代码！\n");
    }
    return id;
}

int m42_change_goods(void) {
    int id = isTheDemo();
    Good good;
    if (Good_view(&good, id) == Good_FAIL) {
        printf("商品不存在");
        return 0;
    }
    int cmd = CMD;
    printf("商品信息：\n");
    printf("商品名称：%-5s  进价：%-3d  售价：%-3d  库存：%-3d  总价：%-3d\n", good.name, good.inprize,
           good.outprize, good.count, good.total);
    printf("请输入修改项目：\n");
    printf("        修改名称：1\n");
    printf("        修改进价：2\n");
    printf("        修改售价：3\n");
    printf("        修改库存：4\n");
    printf("        取消：0\n");
    while (cmd > 4 || cmd < 0) {
        while (!scanf("%d", &cmd))
            fflush(stdin);
    }
    switch (cmd) {//我就算是多写个switch也不会去改宏定义的  ^-^_^-^
        case 1:
            printf("请输入新名称");
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
        printf("请输入新的数值");
        fflush(stdin);
        scanf("%d", &new);
    } while (new < 0);
    Good_change(good.id, cmd, new);
    printf("修改成功\n");
    return 1;
}

int m42_add_goods(void) {
    char name[128];
    int inprize;
    int outprize;
    printf("\n请输入商品名称\n");
    fflush(stdin);
    gets(name);
    printf("请输入商品进货单价(单位/元)\n");
    fflush(stdin);
    while (!scanf("%d", &inprize))
        fflush(stdin);
    printf("请输入商品售卖单价(单位/元)\n");
    fflush(stdin);
    while (!scanf("%d", &outprize))
        fflush(stdin);
    Good good;
    Good_init(&good, name, 0, inprize, outprize);
    if (Good_add(good)) {
        printf("\n商品添加成功");
        return 1;
    } else {
        printf("\n商品添加失败");
        return 0;
    }
}

int m42_show_window(char username[]) {
    int cmd = CMD;
    show_head(username);
    printf("请选择要执行的操作：\n");
    printf("     查看所有商品：1\n");
    printf("     添加商品：2\n");
    printf("     删除商品：3\n");
    printf("     更改商品信息：4\n");
    printf("     商品查询：5\n");
    printf("     查询商品代码：6\n");
    printf("     退出：0\n");
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
        //删除
    }
    if (cmd == APP_M42_CHANGE) {
        m42_change_goods();
    }
    if (cmd == APP_M42_SCARCH) {
        int id = isTheDemo();
        Good good;
        Good_view(&good, id) ? printf("商品名称：%-5s  进价：%-3d  售价：%-3d  库存：%-3d  总价：%-3d\n", good.name, good.inprize,
                                      good.outprize, good.count, good.total) : printf("商品不存在！\n");
    }
    if (cmd == APP_M42_SCARCHDEMO) {
        printf("请输入商品名称：\n");
        char name[128];
        fflush(stdin);
        gets(name);
        int id = Good_getId(name);
        id == Good_FAIL ? printf("\n商品不存在") : printf("\n该商品代码为：%d", id);
    }
    if (cmd > 0 && cmd <= 6) {
        printf("\n按任意键继续\n");
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