//
// Created by pengy on 2019/3/19.
//

#include "../header/m0.h"
#include <stdio.h>

int m0_window_show(){
    int cmd;
    printf("012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    printf("\n\n\n\n");
    printf("                                                  商店零售管理系统\n");
    printf("                                                         v 1.0\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("请输入相应数字：\n");
    printf("    1  登录系统\n");
    printf("    2  帮助页面\n");
    printf("    0  退出\n");
    scanf("%d",&cmd);
    return cmd;
}

int m0_call_back(cmd){
    return cmd;
}

int m0(){
    int cmd;
    cmd=m0_window_show();
    m0_call_back(cmd);
    return 0;

}