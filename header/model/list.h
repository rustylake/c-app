//
// Created by pengy on 2019/5/20.
//

#ifndef APP_LIST_H
#define APP_LIST_H

#include "model/goods.h"

struct List {
    char username[128];
    Good good[20];
    char time[64];
};
typedef struct List List;

int List_init(List *list, char username[]);//��ʼ��
int List_add(List list);//��¼����
int Good_add_list(List *list, Good *good, int count, int n);//�򶩵��������Ʒ
int Good_delate_list(List *list, Good good);//�Ӷ�����ɾ����Ʒ
int List_scarch(List *list, char[]);//�����û�����ѯ����
#endif //APP_LIST_H
