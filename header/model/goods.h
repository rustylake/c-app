//
// Created by pengy on 2019/5/3.
//

#ifndef APP_GOODS_H
#define APP_GOODS_H
#define Good_FAIL 2
#define Good_NAME 20
#define Good_COUNT 30
#define Good_PRIZE 40
#define GOOD_TOTLE 50
struct Good {
    int id;
    char name[128];
    int count;
    int prize;
    int total;
};
typedef struct Good Good;

int Good_init(Good *good, char name[128], int count, int prize);//��ʼ����Ʒ������id
int Good_clone(Good *Good1, Good *Good2);//��Good2���Ƶ�Good1 �ɹ�����1 ʧ�ܷ���0
int Good_add(Good);//������Ʒ
int Good_change_Name(int id, char name[]);//����id����name
int Good_change(int id, int c, int number);//����id����Ʒ��c������ݸ�Ϊnumber���ɹ�����1��ʧ�ܷ���0
int Good_view(Good *, int id);//����id������Ʒ ���ҳɹ�����1 ʧ�ܷ���0
int Good_getId(char name[]);//����name��ѯid

#endif //APP_GOODS_H
