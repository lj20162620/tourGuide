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

/****************�û�ID11��pw11*****************/
/****************����ԱID22��pw22*****************/
            void modifyPlace();
            int mainMenu();             //ϵͳ������
            void gotox(int x);          //�����ڼ���
            void showtime(int k);       //ʱ�����
            void addPalaceNode();       //���Ӿ�����Ϣ
            void printPalace();         //������о�����Ϣ
            void deletePalace();         //ɾ������
            void search1();             //��ѯĿ�꾰������·��
            void search2();             //��ѯ�����о�������·��
            void printCurrentPalace();  //�����ǰ������Ϣ


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
