//#include "public.h"
//#include "Login.h"
#include <iostream>
#include <string.h>
using namespace std;

  struct User
{
    string account;
    string password;
    /*int account;
    int password;*/
    /*
    char name;
    char sex;
    char id;
   // char tickets;
    int authority;
    */
};

void Signin(struct User * user)
{
    printf("该系统使用的用户名与密码全是int整型，在注册的时候请注意\n");
    int flag=0;
    int i;
    int x;
    char account;
    /*
      string name;
      string id;
      string sex;
      int authority;
    */
    do
    {
        if(flag==1)                                             //当重新输入时具有提示
        {
            printf("请重新输入想要注册的账号：\n");             //进行注册
        }
        flag=0;                                     //初始化flag便于判断
        printf("请输入注册的账户名：\n");               //输入账户名
        scanf("%s",&account);
        for( int i=0;"0"==user[i].account;i++)         //找到空缺的第一项
        {
            //if(account==user[i].account)
            if(account==user[i].account)     //当用户注册账号与已有账号重复时，flag标记
            {
                printf("该用户名已经存在，请问是否继续注册？\n如果想要继续注册请输入1\n拒绝继续注册请输入2\n");
                scanf("%d",&x);
                if(x==1)
                {
                    flag=1;
                }
                else
                {
                    flag=2;
                }
            }
        }
    }while(flag==1);
    if(flag==2)
    {
        printf("您没有注册账户，并且选择退出该系统，非常感谢您使用我们系统，欢迎下次光临\n");
        return ;
    }
    //for(int i=0;user[i].account!=0;i++)
    for( int i=0;strcmp("0",user[i].account)!=0;i++)                 //遍历找到最新的空白账户
    {
        ;
    }
   // printf("请输入注册的账户名：\n");         //输入账户名
    //scanf("%d",&user[i].account);
    //printf("\n");
    strcmp(user[i].account,account);
    printf("请设置相应注册账户的密码\n");    //设置密码
    scanf("%s",&user[i].password);
    /*
    printf("请输入用户的身份证号：\n");
    scanf("%s",&user[i].id);
     printf("请输入用户的姓名：\n");
    scanf("%s",&user[i].name);
    printf("请输入用户的性别：\n");
    scanf("%s",&user[i].sex);
    printf(请确认用户的权限：\n如果输入1，则代表该用户为管理者\n如果输入0，则代表该用户为普通用户\n);
    scanf("%d",&user[i].authority);
    */
    printf("\n");

}

int Signup(struct User * user)
{
    //登录验证
    printf("该系统使用的用户名与密码全是int整型，在登录的时候请注意\n");
    int f=0;
    int Count=3;
    int F=0;
   int Q=0;
   //int id;
    char account,password;
   Begin:
    printf("请输入用户名:\n");    //输入用户名
    scanf("%s",&account);
    for( int i=0;strcmp("0",user[i].account)!=0;i++)
    //for(int i=0;user[i].account!=0;i++)      //判断是否存在该账户
    {
           if(strcmp("0",user[i].account)!=0    )
           {
               F=0;
               break;
           }
           else
           {
               F=2;
           }
          /* else
           {
               printf("请问是否重新输入进行登录？\n如果继续登录请输入1\n如果不继续登录请输入2\n");
               scanf("%d",&Q);
               if(Q==1)
               {
                   goto Begin;
               }
               else
               {
                   F=1;
               }
           }*/

    }

     if(F==2)
    {

        printf("请问是否重新输入进行登录？\n如果继续登录请输入1\n如果拒绝继续登录请输入2\n");      //给予选择的机会，是否重新进行相关的登录操作 /*如果忘记密码请输入3*/
               scanf("%d",&Q);
               if(Q==1)
               {
                   goto Begin;
               }
               else if(Q==2)
               {
                   F=1;
               }
               /*else if(Q==3)
               {
                   printf("请输入您的身份证号：\n");
                   if(id==user[i].id)
                   {
                      printf("您已成功登录\n");
                   }

               }*/
               else
               {
                  printf("请问是否重新输入进行登录？\n如果继续登录请输入1\n如果拒绝继续登录请输入2\n");
                  int p;
                  scanf("%d",&p);
                  if(p==1)
                  {
                      goto Begin;
                  }
                  else if(p==2)
                  {
                      F=1;
                  }
                  else
                  {
                      printf("您多次输入错误，登录失败\n");
                      return 1;
                  }

               }


    }
    if(F==1)
    {
        return 1;
    }
    printf("请输入登录密码:\n");                                       //输入用户密码
    scanf("%s",&password);
    for(int j=0;strcmp("0",user[j].account!=0;j++)
    {
        if(strcmp("0",user[j].account==0)    )
        {
            while(Count!=0)
        //while(strcmp(account,user[j].account)==0&&Count!=0)         //判断账户的存在
        {
           // if(password==user[j].password)
            if(password==user[j].password)                   //核对密码
            {
                printf("密码正确\n");
                break;
            }
            else
            {
                printf("密码错误\n");
                printf("当前您还剩下%d次输入机会，请重新输入密码:\n",Count);  //试错机会
                scanf("%s",&password);
                Count--;
            }

        }
        if(Count==0)
        {
            if(user[j].password==password)                                    //三次失败之后没有继续输入密码的机会
            {
                printf("三次输入密码错误，无法登陆");
            }
            else
            {
                f=0;
            }
        }
        return f;
    }
    }
    f=1;
    return f;

}

int main()
{
     //struct User user [5]={0001,223818},{"0","0"},{"0","0"},{"0","0"},{"0","0"}};
     struct User user [5]={{"0001","223818"},{"0","0"},{"0","0"},{"0","0"},{"0","0"}};
    // struct User user [5]={{1,223818,"CB","male","3203212003",1},{2,223818,"TX","female","3203212004",0},{0,0,NULL,NULL,NULL,0}};
     printf("以下是目前已有的账户:\n");
     for(int i=0;user[i].account!='\0';i++)
     {
         printf("%s\n",user[i].account);
     }
    Signin(user);
     printf("以下是目前已有的账户:\n");
     for(int i=0;user[i].account!=0;i++)
     {
         printf("%s\n",user[i].account);
     }
    int F= Signup(user);
    if(F==0)
        printf("成功登录账号");
        else
    {
        printf("没有该账号或者您放弃了登录账号");
    }
    return 0;
}
