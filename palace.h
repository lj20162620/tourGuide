typedef int bool;
#define TRUE 1
#define FALSE 0
/*******����printgrd1********/
/*********************/

            void chanStatus(palace p[],int index,int pa);    //�޸ľ���״̬��Ϣ
            void changeWays();                               //�޸�·����Ϣ

/*************************�޸�·����Ϣ**********************/
void modifyPlace(){
    palace palaceArray[M];
    int palaceTotal;
    palaceTotal = readPalaceFromFile(palaceArray,"palace.dat");
    showtime(0);
    int c,i;
    gotox(5);
    int j=0;
          gotox(5);
    printf("\t\t\t             �ʹ����ε���ϵͳ->�޸�·����Ϣ\n");
    printf("\t\t\t===============================================================\n");
    printf("\t\t\t*                       1   ���ľ���״̬                      *\n");
    printf("\t\t\t*                       2   ����Ŀ�꾰��·��                  *\n");
    printf("\t\t\t*                       0   �˳�                              *\n");
    printf("\t\t\t===============================================================\n");
    printf("\t\t\t������ѡ��[ ]\b\b");
    scanf("%d",&c);
    switch(c){
        case 1:system("cls");
                    while(j<palaceTotal){
                        printf("\t\t\t    ������ţ�%d\n",j+1);
                        printf("\t\t\t    �������ƣ�%s\n",palaceArray[j].name);
                        if(palaceArray[j].status == 1)
                            printf("\t\t\t    ״̬��������");
                        else
                            printf("\t\t\t    ״̬���ر���");
                            gotox(3);
                            j++;
                        }
                    printf("\t\t\t    ������Ҫ�����ľ������:");
                    scanf("%d",&i);
                if(i<0||i>palaceTotal)
                    {printf("\n\t\t\t    �Բ��𣬸þ��㲻����"); system("pause");}
                else
                    chanStatus(palaceArray,i-1,palaceTotal);
                 break;
        case 2:system("cls");
                    while(j<palaceTotal){
                        printf("\t\t\t    ������ţ�%d\n",j+1);
                        printf("\t\t\t    �������ƣ�%s\n",palaceArray[j].name);
                        if(palaceArray[j].status == 1)
                            printf("\t\t\t    ״̬��������");
                        else
                            printf("\t\t\t    ״̬���ر���");
                            gotox(3);
                            j++;
                        }
                 changeWays();
                 break;
        default:
                 break;

    }


}
/**********************�޸ľ���״̬************************/
void chanStatus(palace p[],int index,int pa){
    system("cls");
    gotox(4);
    printf("***********�޸ľ���״̬*************\n");
    int ch;
    printf("��ѡ���ˣ�%s \n",p[index].name);
    if(p[index].status==1){
        printf("�þ��㴦�ڿ���״̬ \n �Ƿ���رգ�\n");
        printf("1 : �ر� \t 0 : �뿪\n");
        printf("��ѡ��[ ]\b\b");
        scanf("%d",&ch);
        if(ch == 1){
             p[index].status = 0;
             printf("�þ�������Ϊ�ر�״̬��");
        }
        system("pause");
    }
    else{
        printf("�þ��㴦�ڹر�״̬ \n �Ƿ���򿪣�\n");
        printf("1 : �� \t 0 : �뿪\n");
        printf("��ѡ��[ ]\b\b");
        scanf("%d",&ch);
        if(ch == 1){
             p[index].status = 1;
             printf("�þ�������Ϊ����״̬��");
        }
        system("pause");
    }
    writePalaceToFile(p,"palace.dat",pa);
}
/*********************�޸�·����Ϣ***************************/
void changeWays(){
    int i,ch,l,b;
    gra1 newgra;
    newgra = readTxtInfornatioFromFile(newgra);
    int sta,fin;
    printf("������Ҫ��������ʼ������� : ");
    scanf("%d",&sta);
    printf("������Ҫ�����Ľ���������� : ");
    scanf("%d",&fin);
    for(i=0;i<newgra.a[1];i++){
            if(((newgra.c[i].id1 == sta&&newgra.c[i].id2 == fin)||(newgra.c[i].id2 == sta&&newgra.c[i].id1 == fin))&&newgra.c[i].length != 0)
                    {
                        printf("������֮�����·�� �� ����Ϊ ��%d\n",newgra.c[i].length);
                        printf("�Ƿ񽫴�·���رգ� 1���ر�   0���뿪\n");
                        scanf("%d",&ch);
                        if(ch==1){
                            newgra.a[1]--;
                            newgra.c[i].id1 = 0;
                            newgra.c[i].id2 = 0;
                            newgra.c[i].length = 0;
                            printf("���������·�ѹرգ�\n");
                            i=0;break;
                        }
                        else system("pause");
                    }
        }
                   if(i>=newgra.a[1]) {
                   printf("������֮�䲻����·�� �� \n");
                   printf("�Ƿ񽫸���·���򿪣� 1����  0���뿪\n");
                   scanf("%d",&ch);
                   if(ch==1)  {

                                printf("�������·���ĳ��ȣ�");
                                scanf("%d",&l);
                                newgra.c[newgra.a[1]].id1=sta;
                                newgra.c[newgra.a[1]].id2=fin;
                                newgra.c[newgra.a[1]].length=l;
                                newgra.a[1]++;
                                printf("�ѿ�ͨ������֮�����·\n");
                                system("pause");
                             }
                   else   system("pause");

             }


     b = writeTxtInfornationToFile(&newgra,"palacegra.txt",1);
     b--;

}
/*********************ɾ������***************************/
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
        printf("\t\t\t    ������ţ�%d\n",i+1);
        printf("\t\t\t    �������ƣ�%s\n",palaceArray[i].name);
        if(palaceArray[i].status == 1)
            printf("\t\t\t    ״̬��������");
        else
            printf("\t\t\t    ״̬���ر���");
        gotox(3);
        i++;
    }
    gra = readTxtInfornatioFromFile(gra);
    printf("\t\t\t    ����Ҫɾ���ľ������:");

    scanf("%d",&i);

    I = 1;//�ı����λ���±�
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
        printf("ɾ���ɹ�����1�뿪");
     }
     scanf("%d",&b);
     if(b==1)
        return ;
}

