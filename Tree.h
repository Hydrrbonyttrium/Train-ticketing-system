#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>

template <typename T>
struct TreeNode {
    T data;
    TreeNode<T>* firstChild;
    TreeNode<T>* nextSibling;

    TreeNode(T data) : data(data), firstChild(nullptr), nextSibling(nullptr) {}
};

template <typename T>
class Tree {
public:
    Tree();
    ~Tree();

    TreeNode<T>* InsertChild(TreeNode<T>* parent, const T& data);
    void Traverse(TreeNode<T>* node, void (*visit)(const T&));

private:
    TreeNode<T>* root;

    void DestroyTree(TreeNode<T>* node);
};

#include "Tree.tpp" // 包含模板实现

#endif // TREE_H_INCLUDED

