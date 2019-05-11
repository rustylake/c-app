//
// Created by pengy on 2019/4/21.
//

#ifndef APP_USER_H
#define APP_USER_H
#define USER_FAIL 2
#define USER_PASSWORD 20
#define USER_QUESTION 30
#define USER_AN 40

struct User {
    char username[128];
    char password[128];
    char question[128];
    char an[128];
};
typedef struct User User;

/***********************************************/

int User_clone(User *user1, User *user2);//将user2复制到user1 成功返回1 失败返回0
int User_add(User);//增加用户
int User_change(char username[], int, char[]);//将username的用户int项的内容改为char，成功返回1，失败返回0
int User_scarch(User *user, char username[]);//查 查找成功返回1 失败返回0
#endif //APP_USER_H
