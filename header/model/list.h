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

int List_init(List *list, char username[]);//初始化
int List_add(List list);//记录订单
int Good_add_list(List *list, Good *good, int count, int n);//向订单中添加商品
int Good_delate_list(List *list, Good good);//从订单中删除商品
int List_scarch(List *list, char[]);//根据用户名查询订单
#endif //APP_LIST_H
