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
#include "1/m1.h"
#include "2/m2.h"
#include "model/model.h"
#include "test.h"

int m0_window_show() {
    int cmd = CMD;
    system("CLS");
    printf("\n\n\n\n");
    printf("                                                  �̵����۹���ϵͳ\n");
    printf("                                                         %s\n", VERSION);
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("��������Ӧ���֣�\n");
    printf("    1  ����ҳ��\n");
    printf("    2  ��¼ϵͳ\n");
    printf("    3  ����ϵͳ\n");
//    printf("    4  ������Ŀ\n");
    printf("    0  �˳�\n");
    while (!scanf("%d", &cmd))fflush(stdin);
    return cmd;
}

int m0_call_back(int cmd) {
    if (cmd == APP_M0_HELP) {//����
        m1();
    }
    if (cmd == APP_M0_LOGIN) {//��¼
        m2();
    }
    if (cmd == APP_M0_TEST) {//����
        test();
    }

    return cmd;
}

int m0() {
    int cmd = CMD;
    while (1) {
        cmd = m0_window_show();
        m0_call_back(cmd);
        if (cmd == APP_M0_EXIT)
            break;
    }
    return 0;

}