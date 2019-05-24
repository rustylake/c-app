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
#define VERSION "V1.3.0"//��ӹ��ﳵ
#define UNLOGIN "unlogin"

#include "model/user.h"
#include "model/list.h"

int YN(char[]);//����y����1��n����0
int click_password(char[], char[]);//������������Ƿ���ͬ,��ͬ����1
int click_username(User, char[]);//�����û����Ƿ����,���ڷ���0�������ڷ���1
int login(char[], char []);//��¼�ɹ�����1��ʧ�ܷ���2
int regist(User, char [], char [], char []);//ע��ɹ�����1��ʧ�ܷ���0
int users(void);//�г������û���Ϣ
int goods(void);//�г�������Ʒ��Ϣ
int show_head(char username[]);//������棬usernameΪUNLOGINʱ������û�
int get_current_time(char times[64]);//�õ���ǰʱ�䣬���ַ�����ʽ����times��
int List_goods_show(List list);//��ʾlist�е�������Ʒ
int lists();//�г����ж���
#endif //APP_MODEL_H
