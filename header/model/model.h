//
// Created by pengy on 2019/4/2.
//

#ifndef APP_MODEL_H
#define APP_MODEL_H

#define DB_LIST "../list.db"
#define DB_USER "../users.db"
#define DB_Good "../goods.db"
#define CMD 999
#define LOGIN 1
#define VERSION "V1.2.2"//添加购物车
#define UNLOGIN "unlogin"

#include "model/user.h"
#include "model/list.h"

int YN(void);//输入y返回1，n返回0
int click_password(char[], char[]);//检查两次密码是否相同,相同返回1
int click_username(User, char[]);//检验用户名是否存在,存在返回0，不存在返回1
int login(char[], char []);//登录成功返回1，失败返回2
int regist(User, char [], char [], char []);//注册成功返回1，失败返回0
int users(void);//列出所有用户信息
int goods(void);//列出所有商品信息
int show_head(char username[]);//输出界面，username为UNLOGIN时不输出用户
int get_current_time(char times[64]);//得到当前时间，以字符串形式输入times中
int List_goods_show(List list);//显示list中的所有商品
int lists();//列出所有订单
#endif //APP_MODEL_H
