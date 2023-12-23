#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>

struct Tree {
  int data;
  Tree *left;
  Tree *right;
  Tree *parent;
};

Tree *createTree(int data);
void insertLeftChild(Tree *root, int data);
void insertRightChild(Tree *root, int data);
void preOrderTraversal(Tree *root);
void inOrderTraversal(Tree *root);
void postOrderTraversal(Tree *root);

#endif // TREE_H_INCLUDED
