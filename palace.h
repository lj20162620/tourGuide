typedef int bool;
#define TRUE 1
#define FALSE 0
/*******更改printgrd1********/
/*********************/

            void chanStatus(palace p[],int index,int pa);    //修改景点状态信息
            void changeWays();                               //修改路径信息

/*************************修改路径信息**********************/
void modifyPlace(){
    palace palaceArray[M];
    int palaceTotal;
    palaceTotal = readPalaceFromFile(palaceArray,"palace.dat");
    showtime(0);
    int c,i;
    gotox(5);
    int j=0;
          gotox(5);
    printf("\t\t\t             故宫旅游导航系统->修改路径信息\n");
    printf("\t\t\t===============================================================\n");
    printf("\t\t\t*                       1   更改景点状态                      *\n");
    printf("\t\t\t*                       2   更改目标景点路径                  *\n");
    printf("\t\t\t*                       0   退出                              *\n");
    printf("\t\t\t===============================================================\n");
    printf("\t\t\t请输入选项[ ]\b\b");
    scanf("%d",&c);
    switch(c){
        case 1:system("cls");
                    while(j<palaceTotal){
                        printf("\t\t\t    景点序号：%d\n",j+1);
                        printf("\t\t\t    景点名称：%s\n",palaceArray[j].name);
                        if(palaceArray[j].status == 1)
                            printf("\t\t\t    状态：开放中");
                        else
                            printf("\t\t\t    状态：关闭中");
                            gotox(3);
                            j++;
                        }
                    printf("\t\t\t    请输入要操作的景点序号:");
                    scanf("%d",&i);
                if(i<0||i>palaceTotal)
                    {printf("\n\t\t\t    对不起，该景点不存在"); system("pause");}
                else
                    chanStatus(palaceArray,i-1,palaceTotal);
                 break;
        case 2:system("cls");
                    while(j<palaceTotal){
                        printf("\t\t\t    景点序号：%d\n",j+1);
                        printf("\t\t\t    景点名称：%s\n",palaceArray[j].name);
                        if(palaceArray[j].status == 1)
                            printf("\t\t\t    状态：开放中");
                        else
                            printf("\t\t\t    状态：关闭中");
                            gotox(3);
                            j++;
                        }
                 changeWays();
                 break;
        default:
                 break;

    }


}
/**********************修改景点状态************************/
void chanStatus(palace p[],int index,int pa){
    system("cls");
    gotox(4);
    printf("***********修改景点状态*************\n");
    int ch;
    printf("您选择了：%s \n",p[index].name);
    if(p[index].status==1){
        printf("该景点处于开放状态 \n 是否将其关闭？\n");
        printf("1 : 关闭 \t 0 : 离开\n");
        printf("请选择[ ]\b\b");
        scanf("%d",&ch);
        if(ch == 1){
             p[index].status = 0;
             printf("该景点已设为关闭状态！");
        }
        system("pause");
    }
    else{
        printf("该景点处于关闭状态 \n 是否将其打开？\n");
        printf("1 : 打开 \t 0 : 离开\n");
        printf("请选择[ ]\b\b");
        scanf("%d",&ch);
        if(ch == 1){
             p[index].status = 1;
             printf("该景点已设为开放状态！");
        }
        system("pause");
    }
    writePalaceToFile(p,"palace.dat",pa);
}
/*********************修改路径信息***************************/
void changeWays(){
    int i,ch,l,b;
    gra1 newgra;
    newgra = readTxtInfornatioFromFile(newgra);
    int sta,fin;
    printf("请输入要操作的起始景点序号 : ");
    scanf("%d",&sta);
    printf("请输入要操作的结束景点序号 : ");
    scanf("%d",&fin);
    for(i=0;i<newgra.a[1];i++){
            if(((newgra.c[i].id1 == sta&&newgra.c[i].id2 == fin)||(newgra.c[i].id2 == sta&&newgra.c[i].id1 == fin))&&newgra.c[i].length != 0)
                    {
                        printf("此两点之间存在路径 ！ 长度为 ：%d\n",newgra.c[i].length);
                        printf("是否将此路径关闭？ 1：关闭   0：离开\n");
                        scanf("%d",&ch);
                        if(ch==1){
                            newgra.a[1]--;
                            newgra.c[i].id1 = 0;
                            newgra.c[i].id2 = 0;
                            newgra.c[i].length = 0;
                            printf("两景点间线路已关闭！\n");
                            i=0;break;
                        }
                        else system("pause");
                    }
        }
                   if(i>=newgra.a[1]) {
                   printf("此两点之间不存在路径 ！ \n");
                   printf("是否将该条路径打开？ 1：打开  0：离开\n");
                   scanf("%d",&ch);
                   if(ch==1)  {

                                printf("请输入该路径的长度：");
                                scanf("%d",&l);
                                newgra.c[newgra.a[1]].id1=sta;
                                newgra.c[newgra.a[1]].id2=fin;
                                newgra.c[newgra.a[1]].length=l;
                                newgra.a[1]++;
                                printf("已开通两景点之间的线路\n");
                                system("pause");
                             }
                   else   system("pause");

             }


     b = writeTxtInfornationToFile(&newgra,"palacegra.txt",1);
     b--;

}
/*********************删除景点***************************/
void deletePalace(){
    int i = 0;
    int k = 0;
    int g = 0;
    int b;
    gra1 gra;

    palace palaceArray[M];
    int palaceTotal;
    palaceTotal = readPalaceFromFile(palaceArray,"palace.dat");

    while(i<palaceTotal){
        printf("\t\t\t    景点序号：%d\n",i+1);
        printf("\t\t\t    景点名称：%s\n",palaceArray[i].name);
        if(palaceArray[i].status == 1)
            printf("\t\t\t    状态：开放中");
        else
            printf("\t\t\t    状态：关闭中");
        gotox(3);
        i++;
    }
    gra = readTxtInfornatioFromFile(gra);
    printf("\t\t\t    输入要删除的景点序号:");

    scanf("%d",&i);

    I = 1;//改变起点位置下标
    deletePalaceInformation(i);
    gra.b[i-1] = 0;
    for(k = 0; k < gra.a[1]; k++){
        if(gra.c[k].id1 == i){
            gra.c[k].id1 = 0;
            gra.c[k].id2 = 0;
            gra.c[k].length = 0;
            g++;
        }
    }
    gra.a[0]--;
    gra.a[1] = gra.a[1] - g;
    b = writeTxtInfornationToFile(&gra,"palacegra.txt",1);
     if(b!=-1){
        printf("删除成功，按1离开");
     }
     scanf("%d",&b);
     if(b==1)
        return ;
}

