//
// Created by pengy on 2019/5/3.
//

#include "model/goods.h"
#include "model/model.h"
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>

int Good_init(Good *good, char name[128], int count, int prize) {
    strcpy(good->name, name);
    good->prize = prize;
    good->count = count;
    good->total = good->count * good->prize;
    int id = -1;
    Good good1;
    good1.id = 0;
    FILE *fp = NULL;
    fp = fopen(DB_Good, "ab+");
    if (fp == NULL) {
        printf("文件打开失败，请联系管理员");
        return Good_FAIL;
    }
    if (!fread(&good1, sizeof(Good), 1, fp)) {
        fwrite(&good1, sizeof(Good), 1, fp);
    }
    fseek(fp, sizeof(Good) * -1, SEEK_END);
    fread(&good1, sizeof(Good), 1, fp);
    fclose(fp);
    good->id = good1.id + 1;
    return good->id;
}

int Good_add(Good Good) {
    FILE *fp = NULL;
    fp = fopen(DB_Good, "ab");
    if (fp == NULL) {
        printf("文件打开失败，请联系管理员");
        return Good_FAIL;
    }
    fwrite(&Good, sizeof(Good), 1, fp);
    fclose(fp);
    return 0;
}

int Good_clone(Good *Good1, Good *Good2) {
    if (Good1 == NULL || Good2 == NULL)
        return 0;
    strcpy(Good1->name, Good2->name);
    Good1->id = Good2->id;
    Good1->count = Good2->count;
    Good1->prize = Good2->prize;
    Good1->total = Good2->total;
    return 1;
}

int Good_change(int id, int c, int number) {
    if (c != Good_COUNT && c != Good_PRIZE)return 0;
    Good Good;
    FILE *fp = NULL;
    fp = fopen(DB_Good, "rb+");
    if (fp == NULL) {
        printf("文件打开失败，请联系管理员");
        return Good_FAIL;
    }
    while (fread(&Good, sizeof(Good), 1, fp)) {
        if (Good.id == id) {
            fseek(fp, sizeof(Good) * (-1), SEEK_CUR);
            switch (c) {
                case Good_COUNT:
                    Good.count = number;
                    break;
                case Good_PRIZE:
                    Good.prize = number;
                    break;
            }
            Good.total = Good_PRIZE * Good_COUNT;
            fflush(stdin);
            fwrite(&Good, sizeof(Good), 1, fp);
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int Good_change_Name(int id, char name[]) {
    Good Good;
    FILE *fp = NULL;
    fp = fopen(DB_Good, "rb+");
    if (fp == NULL) {
        printf("文件打开失败，请联系管理员");
        return Good_FAIL;
    }
    while (fread(&Good, sizeof(Good), 1, fp)) {
        if (Good.id == id) {
            fseek(fp, sizeof(Good) * (-1), SEEK_CUR);
            strcpy(Good.name, name);
            fflush(stdin);
            fwrite(&Good, sizeof(Good), 1, fp);
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;

}

int Good_getId(char name[]) {
    Good Good;
    FILE *fp = NULL;
    fp = fopen(DB_Good, "ab+");
    if (fp == NULL) {
        printf("文件打开失败，请联系管理员");
        return Good_FAIL;
    }
    while (fread(&Good, sizeof(Good), 1, fp)) {
        if (click_password(Good.name, name)) {
            fclose(fp);
            return 1;
        }
    }
    return Good.id;
}

int Good_view(Good *Good, int id) {
    FILE *fp = NULL;
    fp = fopen(DB_Good, "ab+");
    if (fp == NULL) {
        printf("文件打开失败，请联系管理员");
        return Good_FAIL;
    }
    while (fread(Good, sizeof(Good), 1, fp)) {
        if (Good->id == id) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
