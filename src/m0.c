//
// Created by pengy on 2019/3/19.
//

#include "../header/m0.h"
#include <stdio.h>

int m0_window_show(){
    int cmd;
    printf("012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    printf("\n\n\n\n");
    printf("                                                  �̵����۹���ϵͳ\n");
    printf("                                                         v 1.0\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("��������Ӧ���֣�\n");
    printf("    1  ��¼ϵͳ\n");
    printf("    2  ����ҳ��\n");
    printf("    0  �˳�\n");
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