/****************增加景点信息******************/
void addPalaceNode(){
     palace newpalace[1];
     gra1 gra;
     int a,i,j,b=0;
     a=0;
     i=0;
     j=0;

    palace palaceArray[M];
    int palaceTotal;
    palaceTotal = readPalaceFromFile(palaceArray,"palace.dat");
    while(i<palaceTotal){
        printf("\t\t\t    景点序号：%d\n",i+1);
        printf("\t\t\t    景点名称：%s\n",palaceArray[i].name);
        if(palaceArray[i].status == 1)
            printf("\t\t\t    状态：开放中");
        else
            printf("\t\t\t    状态：关闭中");
        gotox(3);
        i++;
    }
     gra = readTxtInfornatioFromFile(gra);
     while(a==0){
        gotox(6);
         printf("\t\t\t    输入增加景点名称：");
         scanf("%s",newpalace[0].name);

         gotox(6);
         printf("\t\t\t    输入增加景点信息：");
         scanf("%s",newpalace[0].descr);

         gotox(6);
         printf("\t\t\t    输入增加景点是否开放：");
         scanf("%d",&newpalace[0].status);
         printf("\n\n");


        j = gra.a[1];
        printf("\t\t\t    请输入景点路径信息，如从当前景点到景点1，则输入1 300");
        while(i!=1){
                 gra.c[j].id1 = gra.a[0]+1;
                 printf("\n\t\t\t    景点序号：");
                 scanf("%d",&gra.c[j].id2);
                 printf("\n\t\t\t    到该景点距离：");
                 scanf("%d",&gra.c[j].length);
                 j++;
                 printf("\n\t\t\t    结束输入请按1，否则继续输入：");
                 scanf("%d",&i);
            }


        printf("\t\t\t    确认：[1]\n");
        printf("\t\t\t重新输入：[0]\n");
        printf("\t\t\t  请选择: [ ]\b\b");
        scanf("%d",&a);
     }



     gra.b[gra.a[0]] = gra.a[0]+1;
     gra.a[0]++;
     gra.a[1] = j;
     b = writeTxtInfornationToFile(&gra,"palacegra.txt",1);
     b = writePalaceAfterFile(newpalace,"palace.dat",1);
     if(b!=-1){
        printf("增加成功，按1离开");
     }
     scanf("%d",&b);
     if(b==1)
        return;
}


