#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

#include "Reality.h"
// c2-1.h ���Ա�Ķ�̬����˳��洢�ṹ
#define LIST_INIT_SIZE 10 // ���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 2 // ���Ա�洢�ռ�ķ�������

template <typename T>
class SqList {
public:
    SqList();
    ~SqList();

    Status InitList();
    Status DestroyList();
    int GetLength();
    int LocateElem(const T& e, Status (*compare)(const T&, const T&)) const;
    Status GetElem(int i, T& e) const;
    Status ListInsert(int i, const T& e);
    Status ListDelete(int i, T& e);
    void print(const T& c) const;
    Status ListTraverse(void (*visit)(const T&)) const;
    Status PriorElem(const T& cur_e, T& pre_e) const;
    Status DeleteAllX(const T& x);

private:
    T* elem;
    int length;
    int listsize;
};

#include "SqList.tpp" // ����ģ��ʵ��

#endif // SQLIST_H_INCLUDED
