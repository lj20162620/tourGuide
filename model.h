#define FINAL 5000 //5000��ʾ�����
#define M 20 //��ʾ��󶥵���
typedef int bool;//����bool����
#define TRUE 1
#define FALSE 0
//ͼ��Ϣ�ṹ��
typedef struct{
    int vexs[M];   //������Ϣ��
    int edges[M][M]; //�ڽӾ���
    int n,e; //ͼ�ж��������ͱ���
}Mgraph;

//������Ϣ�ṹ��
typedef struct{
    char name[20];    //��������
    char descr[300];  //��������
    int status;      //����״̬
}palace;

/****************�û��ڵ�**********************/
struct usernode {
    char userId[11];  //�û�ID
    char name[9];     //�û�����
    char passWord[11];//�û�����
    char phone[12];   //�û��ֻ�����
    int save[M];      //�����û����ξ������
    int role;         //�û���ɫ
};
typedef struct usernode user;
//·����Ϣ
/****************ͼ��·����Ϣ*******************/
typedef struct{
    int id1;
    int id2;
    int length;      //·��Ȩ��
}gra;

//·����Ϣ
typedef struct{
    int a[2];   //������������
    int b[20];
    gra c[50];
}gra1;
