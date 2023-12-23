#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include <iostream>

template <typename T>
struct ListNode {
    T data;
    ListNode<T>* next;

    ListNode(T data, ListNode<T>* next = nullptr) : data(data), next(next) {}
};

template <typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void CreateList(int n);
    void ListInsert(int i, const T& e);
    void ListDelete(int i, T& e);
    int ListLength() const;
    ListNode<T>* GetElemPtr(int i);
    T GetElem(int i);
    int LocateElem(const T& e);
    void ListTraverse(void (*visit)(const T&));
    void print(const T& data);

private:
    ListNode<T>* head;
    void DestroyList();
};

#include "LinkedList.tpp" // 包含模板实现

#endif // LINKLIST_H_INCLUDED
