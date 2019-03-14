/****************用户注册*****************/
void registe(){
    user a[1];
    user userArray[50];
    int userTotal;
    char passWord1[11];
    int i,b=0;//b为0则重新注册。;

    userTotal = readUserFromFile(userArray,"user.dat");// 读取已注册用户个数。
    while(b==0){
        a[0].role = 1;   //普通用户
        system("cls");    //清除屏幕
        printf("\n\n\n\n");
        printf("\t\t\t    姓名：");
        scanf("%s",a[0].name);
        printf("\n\n");
        while(1){
            printf("\t\t\t    账号：");
            scanf("%s",a[0].userId);
            if(userSearch(userArray,userTotal,a[0].userId) != -1){
                printf("\t\t\t该账号已注册!\n");
            }else{
                break;
            }
        }
        printf("\n\n");
        printf("\t\t\t    密码：");
        scanf("%s",passWord1);
        printf("\n\n");
        printf("\t\t\t确认密码：");
        scanf("%s",a[0].passWord);
        printf("\n\n");

        while(strcmp(a[0].passWord,passWord1)!=0){         //确认密码是否相等，不相等就重复循环。
            printf("\t\t\t输入密码与上一个不相等\n");
            printf("\t\t\t确认密码：");
            scanf("%s",a[0].passWord);
            printf("\n\n");
        }

        encryption(a[0].passWord);//密码加密

        printf("\t\t\t    电话：");
        scanf("%s",a[0].phone);
        for(i=0;i<M;i++){
            a[0].save[i] = 0;
        }
        printf("\n\n");
        printf("\t\t\t    确认：[1]\n");
        printf("\t\t\t重新输入：[0]\n");
        printf("\t\t\t  请选择: [ ]\b\b");
        scanf("%d",&b);
   }
   writeUserAfterFile(a,"user.dat",1);
}

/****************用户登录*****************/
//函数功能 ： 用户身份信息验证，返回用户结构体，所以返回类型是 user。
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

  userTotal = readUserFromFile(userArray,f);//读取文件中已注册用户个数。
  while(1){
      printf("\t\t\t\t\t      故宫旅游导航系统-->用户登录\n");
      printf("\t\t\t\t\t==================================\n");
      printf("\t\t\t\t\t账号：  [          ]\b\b\b\b\b\b\b\b\b\b\b");
      scanf("%s",s[0].userId);
      printf("\n");

      printf("\t\t\t\t\t密码：  [      ]\b\b\b\b\b\b\b");
      scanf("%s",s[0].passWord);
      printf("\n");

      srand(time(0));
      yanZhengMa=(rand()%1000+1000)*5/3+1234;
      printf("\t\t\t\t\t验证码：[    ](%d)\b\b\b\b\b\b\b\b\b\b\b",yanZhengMa);
      scanf("%d",&yanZhengMa1);

      do{
        if(yanZhengMa!=yanZhengMa1){
            printf("验证码错误\n");
        }else{
            break;
        }
        yanZhengMa=(rand()%1000+1000)*5/3+1234;
        printf("\t\t\t\t\t验证码：[    ](%d)\b\b\b\b\b\b\b\b\b\b\b",yanZhengMa);
        scanf("%d",&yanZhengMa1);
      }while(yanZhengMa!=yanZhengMa1);

      index = userSearch(userArray,userTotal,s[0].userId);//获取该账号用户所在数组下标。
      decryption(userArray[index].passWord);//密码解密。

      if(index == -1){
        printf("\t\t\t\t用户不存在!\n");
      }else if(strcmp(userArray[index].passWord,s[0].passWord) != 0){
          printf("\t\t\t\t密码不正确!\n");
      }else{
          break;
      }
  }
  return userArray[index];
}

/****************用户模块*****************/
void userSystem(char currentUserId[]){
    int c,loop=2;
    user userArray[50];
    int userTotal;
    int index;
 //   user currentuser[1];

   userTotal = readUserFromFile(userArray,"user.dat");//读取文件中已注册用户个数。
  index = userSearch(userArray,userTotal,currentUserId);//获取该账号用户所在数组下标。
//    currentuser[0]=userArray[index];

    while(loop==2){
        system("cls");
        gotox(2);
        printf("\t%s",userArray[index].name);//显示当前用户姓名。
        showtime(0);   //显示欢迎界面。
        printCurrentPalace(); //输出当前景点信息
        c=menuUser();  //显示用户角色功能菜单界面。
        switch(c){
              case 1: system("cls");
                      printPalace();
                      break;//查询所有景点信息
              case 2: system("cls");
                      search1(currentUserId);
                      break;//查询目标景点最优路线
              case 3: system("cls");
                      search2();
                      break;//查询所有目标最短路径
              case 4: recommend(currentUserId);
				          break;//智能推荐路线

              default:
                      loop=0;
                       break;//退出
        }
    }
    return ;
}

/****************管理员模块*****************/
void adminSystem(char currentUserId[]){
    int c,loop=1;
    user userArray[50];
    int userTotal;
    int index;

    userTotal = readUserFromFile(userArray,"user.dat");//读取文件中已注册用户个数。
    index = userSearch(userArray,userTotal,currentUserId);//获取该账号用户所在数组下标。

		while(loop==1){
			system("cls");
            gotox(2);

            printf("\t%s",userArray[index].name);//显示当前用户姓名。
            showtime(0);   //显示欢迎界面。
            printCurrentPalace(); //输出当前景点信息
            c=menuAdmin();  //显示用户角色功能菜单界面。

			switch(c){
				  case 1:  system("cls");
                           printPalace();
                           break;//查询所有景点信息
				  case 2: system("cls");
                           search1(currentUserId);
                           break;//查询目标景点最优路线
				  case 3: system("cls");
                           search2();
                           break;//查询所有目标最短路径
				  case 4:
				           system("cls");
                           modifyPlace();
                           break;//修改路径信息
				  case 5:  recommend(currentUserId);
				           break;//智能推荐路线
				  case 6:  system("cls");
                           addPalaceNode();
                           break;//增加景点信息
				  case 7:  system("cls");
                           deletePalace();
                           break;//删除景点信息
				  default:
                           loop=0;
                           break;//退出系统
			}
		}
    return ;
}

/**************根据用户角色不同进入不同的管理子系统*******************/
void enterSystem(int c,char currentUserId[]){
    switch(c){
        case 0:  adminSystem(currentUserId);break;
        case 1:  userSystem(currentUserId);break;

    }
}
