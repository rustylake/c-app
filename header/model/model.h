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

int YN(void);//����y����1��n����0
int click_password(char[], char[]);//������������Ƿ���ͬ,��ͬ����1
int click_username(User, char[]);//�����û����Ƿ����,���ڷ���0�������ڷ���1
int login(char[], char []);//��¼�ɹ�����1��ʧ�ܷ���2
int regist(User, char [], char [], char []);//ע��ɹ�����1��ʧ�ܷ���0
#endif //APP_MODEL_H
