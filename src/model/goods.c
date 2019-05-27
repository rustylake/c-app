//
// Created by pengy on 2019/5/3.
//
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>

#include "model/model.h"
#include "model/goods.h"


int Good_init(Good *good, char name[128], int count, int inprize, int outprize) {
    strcpy(good->name, name);
    good->inprize = inprize;
    good->count = count;
    good->total = good->count * good->inprize;
    good->outprize = outprize;
    int id;
    Good good1;//用于查找最后一个id
    FILE *fp = NULL;
    fp = fopen(DB_Good, "ab+");
    if (fp == NULL) {
        printf("文件打开失败，请联系管理员");
        return Good_FAIL;
    }
    if (!fread(&good1, sizeof(Good), 1, fp)) {
        good->id = 1;
    } else {
        fseek(fp, sizeof(Good) * -1, SEEK_END);
        fread(&good1, sizeof(Good), 1, fp);
        good->id = good1.id + 1;
    }
    fclose(fp);
    return good->id;
}

int Good_add(Good Good) {
    FILE *fp = NULL;
    fp = fopen(DB_Good, "ab+");
    if (fp == NULL) {
        printf("文件打开失败，请联系管理员");
        return Good_FAIL;
    }
    fwrite(&Good, sizeof(Good), 1, fp);
    fclose(fp);
    return 1;
}

int Good_clone(Good *Good1, Good *Good2) {
    if (Good1 == NULL || Good2 == NULL)
        return Good_FAIL;
    strcpy(Good1->name, Good2->name);
    Good1->id = Good2->id;
    Good1->count = Good2->count;
    Good1->inprize = Good2->inprize;
    Good1->total = Good2->total;
    Good1->outprize = Good2->outprize;
    return 1;
}

int Good_change(int id, int c, int number) {
    if (c != Good_COUNT && c != Good_INPRIZE && c != Good_OUTPRIZE)//检查参数
        return 0;
    Good Good;
    FILE *fp = NULL;
    fp = fopen(DB_Good, "rb+");
    if (fp == NULL) {
        printf("文件打开失败，请联系s管理员");
        return Good_FAIL;
    }
    while (fread(&Good, sizeof(Good), 1, fp)) {
        if (Good.id == id) {            //查找
            fseek(fp, sizeof(Good) * (-1), SEEK_CUR);
            switch (c) {
                case Good_COUNT:
                    Good.count = number;
                    break;
                case Good_INPRIZE:
                    Good.inprize = number;
                    break;
                case Good_OUTPRIZE:
                    Good.outprize = number;
                    break;
            }
            Good.total = Good.inprize * Good.count;//更改总价
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
    if (fseek(fp, sizeof(Good) * (id - 1), SEEK_SET) == -1)//玄学问题可能失效，根据id移动指针
        return Good_FAIL;
    fread(&Good, sizeof(Good), 1, fp);
    if (Good.id == id) {
        fseek(fp, sizeof(Good) * (-1), SEEK_CUR);
        strcpy(Good.name, name);
        fflush(stdin);
        fwrite(&Good, sizeof(Good), 1, fp);
        fclose(fp);
        return 1;
    }
    fclose(fp);//商品不存在
    return Good_FAIL;
}

int Good_getId(char name[]) {
    Good Good;
    FILE *fp = NULL;
    fp = fopen(DB_Good, "rb+");
    if (fp == NULL) {
        printf("文件打开失败，请联系管理员");
        return Good_FAIL;
    }
    while (fread(&Good, sizeof(Good), 1, fp)) {
        if (click_password(Good.name, name)) {
            fclose(fp);
            return Good.id;
        }
    }
    fclose(fp);
    return Good_FAIL;
}

int Good_scarch(Good *good, int id) {
    FILE *fp = NULL;
    fp = fopen(DB_Good, "rb+");
    if (fp == NULL) {
        printf("文件打开失败，请联系管理员");
        return Good_FAIL;
    }
    if (fseek(fp, sizeof(Good) * (id - 1), SEEK_SET) == -1)
        return Good_FAIL;
    fread(good, sizeof(Good), 1, fp);
    fclose(fp);
    if (good->id == id)
        return 1;
    else
        return Good_FAIL;
}

int Good_delate(int id) {
    Good good;
    FILE *fp = NULL;
    fp = fopen(DB_Good, "rb+");
    if (fp == NULL) {
        printf("文件打开失败，请联系管理员");
        return USER_FAIL;
    }
    FILE *newfp = NULL;//临时文件
    newfp = fopen("../goods1.db", "rb+");
    if (newfp == NULL) {
        printf("文件打开失败，请联系管理员");
        return USER_FAIL;
    }

    while (fread(&good, sizeof(Good), 1, fp)) {
        if (good.id == id) {            //跳过
            while (fread(&good, sizeof(Good), 1, fp)) {
                good.id--;//更改id
                fwrite(&good, sizeof(Good), 1, newfp);
            }
            break;
        }
        fwrite(&good, sizeof(Good), 1, newfp);
    }
    fclose(fp);
    fclose(newfp);
    system("del ..\\goods.db");//删除源文件
    system("rename ..\\goods1.db goods.db");//重命名
    return 1;
}
