//
// Created by pengy on 2019/5/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "4/m42.h"
#include "model/model.h"

int m42_show_window(char username[]) {
    int cmd = CMD;
    system("CLS");
    printf("当前用户：%s", username);
    printf("\n\n\n\n");
    printf("                                                  商店零售管理系统\n");
    printf("                                                         %s\n", VERSION);
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("请选择要执行的操作：\n");
    printf("     查看商品：1\n");
    printf("     添加商品：2\n");
    printf("     删除商品：3\n");
    printf("     更改商品信息：4\n");
    printf("     退出：0\n");
    while (!scanf("%d", &cmd))fflush(stdin);
    return cmd;
}

int m42_call_back(int cmd, char username[]) {
    if (cmd == 1) {
        goods();
        fflush(stdin);
        printf("\n按任意键继续");
        getch();
    }
    return cmd;
}

int m42(char username[]) {
    int cmd = CMD;
    while (1) {
        cmd = m42_show_window(username);
        m42_call_back(cmd, username);
        if (0 == cmd)break;
    }
    return 0;
}