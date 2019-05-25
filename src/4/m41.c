//
// Created by pengy on 2019/5/12.
//

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#include "model/model.h"
#include "model/user.h"
#include "4/m41.h"

int m42_change_user() {
    char username[128];
    printf("要修改的用户名字是：");
    fflush(stdin);
    gets(username);
    User user;
    if (User_scarch(&user, username) == USER_FAIL) {
        printf("\n用户不存在\n");
    } else {
        printf("\n姓名：%s   密码：%s   问题：%s  答案：%s\n",
               user.username,
               user.password,
               user.question,
               user.an);
        printf("选择要更改的项目：0.取消\n                  1.密码\n                  2.问题\n                  3.答案\n");
        int n = 0;
        while (scanf("%d", &n) ? !(n <= 3 && n >= 0) : 1)
            fflush(stdin);
        char change[10] = {0};
        switch (n) {
            case 0:
                return 0;
            case 1:
                n = USER_PASSWORD;
                strcat(change, "密码");
                break;
            case 2:
                n = USER_QUESTION;
                strcat(change, "问题");
                break;
            case 3:
                n = USER_AN;
                strcat(change, "答案");
                break;
            default:
                break;
        }
        printf("请输入新%s：", change);
        char new[128];
        fflush(stdin);
        gets(new);
        if (!YN("确定要修改吗"))return 0;
        User_change(username, n, new);
        printf("\n修改成功");
    }
    printf("\n按任意键继续");
    fflush(stdin);
    getch();
}

int m41_show_window(char username[]) {
    int cmd = CMD;
    show_head(username);
    users();
    printf("请选择要执行的操作：\n");
    printf("     修改用户信息：1");
    printf("\n     退出：0\n");
    while (!scanf("%d", &cmd))
        fflush(stdin);
    return cmd;
}

int m41_call_back(int cmd) {
    if (cmd == 1) {
        m42_change_user();
    }
    return cmd;
}

int m41(char username[]) {
    int cmd = CMD;
    while (1) {
        cmd = m41_show_window(username);
        m41_call_back(cmd);
        if (0 == cmd)break;
    }
    return 0;
}