//
// Created by pengy on 2019/5/20.
//

#ifndef APP_LIST_H
#define APP_LIST_H

#define LIST_SUCCESS 1
#define LIST_FAIL 0

#include "model/goods.h"

struct List {//这个名字不是很好。。。。   忘了链表也叫list了
    char username[128];
    int count;//商品种类的数量
    Good good[20];
    char time[64];
};
typedef struct List List;

int List_init(List *list, char username[]);//初始化,返回list_success
int List_add(List list);//记录订单，返回list_success,失败返回list_fail
int Good_add_list(List *list, Good *good, int count);//向订单中添加商品，成功返回list_success，失败返回list_fail
int Good_delate_list(List *list, int id);//从订单中删除id的商品,成功返回list_success
int List_scarch(List *list, char[]);//根据用户名，查询订单成功返回list_success，失败返回list_fail
#endif //APP_LIST_H