/*********************输出景点信息***************************/
void printPalace(){
    palace palaceArray[M];
    int palaceTotal;
    int i=0;
    int a=0;
    palaceTotal = readPalaceFromFile(palaceArray,"palace.dat");
    system("cls");    //清除屏幕
    showtime(0);
    printCurrentPalace(); //输出当前景点信息
    gotox(6);
    if(palaceTotal == 0)
        printf("没有景点了\n");
    while(i<palaceTotal){
        printf("景点序号：%d\n",i+1);
        printf("景点名称：%s\n",palaceArray[i].name);
        printf("景点信息：%s\n",palaceArray[i].descr);
        if(palaceArray[i].status == 1)
            printf("状态：开放中");
        else printf("状态：暂不开放");
        gotox(6);
        i++;
    }
    gotox(3);
    printf("\n\t\t\t    按1离开：");
    scanf("%d",&a);
    if(a == 1)
        return;
}

/*********************Dijkstra算法求解单源最短路径***************************/
//参数：图的邻接矩阵g
//源点V0
//路径向量p
//距离向量d
void dijkstra(Mgraph g,int v0,int p[],int d[]){
    bool final[M];//表示当前元素是否已求出最短路劲
    int i,j,k,v,min;
    //第一步，初始化集合S和距离向量d和路径向量p
    for(i=0;i<g.n;i++){
        final[i] = FALSE;      //说明集合S没有元素
        d[i] = g.edges[v0-1][i];  //初始化所有景点到原点距离
        if(d[i]<FINAL && d[i] != 0)  //景点到原点有距离
            p[i] = v0-1;              //前驱是源点
        else
            p[i] = -1;               //没有前驱
    }
    final[v0-1] = TRUE;

    //第二步 依次找出n-1个结点加入S
    for(i=1;i<g.n;i++){
        min = FINAL;
        for(j=0;j<g.n;j++)
            if(!final[j] && d[j]<min){      // !final[j]表示j还在v-s集合中
                v = j;
                min = d[j];
            }
    //    printf("\n%d---%d\n",g.vexs[v],min);  //输出本次入选的景点距离
        if(min == FINAL) return;             //已经没有路径
        final[v] = TRUE;

        //第三步，修改集合v-s中景点到源点的最短路径
        for(k = 0;k<g.n;k++){
            if(!final[k] && d[k] > (min+g.edges[v][k])){
                d[k] = min+g.edges[v][k];
                p[k] = v;
            }
        }
    }
}

