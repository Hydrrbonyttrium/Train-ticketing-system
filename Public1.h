#ifndef PUBLIC1_H_INCLUDED
#define PUBLIC1_H_INCLUDED

 #include<string.h>
 #include<ctype.h>
 #include<malloc.h> // malloc()��
 #include<limits.h> // INT_MAX��
 #include<stdio.h> // EOF(=^Z��F6),NULL
 #include<stdlib.h> // atoi()
 #include<io.h> // eof()
 #include<math.h> // floor(),ceil(),abs()
 #include<process.h> // exit()
 #include<iostream>
 using namespace std;
 // �������״̬����
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 //Status �Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��
 typedef int Status;
 typedef int Boolean;
#endif // PUBLIC1_H_INCLUDED
