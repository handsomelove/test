#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 用户结构体
struct  User
{
    char account[20];// 定义账户名
    char password[20];//账户密码
    double balance;//账户余额
};
// 账户信息
struct User accounts[] =
 {
    {"10001", "123456", 1000.0},
    {"10002", "654321", 2000.0},
    {"10003", "111111", 5000.0}
 };


//查询用户余额
void selectmoney()
{
    printf("当前余额为：%.2lf\n",accounts->balance);
    char c;
     printf("\t\t是否继续操作？(Y/N): ");
                 scanf("%*c%c",&c);
			     if(c == 'N' || c == 'n')
			     {
			         printf("谢谢使用，正在退卡...\n");
                    exit (0);
			     }
			     else
                    {
                        system("cls");
                         atm_main();
                    }

}

//用户取款
void getmoney()
{
    double amount;
    int sel;
    char c;
    printf("请选择您要取款的金额：\n");
    printf("\t\t*****100.00*****(1)\n");
    printf("\t\t*****200.00*****(2)\n");
    printf("\t\t*****500.00*****(3)\n");
    printf("\t\t*****1000.00*****(4)\n");
    printf("\t\t*****任意金额*****(5)\n");
    scanf("%d",&sel);
    switch(sel)
    {
        case 1:amount=100.00;printf("已取出：%.2lf元\n", amount=100);
        printf("卡内所剩余额为%lf\n",accounts->balance -=amount);break;
        case 2:amount=200.00;printf("已取出：%.2lf元\n", amount=200);
        printf("卡内所剩余额为%lf\n",accounts->balance -=amount);break;
        case 3:amount=500.00;printf("已取出：%.2lf元\n", amount=500);
        printf("卡内所剩余额为%lf\n",accounts->balance -=amount);break;
        case 4:amount=1000.00;printf("已取出：%.2lf元\n", amount=1000);
        printf("卡内所剩余额为%lf\n",accounts->balance -=amount);break;
        case 5:
             printf("请输入取款金额：");
             scanf("%lf", &amount);

             if (amount > accounts->balance)
                {
                   printf("余额不足！\n");
                   break;
                }
             else
              {
                accounts->balance -= amount;
                printf("已取出：%.2lf元\n", amount);
                printf("卡内所剩余额为%lf\n",accounts->balance);
                break;
              }

    } printf("\t\t是否继续操作？(Y/N): ");
                 scanf("%*c%c",&c);
			     if(c == 'N' || c == 'n')
			      {
			          printf("谢谢使用，正在退卡...\n");
			          exit (0);
			        }
			     else
                     {
                        system("cls");
                         atm_main();
                      }

}

//用户存款
void putmoney()
{
  printf("请输入存款金额：");
            double amount;
            scanf("%lf", &amount);
            accounts->balance += amount;
            printf("已存入：%.2lf元，当前余额：%.2lf元\n", amount,accounts->balance);
         char c;
           printf("\t\t是否继续操作？(Y/N): ");
                 scanf("%*c%c",&c);
			     if(c == 'N' || c == 'n')
                    {
                     printf("谢谢使用，正在退卡...\n");
                    exit(0);
			       }
                  else
                    {
                    system("cls");
                    atm_main();
                    }
}

