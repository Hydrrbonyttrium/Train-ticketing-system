#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

 // c2-1.h ���Ա�Ķ�̬����˳��洢�ṹ
 #define LIST_INIT_SIZE 10 // ���Ա�洢�ռ�ĳ�ʼ������
 #define LISTINCREMENT 2 // ���Ա�洢�ռ�ķ�������
 typedef int ElemType;
// ʵ��SqList�Ĵ洢����
typedef struct SqList
{
    ElemType *elem;
    int length;
    int listsize;

}SqList;

#endif // SQLIST_H_INCLUDED
