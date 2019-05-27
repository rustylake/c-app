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
    int id;//��Ʒ����
    char name[128];//��Ʒ����
    int count;//��Ʒ���
    int inprize;//�����۸�
    int outprize;//�ۼ�
    int total;//�����Ʒ�ܼ�ֵ
};
typedef struct Good Good;

int Good_init(Good *good, char name[128], int count, int inprize, int outprize);//��ʼ����Ʒ������id��ʧ�ܷ���Good_fail
int Good_clone(Good *Good1, Good *Good2);//��Good2���Ƶ�Good1 �ɹ�����1 ʧ�ܷ���Good_fail
int Good_add(Good);//������Ʒ,�ɹ�����1��ʧ�ܷ���Good_fail
int Good_change_Name(int id, char name[]);//����id����name���ɹ�����0��ʧ�ܷ���Good_fail
int Good_change(int id, int c, int number);//����id����Ʒ��c������ݸ�Ϊnumber���ɹ�����1��ʧ�ܷ���Good_fail
int Good_scarch(Good *good, int id);//����id������Ʒ ���ҳɹ�����1 ʧ�ܷ���Good_fail
int Good_getId(char name[]);//����name��ѯid,���ҳɹ�����id ʧ�ܷ���Good_fail
int Good_delate(int id);//ɾ��ָ��id����Ʒ

#endif //APP_GOODS_H
