//
// Created by pengy on 2019/3/31.
//

#include <stdio.h>
#include <stdlib.h>
#include "m22.h"

static char username[256];
static char password[256];
static char password2[256];

int m22_YN(int* cmd){
    printf("ȷ��Ҫע����Y/N��\n");
    char login;
    int re=0;
    login=getchar();
    fflush(stdin);
    if(login=='Y'||login=='y'){*cmd=1;re=1;}
    if(login=='n'||login=='N'){*cmd=0;re=1;}
    return re;
}

int m22_check_password(){
    return 0;
}

int m22_check_username(){
    return 0;
}

//*************************************************************
int m22_window_show(){
    system("CLS");
    printf("012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    printf("\n\n\n\n");
    printf("                                                  �̵����۹���ϵͳ\n");
    printf("                                                         v 1.0\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("ע���˻�\n");
    printf("    �������˺�\n");
    fflush(stdin);
    gets(username);
    fflush(stdin);
    printf("\n    ����������\n");
    gets(password);
    fflush(stdin);
    printf("\n    ��ȷ������\n");
    gets(password2);
    fflush(stdin);
    int re=0,cmd=0;
    while(re!=1){re=m22_YN(&cmd);}
    return cmd;
}
int m22_call_back(int cmd){
    if (cmd == 0)return 0;
    if(m22_check_password()==0){
        printf("�����������벻һ�£�����������");
        return 1;
    } else{
        if (m22_check_username()==0){
            printf("�û����Ѵ���");
            return 1;
        }
    }
    //����˺�
    return 0;
}

int m22(){
    int cmd=1;
    while (1){
        cmd=m22_window_show(cmd);
        cmd=m22_call_back(cmd);
        if(cmd==0)break;
    }
    return 0;
}
