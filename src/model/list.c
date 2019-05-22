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
    return 0;
}

int List_add(List list) {
    FILE *fp = NULL;
    fp = fopen(DB_LIST, "ab+");
    if (fp == NULL) {
        printf("文件打开失败，请联系管理员");
        return 0;
    }
    fwrite(&list, sizeof(list), 1, fp);
    fclose(fp);
    return 1;
}

int Good_add_list(List *list, Good *good, int counts) {//订单  商品  添加的商品数目
    for (int i = 0; i < list->count; i++) {
        if (list->good[i].id == good->id) {
            list->good[i].count += counts;
            return 2;
        }
    }
    Good_clone(&(list->good[list->count]), good);
    list->count++;
    return 1;
}

int Good_delate_list(List *list, Good good) {
    if (list->good[19].id == good.id) {
        Good *good1 = (Good *) malloc(sizeof(good));
        Good_clone(&list->good[20], good1);
    }
    for (int i = 0; i < 19; i++) {
        if (list->good[i].id == good.id) {
            for (int j = i; j < 19; j++) {
                Good_clone(&list->good[j], &list->good[j + 1]);
            }
            return 1;
        }
    }
    return 0;
}

int List_scarch(List *list, char username[]) {
    FILE *fp = NULL;
    fp = fopen(DB_USER, "ab+");
    if (fp == NULL) {
        printf("文件打开失败，请联系管理员");
        return USER_FAIL;
    }
    while (fread(list, sizeof(list), 1, fp)) {
        if (click_password(list->username, username)) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;

}