/*********************输出有向图所有的最短路径***************************/
//参数：邻接矩阵g
//路径向量p
//距离向量d
//文件中所有景点信息数组palaceArray[]
void printgpd(Mgraph g,int p[],int d[],int v0,palace palaceArray[]){
    int st[M],pre,top = -1;       //定义一个栈并初始化栈
    int i;
    for(i = 0;i<g.n;i++){
        st[++top] = i;
        pre = p[i];
        while(pre != -1){      //从第i个景点开始向前搜索最短路径上的景点
            st[++top] = pre;
            pre = p[pre];
        }
         if(top == 0){
              gotox(4);
              printf("\t\t\t    最短路径(%d)：",i+1);
              if(d[i] == 5000)
                 printf("抱歉，该路径已经关闭。");
              else{
              printf("%s",palaceArray[st[top]].name);
              printf("\n\t\t\t    最短路径长度： %7d米",d[i]);
              if(palaceArray[st[top]].status != 1)
                  printf("\t\t\t    遗憾的是该景点不开放。");
              }
              top--;
          }
          else{
              gotox(4);
              printf("\t\t\t    最短路径(%d)：",i+1);
              if(d[i] == 5000)
                 printf("抱歉，该路径已经关闭。");
              else{
              while(top >= 1){
                  printf("%s-->",palaceArray[st[top]].name);
                  top--;
              }
              printf("%s",palaceArray[st[top]].name);
              if(d[i]==FINAL){
                  printf("\n\t\t\t    抱歉，该路径已经关闭。");
              }
              else
                  printf("\n\t\t\t    最短路径长度： %7d米",d[i]);
              if(palaceArray[st[top]].status != 1)
                   printf("\n\t\t\t    遗憾的是该景点不开放。");
              top--;
              }
          }
    }
}

/*********************输出有向图指定的最短路径***************************/
//参数：文件中所有景点信息数组palaceArray[]
//路径向量p
//距离向量d
//终点信息j,对应的下标为j-1
void printgpd1(int p[],int d[],int j,palace palaceArray[]){
    int st[M],pre,top = -1;       //定义一个栈并初始化栈
    st[++top] = j-1;
    pre = p[j-1];
    while(pre != -1){      //从第i个景点开始向前搜索最短路径上的景点
        st[++top] = pre;
        pre = p[pre];
    }
    printf("最短路径：");
    while(top > 0){
        printf("%s-->",palaceArray[st[top]].name);
        top--;
    }
    printf("%s",palaceArray[st[top]].name);
    if(d[j-1]==FINAL){
        printf("\n抱歉，该路径已关闭");
    }
    else
        printf("\n最短路径长度： %7d米",d[j-1]);
}

/*********************查询目标景点最优路线***************************/
void search1(char currentUserId[]){
    int j,i=0;
    Mgraph g;  //邻接矩阵
    int p[M];  //路径向量
    int d[M];  //距离向量
    int v0;   //起点位置
    int a;   //用于判断返回上一界面
    palace palaceArray[M];
    int palaceTotal;
    user currentUser[1];

    system("cls");    //清除屏幕
    showtime(0);
    printCurrentPalace(); //输出当前景点信息
    gotox(3);

    palaceTotal = readPalaceFromFile(palaceArray,"palace.dat");

    //输出所有景点信息
    while(i<palaceTotal){
        printf("\t\t\t    景点序号：%d\n",i+1);
        printf("\t\t\t    景点名称：%s\n",palaceArray[i].name);
        if(palaceArray[i].status == 1)
            printf("\t\t\t    状态：开放中");
        else
            printf("\t\t\t    状态：关闭中");
        gotox(3);
        i++;
    }

    printf("\t\t\t    输入起点:");
    scanf("%d",&v0);
    while(v0<=0||v0>palaceTotal){
            printf("\n\t\t\t    该景点不存在\n");
            printf("\t\t\t    请重新输入起点:");
            scanf("%d",&v0);
            printf("\n\n");
        }

    printf("\t\t\t    输入终点:");
    scanf("%d",&j);
    while(j<=0||j>palaceTotal){
            printf("\n\t\t\t    该景点不存在\n");
            printf("\t\t\t    请重新输入终点:");
            scanf("%d",&j);
            printf("\n\n");
        }

    creat(&g,"palacegra.txt");
    dijkstra(g,v0,p,d);
    printgpd1(p,d,j,palaceArray);
    if(palaceArray[j-1].status != 1)
        printf("\n遗憾的是该景点不开放。");
    else
         I = j;//改变起点位置下标

    //接下来是记录用户所到景点次数
    j--;
    currentUser[0] = loadUserById(currentUserId);
    deleteUserFromFile(currentUser,1);
    currentUser[0].save[j]+=1;
    writeUserAfterFile(currentUser,"user.dat",1);
    gotox(3);
    printf("\n\t\t\t    按1离开：");
    scanf("%d",&a);
    if(a == 1)
        return;
}

