//
// Created by pengy on 2019/4/2.
//

#ifndef APP_MODEL_H
#define APP_MODEL_H

#include "2/m22.h"
#include "user.h"
#include "goods.h"

#define DB_USER "../users.db"
#define DB_Good "../0goods.db"
#define CMD 999
#define VERSION "V1.1.2"

int YN(void);//输入y返回1，n返回0
int click_password(char[], char[]);//检查两次密码是否相同,相同返回1
int click_username(User, char[]);//检验用户名是否存在,存在返回0，不存在返回1
int login(char[], char []);//登录成功返回1，失败返回2
int regist(User, char [], char [], char []);//注册成功返回1，失败返回0
#endif //APP_MODEL_H
