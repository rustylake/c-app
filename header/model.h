//
// Created by pengy on 2019/4/2.
//

#ifndef APP_MODEL_H
#define APP_MODEL_H

#include "m22.h"

#define DB_USER "../yhm"

int YN(void);//输入y返回1，n返回0
int click_password(char[], char[]);//检查两次密码是否相同,相同返回1
int click_username(char[]);//检验用户名是否存在
int login(char[], char []);//登录成功返回1，失败返回2
int regist(char [], char [], char []);//注册成功返回1，失败返回0
#endif //APP_MODEL_H
