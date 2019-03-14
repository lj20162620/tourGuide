#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "model.h"
#include "tool.h"
#include "palace.h"
#include "user.h"

/****************用户ID11，pw11*****************/
/****************管理员ID22，pw22*****************/
            void modifyPlace();
            int mainMenu();             //系统主界面
            void gotox(int x);          //调往第几行
            void showtime(int k);       //时间调用
            void addPalaceNode();       //增加景点信息
            void printPalace();         //输出所有景点信息
            void deletePalace();         //删除景点
            void search1();             //查询目标景点最优路线
            void search2();             //查询到所有景点最优路线
            void printCurrentPalace();  //输出当前景点信息


int main()
{
    int c=2;
    user a;
        while(c!=-1){
        c=mainMenu();
        switch(c){
            case 0:registe();
            case 1: a=login();
                    enterSystem(a.role,a.userId);
                    break;
            case -1:showtime(1);
                    exit(1);
        }
    }

    return 0;
}