/****************���Ӿ�����Ϣ******************/
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
        printf("\t\t\t    ������ţ�%d\n",i+1);
        printf("\t\t\t    �������ƣ�%s\n",palaceArray[i].name);
        if(palaceArray[i].status == 1)
            printf("\t\t\t    ״̬��������");
        else
            printf("\t\t\t    ״̬���ر���");
        gotox(3);
        i++;
    }
     gra = readTxtInfornatioFromFile(gra);
     while(a==0){
        gotox(6);
         printf("\t\t\t    �������Ӿ������ƣ�");
         scanf("%s",newpalace[0].name);

         gotox(6);
         printf("\t\t\t    �������Ӿ�����Ϣ��");
         scanf("%s",newpalace[0].descr);

         gotox(6);
         printf("\t\t\t    �������Ӿ����Ƿ񿪷ţ�");
         scanf("%d",&newpalace[0].status);
         printf("\n\n");


        j = gra.a[1];
        printf("\t\t\t    �����뾰��·����Ϣ����ӵ�ǰ���㵽����1��������1 300");
        while(i!=1){
                 gra.c[j].id1 = gra.a[0]+1;
                 printf("\n\t\t\t    ������ţ�");
                 scanf("%d",&gra.c[j].id2);
                 printf("\n\t\t\t    ���þ�����룺");
                 scanf("%d",&gra.c[j].length);
                 j++;
                 printf("\n\t\t\t    ���������밴1������������룺");
                 scanf("%d",&i);
            }


        printf("\t\t\t    ȷ�ϣ�[1]\n");
        printf("\t\t\t�������룺[0]\n");
        printf("\t\t\t  ��ѡ��: [ ]\b\b");
        scanf("%d",&a);
     }



     gra.b[gra.a[0]] = gra.a[0]+1;
     gra.a[0]++;
     gra.a[1] = j;
     b = writeTxtInfornationToFile(&gra,"palacegra.txt",1);
     b = writePalaceAfterFile(newpalace,"palace.dat",1);
     if(b!=-1){
        printf("���ӳɹ�����1�뿪");
     }
     scanf("%d",&b);
     if(b==1)
        return;
}


/*********************���������Ϣ***************************/
void printPalace(){
    palace palaceArray[M];
    int palaceTotal;
    int i=0;
    int a=0;
    palaceTotal = readPalaceFromFile(palaceArray,"palace.dat");
    system("cls");    //�����Ļ
    showtime(0);
    printCurrentPalace(); //�����ǰ������Ϣ
    gotox(6);
    if(palaceTotal == 0)
        printf("û�о�����\n");
    while(i<palaceTotal){
        printf("������ţ�%d\n",i+1);
        printf("�������ƣ�%s\n",palaceArray[i].name);
        printf("������Ϣ��%s\n",palaceArray[i].descr);
        if(palaceArray[i].status == 1)
            printf("״̬��������");
        else printf("״̬���ݲ�����");
        gotox(6);
        i++;
    }
    gotox(3);
    printf("\n\t\t\t    ��1�뿪��");
    scanf("%d",&a);
    if(a == 1)
        return;
}

