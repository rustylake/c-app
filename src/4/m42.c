//
// Created by pengy on 2019/5/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "4/m42.h"
#include "model/model.h"

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
    Good_view(&good, id);
    printf("商品信息：\n");
    printf("商品名称：进价：售价：库存：总价：");
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
    Good_add(good) ? printf("\n商品添加成功") : printf("\n商品添加失败");
    getch();
    printf("\n按任意键继续");
}

int m42_show_window(char username[]) {
    int cmd = CMD;
    system("CLS");
    printf("当前用户：%s", username);
    printf("\n\n\n\n");
    printf("                                                  商店零售管理系统\n");
    printf("                                                         %s\n", VERSION);
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("请选择要执行的操作：\n");
    printf("     查看所有商品：1\n");
    printf("     添加商品：2\n");
    printf("     删除商品：3\n");
    printf("     更改商品信息：4\n");
    printf("     商品查询：5\n");
    printf("     退出：0\n");
    while (!scanf("%d", &cmd))
        fflush(stdin);
    return cmd;
}

int m42_call_back(int cmd, char username[]) {
    if (cmd == APP_M42_LIST) {
        goods();
        fflush(stdin);
        printf("\n按任意键继续");
        getch();
    }
    if (cmd == APP_M42_ADD) {
        m42_add_goods();
    }
    if (cmd == APP_M42_DELATE) {
        //删除
    }
    if (cmd == APP_M42_CHANGE) {
        //更改
    }
    if (cmd == APP_M42_SCARCH) {
        int id = isTheDemo();
        Good good;
        Good_view(&good, id) ? printf("商品名称：%-5s  进价：%-3d  售价：%-3d  库存：%-3d  总价：%-3d\n", good.name, good.inprize,
                                      good.outprize, good.count, good.total) : printf("商品不存在！\n");
        fflush(stdin);
        printf("按任意键继续");
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