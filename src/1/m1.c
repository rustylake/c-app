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
    show_head(UNLOGIN);
    system("..\\help.png");
    fflush(stdin);
    printf("    ��������˳�\n");
    getch();
    return 0;
}

int m1() {
    m1_window_show();
    return 0;
}
