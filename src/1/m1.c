//�ļ�����m1.c
//���ߣ�peny
//���ڣ�20190330
//
//����������ҳ��
//
//�ӿڼ����������ͷ�ļ�
//����
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include "1/m1.h"
#include "model/model.h"

int m1_window_show() {
    system("CLS");
    printf("\n\n\n\n");
    printf("                                                  �̵����۹���ϵͳ\n");
    printf("                                                        %s\n", VERSION);
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("    ����ҳ��\n");
    printf("    1  ����������\n");
    printf("    2  ����������\n");
    printf("    1  ����������\n");
    printf("    1  ����������\n");
    printf("    1  ����������\n");
    printf("    1  ����������\n");
    printf("    ��������˳�\n");
    getch();
    return 0;
}

int m1_call_back() {
    return 0;
}

int m1() {
    int cmd = CMD;
    while (1) {
        m1_window_show();
        m1_call_back();
        break;
    }
    return 0;
}