//用户修改密码
// 用户修改密码，有三次试错机会
void changepassword()
{
    int i, attempts = 0,j=0;
    char c;
    char old_password[20];
    static char  new_password[20];

    printf("请输入银行卡密码：");
    scanf("%s", old_password);

    // loop for three attempts
    while (attempts < 3) {
        for (i = 0; i < 3; ++i) {
            if (strcmp(accounts[i].password, old_password) == 0) {
                printf("请输入新密码：");
                scanf("%s", new_password);
                 while (j< 3)
                {
                 if(strcmp( old_password, new_password ) == 0)
                 {
                     printf("\t\t                                              \n");
                     printf("\t\t                                              \n");
                     printf("密码不能设置重复！\n");
                     printf("\t\t                                              \n");
                     printf("\t\t                                              \n");
                   j++;

                 }
                  else if(strcmp( old_password, new_password ) != 0)
                    break;

                  if (j< 3)
                    {
                      printf("请重新输入银行卡密码：");
                      scanf("%s", new_password);
                    }
                   else
                     {
                        printf("输入次数上限，无法修改密码！\n");
                        printf("请前往柜台处理\n");

                       printf("\t\t是否继续操作？(Y/N):");
                        scanf("%*c%c",&c);
                      if(c == 'N' || c == 'n') {
                        printf("谢谢使用，正在退卡...\n");
                        exit(0);
                         }
                        else {
                           system("cls");
                             atm_main();
                             }
                     }
                    }

                        strcpy(accounts[i].password, new_password);
                        printf("密码修改成功！\n");
                        printf("\t\t                                              \n");
                        printf("\t\t                                              \n");
                        printf("\t\t是否继续操作？(Y/N): ");
                        scanf("%*c%c",&c);
                    if(c == 'N' || c == 'n') {
                        printf("谢谢使用，正在退卡...\n");
                        exit(0);
                    }
                    else {
                    system("cls");
                    atm_main();
                    }
            }
        }
        printf("密码不正确！\n");
        attempts++;
        if (attempts < 3) {
            printf("请重新输入银行卡密码：");
            scanf("%s", old_password);
        }
    }
    printf("密码不正确，无法修改密码！\n");
    printf("请前往柜台处理\n");

    printf("\t\t是否继续操作？(Y/N):");
    scanf("%*c%c",&c);
    if(c == 'N' || c == 'n') {
        printf("谢谢使用，正在退卡...\n");
        exit(0);
    }
    else {
        system("cls");
        atm_main();
    }
}


//退卡
void exitam()
{
     printf("谢谢使用，正在退卡...\n");
     exit(0);
}


#define MAX_ACCOUNTS (sizeof(accounts) / sizeof(accounts[0]))

// ATM主页面
void atm_main()
{
    while (1)
    {
        printf("请选择操作：\n");
        printf("\t **********查询余额************(1)\n");
        printf("\t **********取款****************(2)\n");
        printf("\t **********存款****************(3)\n");
        printf("\t **********密码修改************(4)\n");
        printf("\t **********退出****************(5)\n");


        char choice;
        scanf(" %c", &choice);

        switch (choice)
        {
          case '1': {
             selectmoney();
              break;
          }
          case '2': {
              getmoney();
              break;
          }
          case '3': {
             putmoney();
               break;
          }
          case '4':{
            changepassword();
            break;
          }
          case '5': {
            exitam();
              break;
          }
           default: {
               printf("无效选择，请重新输入：\n");
              break;
            }
        }
    }
}

// ATM程序入口
void atm() {
printf("\t\t                                              \n");
        printf("\t\t ^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^\n");
printf("\t\t                                              \n");
printf("\t\t              欢迎使用ATM取款机               \n");
printf("\t\t                                              \n");
printf("\t\t    制作人：邓平川、刘星宇、何俊豪、李奥迪     \n");
printf("\t\t            李文强、阿尔斯‘塔布斯、黄磊             \n");
printf("\t\t                                              \n");
printf("\t\t^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^ \n");
printf("\t\t                                              \n");
printf("\t\t                                              \n");
        printf("                请插入银行卡             \n");
printf("\t\t                                              \n");

    char  account[20],  password[20];
        printf("                请输入账号：      ");
    scanf("%s", account);

    while (1) {

        int i, j;
        for (j = 5; j >= 1; j--)
        {
            printf("\t\t                                              \n");
            printf("               请输入密码：      ");
            scanf("%s", password);
            for (i = 0; i < MAX_ACCOUNTS; ++i)
            {
                if (strcmp(accounts[i].account, account) == 0 && strcmp(accounts[i].password, password) == 0)
                {
                    printf("\t\t                                              \n");
                    printf("验证成功！\n");
                    system("cls");
                    atm_main(&accounts[i]);
                    return;
                }
            }
            printf("密码错误，请重新输入！\n");
            printf("您还有%d次机会\n", j - 1);

        }
        printf("密码错误超过5次，卡被吞，请前往柜台处理！\n");
        break;
    }
}

int main()
{
    atm();
    return 0;
}