/*********************Dijkstra�㷨��ⵥԴ���·��***************************/
//������ͼ���ڽӾ���g
//Դ��V0
//·������p
//��������d
void dijkstra(Mgraph g,int v0,int p[],int d[]){
    bool final[M];//��ʾ��ǰԪ���Ƿ���������·��
    int i,j,k,v,min;
    //��һ������ʼ������S�;�������d��·������p
    for(i=0;i<g.n;i++){
        final[i] = FALSE;      //˵������Sû��Ԫ��
        d[i] = g.edges[v0-1][i];  //��ʼ�����о��㵽ԭ�����
        if(d[i]<FINAL && d[i] != 0)  //���㵽ԭ���о���
            p[i] = v0-1;              //ǰ����Դ��
        else
            p[i] = -1;               //û��ǰ��
    }
    final[v0-1] = TRUE;

    //�ڶ��� �����ҳ�n-1��������S
    for(i=1;i<g.n;i++){
        min = FINAL;
        for(j=0;j<g.n;j++)
            if(!final[j] && d[j]<min){      // !final[j]��ʾj����v-s������
                v = j;
                min = d[j];
            }
    //    printf("\n%d---%d\n",g.vexs[v],min);  //���������ѡ�ľ������
        if(min == FINAL) return;             //�Ѿ�û��·��
        final[v] = TRUE;

        //���������޸ļ���v-s�о��㵽Դ������·��
        for(k = 0;k<g.n;k++){
            if(!final[k] && d[k] > (min+g.edges[v][k])){
                d[k] = min+g.edges[v][k];
                p[k] = v;
            }
        }
    }
}

/*********************�������ͼ���е����·��***************************/
//�������ڽӾ���g
//·������p
//��������d
//�ļ������о�����Ϣ����palaceArray[]
void printgpd(Mgraph g,int p[],int d[],int v0,palace palaceArray[]){
    int st[M],pre,top = -1;       //����һ��ջ����ʼ��ջ
    int i;
    for(i = 0;i<g.n;i++){
        st[++top] = i;
        pre = p[i];
        while(pre != -1){      //�ӵ�i�����㿪ʼ��ǰ�������·���ϵľ���
            st[++top] = pre;
            pre = p[pre];
        }
         if(top == 0){
              gotox(4);
              printf("\t\t\t    ���·��(%d)��",i+1);
              if(d[i] == 5000)
                 printf("��Ǹ����·���Ѿ��رա�");
              else{
              printf("%s",palaceArray[st[top]].name);
              printf("\n\t\t\t    ���·�����ȣ� %7d��",d[i]);
              if(palaceArray[st[top]].status != 1)
                  printf("\t\t\t    �ź����Ǹþ��㲻���š�");
              }
              top--;
          }
          else{
              gotox(4);
              printf("\t\t\t    ���·��(%d)��",i+1);
              if(d[i] == 5000)
                 printf("��Ǹ����·���Ѿ��رա�");
              else{
              while(top >= 1){
                  printf("%s-->",palaceArray[st[top]].name);
                  top--;
              }
              printf("%s",palaceArray[st[top]].name);
              if(d[i]==FINAL){
                  printf("\n\t\t\t    ��Ǹ����·���Ѿ��رա�");
              }
              else
                  printf("\n\t\t\t    ���·�����ȣ� %7d��",d[i]);
              if(palaceArray[st[top]].status != 1)
                   printf("\n\t\t\t    �ź����Ǹþ��㲻���š�");
              top--;
              }
          }
    }
}

/*********************�������ͼָ�������·��***************************/
//�������ļ������о�����Ϣ����palaceArray[]
//·������p
//��������d
//�յ���Ϣj,��Ӧ���±�Ϊj-1
void printgpd1(int p[],int d[],int j,palace palaceArray[]){
    int st[M],pre,top = -1;       //����һ��ջ����ʼ��ջ
    st[++top] = j-1;
    pre = p[j-1];
    while(pre != -1){      //�ӵ�i�����㿪ʼ��ǰ�������·���ϵľ���
        st[++top] = pre;
        pre = p[pre];
    }
    printf("���·����");
    while(top > 0){
        printf("%s-->",palaceArray[st[top]].name);
        top--;
    }
    printf("%s",palaceArray[st[top]].name);
    if(d[j-1]==FINAL){
        printf("\n��Ǹ����·���ѹر�");
    }
    else
        printf("\n���·�����ȣ� %7d��",d[j-1]);
}

