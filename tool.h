
/*************�����ڼ���******************/

void gotox(int x)      //ǰ���ڼ���
{
    int i;
    for(i=1;i<x;i++)
        printf("\n");
}
/**************д��ͼtxt��Ϣ*******************/
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
        printf("�ļ�����ʧ�ܣ�\n");
        return -1;
    }
}

/**************��ȡͼtxt��Ϣ*******************/
gra1 readTxtInfornatioFromFile(gra1 gra){
    int k;

    FILE *fp=fopen("palacegra.txt","r");
    if(fp!=NULL){
        fscanf(fp,"%d%d",&gra.a[0],&gra.a[1]);  //����ͼ�ö������ͱ���
        for(k=0;k<gra.a[0];k++)
            fscanf(fp,"%d",&gra.b[k]);  //���붥����Ϣ��

        for(k=0;k<gra.a[1];k++){   //�����
            fscanf(fp,"%d%d%d",&gra.c[k].id1,&gra.c[k].id2,&gra.c[k].length);
        }
        fclose(fp);   //�ر��ļ�
    }
    return gra;
}

/****************��ʾ��ǰʱ��**************/
/*
   @�������ƣ�showtime    ��ڲ�����int k

   @�������ܣ���ʾʱ���뻶ӭ����
*/
void showtime(int k)
{
    time_t nowtime;
    struct tm *t;
    time(&nowtime);
    t=localtime(&nowtime);
    if(t->tm_hour>=5&&t->tm_hour<12)
         printf("����� �� \n");
    else
          if(t->tm_hour>=12&&t->tm_hour<18)
            printf("����� �� \n");
              else
                printf("���Ϻ� �� \n");
    switch(k)
    {
        case 0 : printf("��ӭʹ�ùʹ����ε���ϵͳ ��");
        printf("\t ��ǰʱ�� �� %s", ctime(&nowtime));  break;
        case 1 : printf("\t ллʹ�ùʹ����ε���ϵͳ ��");
        printf("\t ��ǰʱ�� �� %s", ctime(&nowtime));     break;
    }
}

/**************�ļ�β��д�뾰����Ϣ�ṹ��*******************/
int writePalaceAfterFile(palace s[],char *f,int n){
    int k;

    FILE *fp=fopen(f,"ab+");
    if(fp!=NULL){
        k = fwrite(s,sizeof(palace),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("�ļ�����ʧ�ܣ�\n");
        return -1;
    }
}

/****************����ͼ���ڽӾ���洢�ṹ******************/
//*gΪָ���ڽӾ����ָ��
//*sָ���ļ���
void creat(Mgraph *g,char *s){
    int i,j,k,w;
    FILE *fp;
    fp = fopen(s,"r");//��ȡ�ļ���Ϣ
    if(fp!=NULL){
        fscanf(fp,"%d%d",&g->n,&g->e);  //����ͼ�ö������ͱ���
        for(i=0;i<g->n;i++)
            fscanf(fp,"%d",&g->vexs[i]);  //���붥����Ϣ��
        for(i=0;i<g->n;i++)//��ʼ���ڽӾ���
            for(j=0;j<g->n;j++)
                if(i==j) g->edges[i][j]=0;
                else g->edges[i][j]=FINAL;
        for(k=0;k<g->e;k++){   //�����
            fscanf(fp,"%d%d%d",&i,&j,&w);
            g->edges[i-1][j-1] = w;    //��������ͼ�ڽӾ���
            g->edges[j-1][i-1] = w;
        }
        fclose(fp);   //�ر��ļ�
    }
    else g->n=0;  //û�д��ļ���û�ж��㣻
}

/***************��palace.dat��ȡ����ṹ����Ϣ********************/
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
        return counter;//���ض�ȡ����
    }else{
        printf("�ļ���ȡʧ��!");
        return 0;
    }
}

