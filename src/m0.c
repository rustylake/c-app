//�ļ�����m0.c
//���ߣ�peny
//���ڣ�20190330
//
//��������ʼģ��
//
//����
//
#include "m0.h"
#include <stdio.h>
#include <stdlib.h>
#include "m1.h"
#include "m2.h"
int m0_window_show(){
    int cmd;
    system("CLS");
    printf("\n\n\n\n");
    printf("                                                  �̵����۹���ϵͳ\n");
    printf("                                                         v 1.0\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("��������Ӧ���֣�\n");
    printf("    1  ����ҳ��\n");
    printf("    2  ��¼ϵͳ\n");
    printf("    3  ����ϵͳ\n");
    printf("    0  �˳�\n");
    scanf("%d",&cmd);
    return cmd;
}

int m0_call_back(cmd){
    if (cmd==APP_M0_HELP){//����
        m1();
    }
    if (cmd==APP_M0_LOGIN){//��¼
        m2();
    }

    return cmd;
}

int m0(){
    int cmd;
    while (1) {
        cmd=m0_window_show();
        m0_call_back(cmd);
        if (cmd==APP_M0_EXIT)
            break;
    }
    return 0;

}