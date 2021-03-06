//
// Created by pengy on 2019/5/3.
//

#ifndef APP_GOODS_H
#define APP_GOODS_H

#define Good_FAIL 0
#define Good_NAME 20
#define Good_COUNT 30
#define Good_INPRIZE 40
#define GOOD_TOTLE 50
#define Good_OUTPRIZE 60

struct Good {
    int id;//商品代码
    char name[128];//商品名称
    int count;//商品库存
    int inprize;//进货价格
    int outprize;//售价
    int total;//库存商品总价值
};
typedef struct Good Good;

int Good_init(Good *good, char name[128], int count, int inprize, int outprize);//初始化商品，返回id，失败返回Good_fail
int Good_clone(Good *Good1, Good *Good2);//将Good2复制到Good1 成功返回1 失败返回Good_fail
int Good_add(Good);//增加商品,成功返回1，失败返回Good_fail
int Good_change_Name(int id, char name[]);//根据id更改name，成功返回0，失败返回Good_fail
int Good_change(int id, int c, int number);//根据id将商品第c项的内容改为number，成功返回1，失败返回Good_fail
int Good_scarch(Good *good, int id);//根据id查找商品 查找成功返回1 失败返回Good_fail
int Good_getId(char name[]);//根据name查询id,查找成功返回id 失败返回Good_fail
int Good_delate(int id);//删除指定id的商品

#endif //APP_GOODS_H
