//文件名：main.c
//作者：peny
//日期：20190330
//
//描述：登录系统模块
//
//操作
//
#include "m2.h"
#include "m21.h"
#include "m22.h"
#include "m3.h"

#include <stdlib.h>
#include <stdio.h>
int m2_show_window(int cmd){
    system("CLS");
    printf("012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    printf("\n\n\n\n");
    printf("                                                  商店零售管理系统\n");
    printf("                                                         v 1.1\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("登录系统：\n");
    printf("    1  登录\n");
    printf("    2  用户注册\n");
    printf("    3. 忘记密码（仅限管理员使用）\n");
    printf("    0  返回\n");
    scanf("%d",&cmd);
    return cmd;
}
int m2_call_back(int cmd){
    switch (cmd){
        case APP_M2_EXIT://返回主界面
            break;
        case APP_M2_LOGIN://登录
            m21();
            break;
        case APP_M2_REGIST://注册
            m22();
            break;
        case APP_M2_FORGITE://忘记密码

            break;
        default:
            break;

    }
    return cmd;
}


int m2(){
    int cmd=1;
    while (1){
       cmd=m2_show_window(cmd);
       cmd=m2_call_back(cmd);
       if (cmd==0)break;
    }
    return cmd;
}