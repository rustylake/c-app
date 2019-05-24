//
// Created by pengy on 2019/3/31.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "model/model.h"
#include "model/user.h"
#include "2/m22.h"


int m22_call_back(int cmd, User, char username[], char password[], char password2[]);

int m22_window_show(int cmd) {
    User user;
    char password2[256];
    show_head(UNLOGIN);
    printf("×¢²áÕË»§\n");
    printf("    ÇëÊäÈëÕËºÅ\n");
    fflush(stdin);
    gets(user.username);
    fflush(stdin);
    printf("\n    ÇëÊäÈëÃÜÂë\n");
    gets(user.password);
    fflush(stdin);
    printf("\n    ÇëÈ·ÈÏÃÜÂë\n");
    gets(password2);
    fflush(stdin);
    cmd = YN();
    cmd = m22_call_back(cmd, user, user.username, user.password, password2);
    return cmd;
}

int m22_call_back(int cmd, User user, char username[], char password[], char password2[]) {
    if (cmd == 0)return M22_EXIT;
    cmd = regist(user, username, password, password2);
    if (cmd == M22_SUCCESS)printf("\n×¢²á³É¹¦");
    if (cmd == M22_FAILD)printf("\n×¢²áÊ§°Ü£¬ÇëÖØÊÔ");
    printf("\n°´ÈÎÒâ¼ü¼ÌĞø");
    getch();
    return cmd;
}

int m22() {
    int cmd = CMD;
    cmd = m22_window_show(cmd);
    return cmd;
}
