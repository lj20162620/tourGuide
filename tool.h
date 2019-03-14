
/*************跳往第几行******************/

void gotox(int x)      //前往第几行
{
    int i;
    for(i=1;i<x;i++)
        printf("\n");
}
/**************写入图txt信息*******************/
int writeTxtInfornationToFile(gra1 *gra,char *f,int n){
    int k;

    FILE *fp=fopen(f,"w");
    if(fp!=NULL){
        fprintf(fp,"%d",gra->a[0]);
        fprintf(fp," %d",gra->a[1]);
        for(k=0;k<gra->a[0];k++){
             fprintf(fp," %d",gra->b[k]);
        }
        for(k=0;k<gra->a[1];k++){
             fprintf(fp," %d",gra->c[k].id1);
             fprintf(fp," %d",gra->c[k].id2);
             fprintf(fp," %d",gra->c[k].length);
        }
        fclose(fp);
        return k;
    }
    else{
        printf("文件保存失败！\n");
        return -1;
    }
}

/**************读取图txt信息*******************/
gra1 readTxtInfornatioFromFile(gra1 gra){
    int k;

    FILE *fp=fopen("palacegra.txt","r");
    if(fp!=NULL){
        fscanf(fp,"%d%d",&gra.a[0],&gra.a[1]);  //读入图得顶点数和边数
        for(k=0;k<gra.a[0];k++)
            fscanf(fp,"%d",&gra.b[k]);  //读入顶点信息域

        for(k=0;k<gra.a[1];k++){   //读入边
            fscanf(fp,"%d%d%d",&gra.c[k].id1,&gra.c[k].id2,&gra.c[k].length);
        }
        fclose(fp);   //关闭文件
    }
    return gra;
}

/****************显示当前时间**************/
/*
   @函数名称：showtime    入口参数：int k

   @函数功能：显示时间与欢迎界面
*/
void showtime(int k)
{
    time_t nowtime;
    struct tm *t;
    time(&nowtime);
    t=localtime(&nowtime);
    if(t->tm_hour>=5&&t->tm_hour<12)
         printf("上午好 ！ \n");
    else
          if(t->tm_hour>=12&&t->tm_hour<18)
            printf("下午好 ！ \n");
              else
                printf("晚上好 ！ \n");
    switch(k)
    {
        case 0 : printf("欢迎使用故宫旅游导航系统 ！");
        printf("\t 当前时间 ： %s", ctime(&nowtime));  break;
        case 1 : printf("\t 谢谢使用故宫旅游导航系统 ！");
        printf("\t 当前时间 ： %s", ctime(&nowtime));     break;
    }
}

