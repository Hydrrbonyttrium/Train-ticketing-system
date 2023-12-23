#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

#include "Reality.h"
// c2-1.h 线性表的动态分配顺序存储结构
#define LIST_INIT_SIZE 10 // 线性表存储空间的初始分配量
#define LISTINCREMENT 2 // 线性表存储空间的分配增量

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

#include "SqList.tpp" // 包含模板实现

#endif // SQLIST_H_INCLUDED