/**************����д�뾰��*******************/
int writePalaceToFile(palace palaceArray[],char *f,int n){
    int k;

    FILE *fp=fopen(f,"wb");
    if(fp!=NULL){
        k = fwrite(palaceArray,sizeof(palace),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("�ļ�����ʧ�ܣ�\n");
        return -1;
    }
}

/****************��¼����******************/
int mainMenu(){
    int c;

    system("cls"); gotox(6);
    printf("\t\t\t\t\t            �ʹ����ε���ϵͳ\n");
    printf("\t\t\t\t\t====================================\n");
    printf("\t\t\t\t\t*           1 ��½ϵͳ             *\n");
    printf("\t\t\t\t\t*           0 ���û�ע��ϵͳ       *\n");
    printf("\t\t\t\t\t*          -1 �˳�ϵͳ             *\n");
    printf("\t\t\t\t\t====================================\n");
    printf("\t\t\t\t\t������ѡ��[ ]\b\b");
    scanf("%d",&c);
    return c;
}

/****************�û���¼����******************/
int menuUser(){

    int c;
    gotox(5);
    printf("\t\t\t                          �ʹ����ε���ϵͳ\n");
    printf("\t\t\t===============================================================\n");
    printf("\t\t\t*                       1   ��ѯ���о�����Ϣ                  *\n");
    printf("\t\t\t*                       2   ��ѯĿ�꾰������·��              *\n");
    printf("\t\t\t*                       3   ��ѯ����Ŀ�����·��              *\n");
    printf("\t\t\t*                       4   �����Ƽ�·��                      *\n");
    printf("\t\t\t*                       0   �˳�                              *\n");
    printf("\t\t\t===============================================================\n");
    printf("\t\t\t������ѡ��[ ]\b\b");
    scanf("%d",&c);
    return c;
}

/****************����Ա��¼����******************/
int menuAdmin(){

    int c;
    gotox(5);
    printf("\t\t\t                          �ʹ����ε���ϵͳ\n");
    printf("\t\t\t===============================================================\n");
    printf("\t\t\t*                       1   ��ѯ���о�����Ϣ                  *\n");
    printf("\t\t\t*                       2   ��ѯĿ�꾰������·��              *\n");
    printf("\t\t\t*                       3   ��ѯ����Ŀ�����·��              *\n");
    printf("\t\t\t*                       4   �޸�·����Ϣ                      *\n");
    printf("\t\t\t*                       5   �����Ƽ�·��                      *\n");
    printf("\t\t\t*                       6   ���Ӿ�����Ϣ                      *\n");
    printf("\t\t\t*                       7   ɾ��������Ϣ                      *\n");
    printf("\t\t\t*                       0   �˳�                              *\n");
    printf("\t\t\t===============================================================\n");
    printf("\t\t\t������ѡ��[ ]\b\b");
    scanf("%d",&c);
    return c;
}

/***************��user.dat��ȡ�û���Ϣ********************/
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
        return counter;//���ض�ȡ����
    }else{
        printf("�ļ���ȡʧ��!");
        return 0;
    }
    return -1;
}

/*********��ѯ�û�***************/
int userSearch(user userArray[],int userTotal,char id[]){
    	int i;
    	for(i = 0;i < userTotal;i++){
    		if(strcmp(id,userArray[i].userId) == 0){
    			return i;
    		}
    	}
     return -1;
}

/**************�������*******************/
void encryption(char password[]){
    int i = 0;
    while(password[i] != '\0'){
        password[i] = password[i]^0xba;
        i++;
    }
}

/***************�������***************************/
void decryption(char password[]){
    int i = 0;
    while(password[i] != '\0'){
        password[i] = password[i]^0xba;
        i++;
    }
}

/**************�ļ�β��д���û�*******************/
int writeUserAfterFile(user s[],char *f,int n){
    int k;

    FILE *fp=fopen(f,"ab+");
    if(fp!=NULL){
        k = fwrite(s,sizeof(user),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("�ļ�����ʧ�ܣ�\n");
        return -1;
    }
}


/**************����д���û�*******************/
int writeUserToFile(user userArray[],char *f,int n){
    int k;

    FILE *fp=fopen(f,"wb");
    if(fp!=NULL){
        k = fwrite(userArray,sizeof(user),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("�ļ�����ʧ�ܣ�\n");
        return -1;
    }
}


/***************���ļ���ɾ���û�******************/
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

/*****************����id����user**************************/
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
        printf("�Ҳ����˺�Ϊ%s����",userId);
        exit(-1);
    }
    return p;

}


int I = 1; //���嵱ǰ������ţ�ȫ�ֱ���
/*********************�����ǰ������Ϣ***************************/
void printCurrentPalace(){
    palace palaceArray[M];
    int palaceTotal;
    palace currentPalace;
    palaceTotal = readPalaceFromFile(palaceArray,"palace.dat");
    palaceTotal--;
    currentPalace = palaceArray[I-1];
    printf("\n�㵱ǰ���ھ��㣺(%d)%s\n",I,currentPalace.name);
}
/*********************�����µ�ͼ����Ϣд���ļ�**********************/
//���붥�������������
void saveArraytxt(int t[],char *f,int n){  //t,��������� f �ļ��� n ����
   // int i=0;
    FILE *fp=fopen(f,"w");
     if(fp!=NULL){

           fprintf(fp," %d",t[0]);
           fprintf(fp," %d",t[1]);
            fclose(fp);
    }
    else{
        printf("�ļ�����ʧ�ܣ�\n");
    }

}
//���붥�����


//����ߵ���Ϣ
void saveStructtxt(gra sgra[],char *f,int n){    //��ͼ�ı߽��Ȩ����Ϣ�����ļ�
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
        printf("�ļ�����ʧ�ܣ�\n");
    }

}
/*************ɾ��������Ϣ******************/

void deletePalaceInformation(int i)      //ǰ���ڼ���
{
    int k;
    palace palaceArray[M];
    int palaceTotal;

    palaceTotal = readPalaceFromFile(palaceArray,"palace.dat");
    system("cls");    //�����Ļ
    showtime(0);
    printCurrentPalace(); //�����ǰ������Ϣ
    gotox(6);

    for(k = i;k < palaceTotal;k++){
        palaceArray[k - 1] = palaceArray[k];
    }
    palaceTotal--;
    writePalaceToFile(palaceArray,"palace.dat",palaceTotal);
}