/**************文件尾部写入景点信息结构体*******************/
int writePalaceAfterFile(palace s[],char *f,int n){
    int k;

    FILE *fp=fopen(f,"ab+");
    if(fp!=NULL){
        k = fwrite(s,sizeof(palace),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("文件保存失败！\n");
        return -1;
    }
}

/****************建立图的邻接矩阵存储结构******************/
//*g为指向邻接矩阵的指针
//*s指向文件名
void creat(Mgraph *g,char *s){
    int i,j,k,w;
    FILE *fp;
    fp = fopen(s,"r");//读取文件信息
    if(fp!=NULL){
        fscanf(fp,"%d%d",&g->n,&g->e);  //读入图得顶点数和边数
        for(i=0;i<g->n;i++)
            fscanf(fp,"%d",&g->vexs[i]);  //读入顶点信息域
        for(i=0;i<g->n;i++)//初始化邻接矩阵
            for(j=0;j<g->n;j++)
                if(i==j) g->edges[i][j]=0;
                else g->edges[i][j]=FINAL;
        for(k=0;k<g->e;k++){   //读入边
            fscanf(fp,"%d%d%d",&i,&j,&w);
            g->edges[i-1][j-1] = w;    //建立无向图邻接矩阵
            g->edges[j-1][i-1] = w;
        }
        fclose(fp);   //关闭文件
    }
    else g->n=0;  //没有打开文件，没有顶点；
}

/***************从palace.dat读取景点结构体信息********************/
int readPalaceFromFile(palace palaceArray[], char *f){
    FILE *fp;
    int counter=0,k;

    fp = fopen(f,"rb");
    if(fp !=NULL){
        while(1){
            k = fread(palaceArray + counter,sizeof(palace),1,fp);
            if(k == 1){
                counter++;
            }else{
                 break;
           }
        }
        fclose(fp);
        return counter;//返回读取个数
    }else{
        printf("文件读取失败!");
        return 0;
    }
}

/**************重新写入景点*******************/
int writePalaceToFile(palace palaceArray[],char *f,int n){
    int k;

    FILE *fp=fopen(f,"wb");
    if(fp!=NULL){
        k = fwrite(palaceArray,sizeof(palace),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("文件保存失败！\n");
        return -1;
    }
}

/****************登录界面******************/
int mainMenu(){
    int c;

    system("cls"); gotox(6);
    printf("\t\t\t\t\t            故宫旅游导航系统\n");
    printf("\t\t\t\t\t====================================\n");
    printf("\t\t\t\t\t*           1 登陆系统             *\n");
    printf("\t\t\t\t\t*           0 新用户注册系统       *\n");
    printf("\t\t\t\t\t*          -1 退出系统             *\n");
    printf("\t\t\t\t\t====================================\n");
    printf("\t\t\t\t\t请输入选项[ ]\b\b");
    scanf("%d",&c);
    return c;
}

/****************用户登录界面******************/
int menuUser(){

    int c;
    gotox(5);
    printf("\t\t\t                          故宫旅游导航系统\n");
    printf("\t\t\t===============================================================\n");
    printf("\t\t\t*                       1   查询所有景点信息                  *\n");
    printf("\t\t\t*                       2   查询目标景点最优路线              *\n");
    printf("\t\t\t*                       3   查询所有目标最短路径              *\n");
    printf("\t\t\t*                       4   智能推荐路线                      *\n");
    printf("\t\t\t*                       0   退出                              *\n");
    printf("\t\t\t===============================================================\n");
    printf("\t\t\t请输入选项[ ]\b\b");
    scanf("%d",&c);
    return c;
}

/****************管理员登录界面******************/
int menuAdmin(){

    int c;
    gotox(5);
    printf("\t\t\t                          故宫旅游导航系统\n");
    printf("\t\t\t===============================================================\n");
    printf("\t\t\t*                       1   查询所有景点信息                  *\n");
    printf("\t\t\t*                       2   查询目标景点最优路线              *\n");
    printf("\t\t\t*                       3   查询所有目标最短路径              *\n");
    printf("\t\t\t*                       4   修改路径信息                      *\n");
    printf("\t\t\t*                       5   智能推荐路线                      *\n");
    printf("\t\t\t*                       6   增加景点信息                      *\n");
    printf("\t\t\t*                       7   删除景点信息                      *\n");
    printf("\t\t\t*                       0   退出                              *\n");
    printf("\t\t\t===============================================================\n");
    printf("\t\t\t请输入选项[ ]\b\b");
    scanf("%d",&c);
    return c;
}

/***************从user.dat读取用户信息********************/
int readUserFromFile(user userArray[], char *f){
    FILE *fp;
    int counter=0,k;

    fp = fopen(f,"rb");
    if(fp !=NULL){
        while(1){
            k = fread(userArray + counter,sizeof(user),1,fp);
            if(k == 1){
                counter++;
            }else{
                 break;
           }
        }
        fclose(fp);
        return counter;//返回读取个数
    }else{
        printf("文件读取失败!");
        return 0;
    }
    return -1;
}

/*********查询用户***************/
int userSearch(user userArray[],int userTotal,char id[]){
    	int i;
    	for(i = 0;i < userTotal;i++){
    		if(strcmp(id,userArray[i].userId) == 0){
    			return i;
    		}
    	}
     return -1;
}

/**************密码加密*******************/
void encryption(char password[]){
    int i = 0;
    while(password[i] != '\0'){
        password[i] = password[i]^0xba;
        i++;
    }
}

/***************密码解密***************************/
void decryption(char password[]){
    int i = 0;
    while(password[i] != '\0'){
        password[i] = password[i]^0xba;
        i++;
    }
}

/**************文件尾部写入用户*******************/
int writeUserAfterFile(user s[],char *f,int n){
    int k;

    FILE *fp=fopen(f,"ab+");
    if(fp!=NULL){
        k = fwrite(s,sizeof(user),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("文件保存失败！\n");
        return -1;
    }
}


/**************重新写入用户*******************/
int writeUserToFile(user userArray[],char *f,int n){
    int k;

    FILE *fp=fopen(f,"wb");
    if(fp!=NULL){
        k = fwrite(userArray,sizeof(user),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("文件保存失败！\n");
        return -1;
    }
}


/***************从文件中删除用户******************/
int deleteUserFromFile(user userDeleteArray[],int n){
    user userArray[50];
    int userTotal;
    int i,j,k;

    userTotal = readUserFromFile(userArray,"user.dat");
    for(i = 0;i < n;i++){
        for(j = 0;j < userTotal;j++){
            if(strcmp(userDeleteArray[i].userId,userArray[j].userId)==0){
                for(k = j + 1;k < userTotal;k++){
                    userArray[k - 1] = userArray[k];
                }
                userTotal--;
                break;
            }
        }
    }
    writeUserToFile(userArray,"user.dat",userTotal);
    return userTotal;
}

/*****************根据id加载user**************************/
user loadUserById(char userId[]){
    user p;
    user userArray[100];
    int userTotal;
    int i;


    userTotal = readUserFromFile(userArray,"user.dat");
    for(i = 0;i < userTotal;i++){

        if(strcmp(userArray[i].userId,userId)==0){
            p = userArray[i];
            break;
        }
    }
    if(i == userTotal){
        printf("找不到账号为%s的数",userId);
        exit(-1);
    }
    return p;

}


int I = 1; //定义当前景点序号，全局变量
/*********************输出当前景点信息***************************/
void printCurrentPalace(){
    palace palaceArray[M];
    int palaceTotal;
    palace currentPalace;
    palaceTotal = readPalaceFromFile(palaceArray,"palace.dat");
    palaceTotal--;
    currentPalace = palaceArray[I-1];
    printf("\n你当前所在景点：(%d)%s\n",I,currentPalace.name);
}
/*********************将更新的图的信息写入文件**********************/
//存入顶点总数与边总数
void saveArraytxt(int t[],char *f,int n){  //t,存入的数组 f 文件名 n 数量
   // int i=0;
    FILE *fp=fopen(f,"w");
     if(fp!=NULL){

           fprintf(fp," %d",t[0]);
           fprintf(fp," %d",t[1]);
            fclose(fp);
    }
    else{
        printf("文件保存失败！\n");
    }

}
//存入顶点序号


//存入边的信息
void saveStructtxt(gra sgra[],char *f,int n){    //将图的边结点权重信息存入文件
    int i=0;
    FILE *fp=fopen(f,"w");
    if(fp!=NULL){
            for(i=0;i<n;i++)
        {
            fprintf(fp,"%2d",sgra[i].id1);
            fprintf(fp,"%2d",sgra[i].id2);
            fprintf(fp,"%2d",sgra[i].length);

        }
fclose(fp);
    }
    else{
        printf("文件保存失败！\n");
    }

}
/*************删除景点信息******************/

void deletePalaceInformation(int i)      //前往第几行
{
    int k;
    palace palaceArray[M];
    int palaceTotal;

    palaceTotal = readPalaceFromFile(palaceArray,"palace.dat");
    system("cls");    //清除屏幕
    showtime(0);
    printCurrentPalace(); //输出当前景点信息
    gotox(6);

    for(k = i;k < palaceTotal;k++){
        palaceArray[k - 1] = palaceArray[k];
    }
    palaceTotal--;
    writePalaceToFile(palaceArray,"palace.dat",palaceTotal);
}
