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
    printf("��ϵͳʹ�õ��û���������ȫ��int���ͣ���ע���ʱ����ע��\n");
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
        if(flag==1)                                             //����������ʱ������ʾ
        {
            printf("������������Ҫע����˺ţ�\n");             //����ע��
        }
        flag=0;                                     //��ʼ��flag�����ж�
        printf("������ע����˻�����\n");               //�����˻���
        scanf("%s",&account);
        for( int i=0;"0"==user[i].account;i++)         //�ҵ���ȱ�ĵ�һ��
        {
            //if(account==user[i].account)
            if(account==user[i].account)     //���û�ע���˺��������˺��ظ�ʱ��flag���
            {
                printf("���û����Ѿ����ڣ������Ƿ����ע�᣿\n�����Ҫ����ע��������1\n�ܾ�����ע��������2\n");
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
        printf("��û��ע���˻�������ѡ���˳���ϵͳ���ǳ���л��ʹ������ϵͳ����ӭ�´ι���\n");
        return ;
    }
    //for(int i=0;user[i].account!=0;i++)
    for( int i=0;strcmp("0",user[i].account)!=0;i++)                 //�����ҵ����µĿհ��˻�
    {
        ;
    }
   // printf("������ע����˻�����\n");         //�����˻���
    //scanf("%d",&user[i].account);
    //printf("\n");
    strcmp(user[i].account,account);
    printf("��������Ӧע���˻�������\n");    //��������
    scanf("%s",&user[i].password);
    /*
    printf("�������û������֤�ţ�\n");
    scanf("%s",&user[i].id);
     printf("�������û���������\n");
    scanf("%s",&user[i].name);
    printf("�������û����Ա�\n");
    scanf("%s",&user[i].sex);
    printf(��ȷ���û���Ȩ�ޣ�\n�������1���������û�Ϊ������\n�������0���������û�Ϊ��ͨ�û�\n);
    scanf("%d",&user[i].authority);
    */
    printf("\n");

}

int Signup(struct User * user)
{
    //��¼��֤
    printf("��ϵͳʹ�õ��û���������ȫ��int���ͣ��ڵ�¼��ʱ����ע��\n");
    int f=0;
    int Count=3;
    int F=0;
   int Q=0;
   //int id;
    char account,password;
   Begin:
    printf("�������û���:\n");    //�����û���
    scanf("%s",&account);
    for( int i=0;strcmp("0",user[i].account)!=0;i++)
    //for(int i=0;user[i].account!=0;i++)      //�ж��Ƿ���ڸ��˻�
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
               printf("�����Ƿ�����������е�¼��\n���������¼������1\n�����������¼������2\n");
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

        printf("�����Ƿ�����������е�¼��\n���������¼������1\n����ܾ�������¼������2\n");      //����ѡ��Ļ��ᣬ�Ƿ����½�����صĵ�¼���� /*�����������������3*/
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
                   printf("�������������֤�ţ�\n");
                   if(id==user[i].id)
                   {
                      printf("���ѳɹ���¼\n");
                   }

               }*/
               else
               {
                  printf("�����Ƿ�����������е�¼��\n���������¼������1\n����ܾ�������¼������2\n");
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
                      printf("�����������󣬵�¼ʧ��\n");
                      return 1;
                  }

               }


    }
    if(F==1)
    {
        return 1;
    }
    printf("�������¼����:\n");                                       //�����û�����
    scanf("%s",&password);
    for(int j=0;strcmp("0",user[j].account!=0;j++)
    {
        if(strcmp("0",user[j].account==0)    )
        {
            while(Count!=0)
        //while(strcmp(account,user[j].account)==0&&Count!=0)         //�ж��˻��Ĵ���
        {
           // if(password==user[j].password)
            if(password==user[j].password)                   //�˶�����
            {
                printf("������ȷ\n");
                break;
            }
            else
            {
                printf("�������\n");
                printf("��ǰ����ʣ��%d��������ᣬ��������������:\n",Count);  //�Դ����
                scanf("%s",&password);
                Count--;
            }

        }
        if(Count==0)
        {
            if(user[j].password==password)                                    //����ʧ��֮��û�м�����������Ļ���
            {
                printf("����������������޷���½");
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
     printf("������Ŀǰ���е��˻�:\n");
     for(int i=0;user[i].account!='\0';i++)
     {
         printf("%s\n",user[i].account);
     }
    Signin(user);
     printf("������Ŀǰ���е��˻�:\n");
     for(int i=0;user[i].account!=0;i++)
     {
         printf("%s\n",user[i].account);
     }
    int F= Signup(user);
    if(F==0)
        printf("�ɹ���¼�˺�");
        else
    {
        printf("û�и��˺Ż����������˵�¼�˺�");
    }
    return 0;
}