/*********************��ѯĿ�꾰������·��***************************/
void search1(char currentUserId[]){
    int j,i=0;
    Mgraph g;  //�ڽӾ���
    int p[M];  //·������
    int d[M];  //��������
    int v0;   //���λ��
    int a;   //�����жϷ�����һ����
    palace palaceArray[M];
    int palaceTotal;
    user currentUser[1];

    system("cls");    //�����Ļ
    showtime(0);
    printCurrentPalace(); //�����ǰ������Ϣ
    gotox(3);

    palaceTotal = readPalaceFromFile(palaceArray,"palace.dat");

    //������о�����Ϣ
    while(i<palaceTotal){
        printf("\t\t\t    ������ţ�%d\n",i+1);
        printf("\t\t\t    �������ƣ�%s\n",palaceArray[i].name);
        if(palaceArray[i].status == 1)
            printf("\t\t\t    ״̬��������");
        else
            printf("\t\t\t    ״̬���ر���");
        gotox(3);
        i++;
    }

    printf("\t\t\t    �������:");
    scanf("%d",&v0);
    while(v0<=0||v0>palaceTotal){
            printf("\n\t\t\t    �þ��㲻����\n");
            printf("\t\t\t    �������������:");
            scanf("%d",&v0);
            printf("\n\n");
        }

    printf("\t\t\t    �����յ�:");
    scanf("%d",&j);
    while(j<=0||j>palaceTotal){
            printf("\n\t\t\t    �þ��㲻����\n");
            printf("\t\t\t    �����������յ�:");
            scanf("%d",&j);
            printf("\n\n");
        }

    creat(&g,"palacegra.txt");
    dijkstra(g,v0,p,d);
    printgpd1(p,d,j,palaceArray);
    if(palaceArray[j-1].status != 1)
        printf("\n�ź����Ǹþ��㲻���š�");
    else
         I = j;//�ı����λ���±�

    //�������Ǽ�¼�û������������
    j--;
    currentUser[0] = loadUserById(currentUserId);
    deleteUserFromFile(currentUser,1);
    currentUser[0].save[j]+=1;
    writeUserAfterFile(currentUser,"user.dat",1);
    gotox(3);
    printf("\n\t\t\t    ��1�뿪��");
    scanf("%d",&a);
    if(a == 1)
        return;
}

/*********************��ѯ����Ŀ�����·��**************************/
void search2(){
    Mgraph g;
    int p[M];
    int d[M];
    int v0;
    int a,i=0;
    palace palaceArray[M];
    int palaceTotal;
    system("cls");    //�����Ļ
    showtime(0);
    printCurrentPalace(); //�����ǰ������Ϣ
    gotox(3);
    palaceTotal = readPalaceFromFile(palaceArray,"palace.dat");

    while(i<palaceTotal){
        printf("\t\t\t    ������ţ�%d\n",i+1);
        printf("\t\t\t    �������ƣ�%s\n",palaceArray[i].name);
        if(palaceArray[i].status == 1)
            printf("\t\t\t    ״̬��������");
        else
            printf("\t\t\t    ״̬���ݲ�����");
        gotox(3);
        i++;
    }
    printf("\t\t\t    �������:");
    scanf("%d",&v0);
    while(v0<=0||v0>palaceTotal){         //ȷ�������Ƿ���ȣ�����Ⱦ��ظ�ѭ����
            printf("\n\t\t\t    �þ��㲻����\n");
            printf("\t\t\t    �������������:");
            scanf("%d",&v0);
            printf("\n\n");
        }
    creat(&g,"palacegra.txt");
    dijkstra(g,v0,p,d);
    printgpd(g,p,d,v0,palaceArray);
    gotox(3);
    printf("\n\t\t\t    ��1�뿪��");
    scanf("%d",&a);
    if(a == 1)
        return;
}

/****************�����Ƽ�·��1******************/
void recommend(char currentUserId[]){
    int i,a;                //a�����ж��Ƿ��뿪
    Mgraph g;
    int p[M];
    int d[M];
    int max2[3] = {0,0,0};    //�������δ���
    int max1[3] = {0,0,0};    //�������δ���ǰ���ľ����±�
    palace palaceArray[M];
    int palaceTotal;
    user userArray[50];
    user currentUser;
    int userTotal;

    userTotal = readUserFromFile(userArray,"user.dat");// ��ȡ��ע���û�������
    currentUser=loadUserById(currentUserId);
    currentUser.save[11] = 0;
    palaceTotal = readPalaceFromFile(palaceArray,"palace.dat");
    palaceTotal--;
    userTotal--;
    system("cls");    //�����Ļ
    showtime(0);
    printCurrentPalace(); //�����ǰ������Ϣ

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
        printf("������ţ�%d\n",max1[i]+1);
        printf("�������ƣ�%s\n",palaceArray[max1[i]].name);
        printf("������Ϣ��%s\n",palaceArray[max1[i]].descr);
        if(palaceArray[max1[i]].status == 1)
            printf("״̬��������\n");
        printgpd1(p,d,max1[i]+1,palaceArray);
        gotox(6);
    }
    gotox(3);
    printf("\n\t\t\t    ��1�뿪��");
    scanf("%d",&a);
    if(a == 1)
        return;
}