/*********************查询所有目标最短路径**************************/
void search2(){
    Mgraph g;
    int p[M];
    int d[M];
    int v0;
    int a,i=0;
    palace palaceArray[M];
    int palaceTotal;
    system("cls");    //清除屏幕
    showtime(0);
    printCurrentPalace(); //输出当前景点信息
    gotox(3);
    palaceTotal = readPalaceFromFile(palaceArray,"palace.dat");

    while(i<palaceTotal){
        printf("\t\t\t    景点序号：%d\n",i+1);
        printf("\t\t\t    景点名称：%s\n",palaceArray[i].name);
        if(palaceArray[i].status == 1)
            printf("\t\t\t    状态：开放中");
        else
            printf("\t\t\t    状态：暂不开放");
        gotox(3);
        i++;
    }
    printf("\t\t\t    输入起点:");
    scanf("%d",&v0);
    while(v0<=0||v0>palaceTotal){         //确认密码是否相等，不相等就重复循环。
            printf("\n\t\t\t    该景点不存在\n");
            printf("\t\t\t    请重新输入起点:");
            scanf("%d",&v0);
            printf("\n\n");
        }
    creat(&g,"palacegra.txt");
    dijkstra(g,v0,p,d);
    printgpd(g,p,d,v0,palaceArray);
    gotox(3);
    printf("\n\t\t\t    按1离开：");
    scanf("%d",&a);
    if(a == 1)
        return;
}

/****************智能推荐路线1******************/
void recommend(char currentUserId[]){
    int i,a;                //a用于判断是否离开
    Mgraph g;
    int p[M];
    int d[M];
    int max2[3] = {0,0,0};    //储存旅游次数
    int max1[3] = {0,0,0};    //储存旅游次数前三的景点下标
    palace palaceArray[M];
    int palaceTotal;
    user userArray[50];
    user currentUser;
    int userTotal;

    userTotal = readUserFromFile(userArray,"user.dat");// 读取已注册用户个数。
    currentUser=loadUserById(currentUserId);
    currentUser.save[11] = 0;
    palaceTotal = readPalaceFromFile(palaceArray,"palace.dat");
    palaceTotal--;
    userTotal--;
    system("cls");    //清除屏幕
    showtime(0);
    printCurrentPalace(); //输出当前景点信息

    for(i = 0;i<M;i++){
       if(currentUser.save[i]>max2[0]){
            max2[0] = currentUser.save[i];
            max1[0] = i;
       }
    }
    for(i = 0;i<M;i++){
       if(currentUser.save[i]>max2[1] && i!=max1[0]){
            max2[1] = currentUser.save[i];
            max1[1] = i;
       }
    }
    for(i = 0;i<M;i++){
       if(currentUser.save[i]>max2[2] && i!=max1[0] && i!=max1[1]){
            max2[2] = currentUser.save[i];
            max1[2] = i;
       }
    }
    creat(&g,"palacegra.txt");
    dijkstra(g,I,p,d);
    gotox(6);
    for(i = 0;i<3;i++){
        printf("景点序号：%d\n",max1[i]+1);
        printf("景点名称：%s\n",palaceArray[max1[i]].name);
        printf("景点信息：%s\n",palaceArray[max1[i]].descr);
        if(palaceArray[max1[i]].status == 1)
            printf("状态：开放中\n");
        printgpd1(p,d,max1[i]+1,palaceArray);
        gotox(6);
    }
    gotox(3);
    printf("\n\t\t\t    按1离开：");
    scanf("%d",&a);
    if(a == 1)
        return;
}
