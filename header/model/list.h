//
// Created by pengy on 2019/5/20.
//

#ifndef APP_LIST_H
#define APP_LIST_H

#define LIST_SUCCESS 1
#define LIST_FAIL 0

#include "model/goods.h"

struct List {//������ֲ��Ǻܺá�������   ��������Ҳ��list��
    char username[128];
    int count;//��Ʒ���������
    Good good[20];
    char time[64];
    int money;
};
typedef struct List List;

int List_init(List *list, char username[]);//��ʼ��,����list_success
int List_add(List list);//��¼����������list_success,ʧ�ܷ���list_fail
int Good_add_list(List *list, Good *good, int count);//�򶩵��������Ʒ���ɹ�����list_success��ʧ�ܷ���list_fail
int Good_delate_list(List *list, int id);//�Ӷ�����ɾ��id����Ʒ,�ɹ�����list_success
int List_scarch(List *list, char[]);//�����û�������ѯ�����ɹ�����list_success��ʧ�ܷ���list_fail
#endif //APP_LIST_H
