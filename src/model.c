//
// Created by pengy on 2019/4/2.
//

#include "model.h"
#include <stdio.h>

int YN(int cmd) {
    int re = 0;
    while (re != 1) {
        printf("确定要注册吗（Y/N）\n");
        char login;
        login = getchar();
        fflush(stdin);
        if (login == 'Y' || login == 'y') {
            cmd = 1;
            re = 1;
        }
        if (login == 'n' || login == 'N') {
            cmd = 0;
            re = 1;
        }
    }
    return cmd;
}

int click_username(char username[]){

}

int click_password(char password1[], char password2[]){

}

int login(char username[],char password[]){}
int regist(char *username, char *password, char *password2){
    if(click_password(password2,password)==0){
        printf("两次密码输入不一致，请重新输入");
        return 1;
    } else{
        if (click_username(username)==0){
            printf("用户名已存在");
            return 1;
        }
    }
}