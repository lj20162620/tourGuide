/****************�û�ע��*****************/
void registe(){
    user a[1];
    user userArray[50];
    int userTotal;
    char passWord1[11];
    int i,b=0;//bΪ0������ע�ᡣ;

    userTotal = readUserFromFile(userArray,"user.dat");// ��ȡ��ע���û�������
    while(b==0){
        a[0].role = 1;   //��ͨ�û�
        system("cls");    //�����Ļ
        printf("\n\n\n\n");
        printf("\t\t\t    ������");
        scanf("%s",a[0].name);
        printf("\n\n");
        while(1){
            printf("\t\t\t    �˺ţ�");
            scanf("%s",a[0].userId);
            if(userSearch(userArray,userTotal,a[0].userId) != -1){
                printf("\t\t\t���˺���ע��!\n");
            }else{
                break;
            }
        }
        printf("\n\n");
        printf("\t\t\t    ���룺");
        scanf("%s",passWord1);
        printf("\n\n");
        printf("\t\t\tȷ�����룺");
        scanf("%s",a[0].passWord);
        printf("\n\n");

        while(strcmp(a[0].passWord,passWord1)!=0){         //ȷ�������Ƿ���ȣ�����Ⱦ��ظ�ѭ����
            printf("\t\t\t������������һ�������\n");
            printf("\t\t\tȷ�����룺");
            scanf("%s",a[0].passWord);
            printf("\n\n");
        }

        encryption(a[0].passWord);//�������

        printf("\t\t\t    �绰��");
        scanf("%s",a[0].phone);
        for(i=0;i<M;i++){
            a[0].save[i] = 0;
        }
        printf("\n\n");
        printf("\t\t\t    ȷ�ϣ�[1]\n");
        printf("\t\t\t�������룺[0]\n");
        printf("\t\t\t  ��ѡ��: [ ]\b\b");
        scanf("%d",&b);
   }
   writeUserAfterFile(a,"user.dat",1);
}

/****************�û���¼*****************/
//�������� �� �û������Ϣ��֤�������û��ṹ�壬���Է��������� user��
user login(){
  system("cls");
  gotox(6);

  char* f = "user.dat";
  int yanZhengMa1;
  int yanZhengMa;
  user s[1];
  int userTotal;
  user userArray[100];
  int index;

  userTotal = readUserFromFile(userArray,f);//��ȡ�ļ�����ע���û�������
  while(1){
      printf("\t\t\t\t\t      �ʹ����ε���ϵͳ-->�û���¼\n");
      printf("\t\t\t\t\t==================================\n");
      printf("\t\t\t\t\t�˺ţ�  [          ]\b\b\b\b\b\b\b\b\b\b\b");
      scanf("%s",s[0].userId);
      printf("\n");

      printf("\t\t\t\t\t���룺  [      ]\b\b\b\b\b\b\b");
      scanf("%s",s[0].passWord);
      printf("\n");

      srand(time(0));
      yanZhengMa=(rand()%1000+1000)*5/3+1234;
      printf("\t\t\t\t\t��֤�룺[    ](%d)\b\b\b\b\b\b\b\b\b\b\b",yanZhengMa);
      scanf("%d",&yanZhengMa1);

      do{
        if(yanZhengMa!=yanZhengMa1){
            printf("��֤�����\n");
        }else{
            break;
        }
        yanZhengMa=(rand()%1000+1000)*5/3+1234;
        printf("\t\t\t\t\t��֤�룺[    ](%d)\b\b\b\b\b\b\b\b\b\b\b",yanZhengMa);
        scanf("%d",&yanZhengMa1);
      }while(yanZhengMa!=yanZhengMa1);

      index = userSearch(userArray,userTotal,s[0].userId);//��ȡ���˺��û����������±ꡣ
      decryption(userArray[index].passWord);//������ܡ�

      if(index == -1){
        printf("\t\t\t\t�û�������!\n");
      }else if(strcmp(userArray[index].passWord,s[0].passWord) != 0){
          printf("\t\t\t\t���벻��ȷ!\n");
      }else{
          break;
      }
  }
  return userArray[index];
}

/****************�û�ģ��*****************/
void userSystem(char currentUserId[]){
    int c,loop=2;
    user userArray[50];
    int userTotal;
    int index;
 //   user currentuser[1];

   userTotal = readUserFromFile(userArray,"user.dat");//��ȡ�ļ�����ע���û�������
  index = userSearch(userArray,userTotal,currentUserId);//��ȡ���˺��û����������±ꡣ
//    currentuser[0]=userArray[index];

    while(loop==2){
        system("cls");
        gotox(2);
        printf("\t%s",userArray[index].name);//��ʾ��ǰ�û�������
        showtime(0);   //��ʾ��ӭ���档
        printCurrentPalace(); //�����ǰ������Ϣ
        c=menuUser();  //��ʾ�û���ɫ���ܲ˵����档
        switch(c){
              case 1: system("cls");
                      printPalace();
                      break;//��ѯ���о�����Ϣ
              case 2: system("cls");
                      search1(currentUserId);
                      break;//��ѯĿ�꾰������·��
              case 3: system("cls");
                      search2();
                      break;//��ѯ����Ŀ�����·��
              case 4: recommend(currentUserId);
				          break;//�����Ƽ�·��

              default:
                      loop=0;
                       break;//�˳�
        }
    }
    return ;
}

/****************����Աģ��*****************/
void adminSystem(char currentUserId[]){
    int c,loop=1;
    user userArray[50];
    int userTotal;
    int index;

    userTotal = readUserFromFile(userArray,"user.dat");//��ȡ�ļ�����ע���û�������
    index = userSearch(userArray,userTotal,currentUserId);//��ȡ���˺��û����������±ꡣ

		while(loop==1){
			system("cls");
            gotox(2);

            printf("\t%s",userArray[index].name);//��ʾ��ǰ�û�������
            showtime(0);   //��ʾ��ӭ���档
            printCurrentPalace(); //�����ǰ������Ϣ
            c=menuAdmin();  //��ʾ�û���ɫ���ܲ˵����档

			switch(c){
				  case 1:  system("cls");
                           printPalace();
                           break;//��ѯ���о�����Ϣ
				  case 2: system("cls");
                           search1(currentUserId);
                           break;//��ѯĿ�꾰������·��
				  case 3: system("cls");
                           search2();
                           break;//��ѯ����Ŀ�����·��
				  case 4:
				           system("cls");
                           modifyPlace();
                           break;//�޸�·����Ϣ
				  case 5:  recommend(currentUserId);
				           break;//�����Ƽ�·��
				  case 6:  system("cls");
                           addPalaceNode();
                           break;//���Ӿ�����Ϣ
				  case 7:  system("cls");
                           deletePalace();
                           break;//ɾ��������Ϣ
				  default:
                           loop=0;
                           break;//�˳�ϵͳ
			}
		}
    return ;
}

/**************�����û���ɫ��ͬ���벻ͬ�Ĺ�����ϵͳ*******************/
void enterSystem(int c,char currentUserId[]){
    switch(c){
        case 0:  adminSystem(currentUserId);break;
        case 1:  userSystem(currentUserId);break;

    }
}
