#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED
#include "Reality.h"
 // c2-1.h ���Ա�Ķ�̬����˳��洢�ṹ
 #define LIST_INIT_SIZE 10 // ���Ա�洢�ռ�ĳ�ʼ������
 #define LISTINCREMENT 2 // ���Ա�洢�ռ�ķ�������
 typedef int ElemType;
// ʵ��SqList�Ĵ洢����
typedef struct SqList
{
    User *elem;
    int length;
    int listsize;

}SqListUser;

Status InitList(SqList &L);
Status DestroyList(SqList &L);
Status comp(ElemType c1, ElemType c2);
int LocateElem(SqList L, ElemType e,Status (* compare)(ElemType, ElemType));
Status GetElem(SqList L,int i,ElemType &e);
Status ListInsert(SqList &L,int i,ElemType e);
Status ListDelete(SqList &L,int i,ElemType &e);
void print(ElemType c);
Status ListTraverse(SqList L,void(* visit)(ElemType));
Status PriorElem(SqList L,ElemType cur_e,ElemType &pre_e);
Status DeleteAllX(SqList &L, ElemType4 x)

#endif // SQLIST_H_INCLUDED
