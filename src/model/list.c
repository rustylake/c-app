//
// Created by pengy on 2019/5/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <string.h>

#include "model/model.h"
#include "model/list.h"


int List_init(List *list, char username[]) {
    strcpy(list->username, username);
    char time[64];
    get_current_time(time);
    strcpy(list->time, time);
    list->count = 0;
    return LIST_SUCCESS;
}

int List_add(List list) {
    FILE *fp = NULL;
    fp = fopen(DB_LIST, "ab+");
    if (fp == NULL) {
        printf("文件打开失败，请联系管理员");
        return LIST_FAIL;
    }
    fwrite(&list, sizeof(list), 1, fp);
    fclose(fp);
    return LIST_SUCCESS;
}

int Good_add_list(List *list, Good *good, int counts) {//订单  商品  添加的商品数目
    for (int i = 0; i < list->count; i++) {
        if (list->good[i].id == good->id) {
            list->good[i].count += counts;
            list->good[i].total = list->good[i].outprize * list->good[i].count;
            return LIST_SUCCESS;
        }
    }
    good->count = counts;
    good->total = good->outprize * counts;
    Good_clone(&(list->good[list->count]), good);
    list->count++;
    return LIST_SUCCESS;
}

int Good_delate_list(List *list, int id) {
    if (list->good[list->count - 1].id == id) {
        list->count--;
    }
    for (int i = 0; i < list->count; i++) {
        if (list->good[i].id == id) {
            for (int j = i; j < list->count; j++) {
                Good_clone(&list->good[j], &list->good[j + 1]);
            }
            list->count--;
            return LIST_SUCCESS;
        }
    }
    return LIST_FAIL;
}

int List_scarch(List *list, char username[]) {
    FILE *fp = NULL;
    fp = fopen(DB_LIST, "rb+");
    if (fp == NULL) {
        printf("文件打开失败，请联系管理员");
        return LIST_FAIL;
    }
    while (fread(list, sizeof(List), 1, fp)) {
        if (click_password(list->username, username)) {
            fclose(fp);
            return LIST_SUCCESS;
        }
    }
    fclose(fp);
    return LIST_FAIL;

}