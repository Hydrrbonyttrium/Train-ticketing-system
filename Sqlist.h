#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED
#include "Reality.h"
 // c2-1.h 线性表的动态分配顺序存储结构
 #define LIST_INIT_SIZE 10 // 线性表存储空间的初始分配量
 #define LISTINCREMENT 2 // 线性表存储空间的分配增量
 typedef int ElemType;
// 实现SqList的存储定义
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
