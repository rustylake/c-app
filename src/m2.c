//
// Created by pengy on 2019/3/26.
//

#include "m2.h"
#include "m21.h"
#include <stdlib.h>
#include <stdio.h>
int m2_show_window(int cmd){
    system("CLS");
    printf("012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    printf("\n\n\n\n");
    printf("                                                  �̵����۹���ϵͳ\n");
    printf("                                                         v 1.0\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("��¼ϵͳ��\n");
    printf("    1  ��¼\n");
    printf("    2  �û�ע��\n");
    printf("    3. ��������\n");
    printf("    0  ����\n");
    scanf("%d",&cmd);
    return cmd;
}
int m2_call_back(int cmd){
    switch (cmd){
        case APP_M2_EXIT:
            break;
        case APP_M2_LOGIN:
            m21();
            break;
        case APP_M2_REGIST:
            break;
        case APP_M2_FORGITE:
            break;
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