#define FINAL 5000 //5000表示无穷大
#define M 20 //表示最大顶点数
typedef int bool;//定义bool类型
#define TRUE 1
#define FALSE 0
//图信息结构体
typedef struct{
    int vexs[M];   //顶点信息域
    int edges[M][M]; //邻接矩阵
    int n,e; //图中顶点总数和边数
}Mgraph;

//景点信息结构体
typedef struct{
    char name[20];    //景点名称
    char descr[300];  //景点描述
    int status;      //景点状态
}palace;

/****************用户节点**********************/
struct usernode {
    char userId[11];  //用户ID
    char name[9];     //用户名称
    char passWord[11];//用户密码
    char phone[12];   //用户手机号码
    int save[M];      //储存用户旅游景点次数
    int role;         //用户角色
};
typedef struct usernode user;
//路径信息
/****************图中路径信息*******************/
typedef struct{
    int id1;
    int id2;
    int length;      //路径权重
}gra;

//路径信息
typedef struct{
    int a[2];   //边数，顶点数
    int b[20];
    gra c[50];
}gra1;
