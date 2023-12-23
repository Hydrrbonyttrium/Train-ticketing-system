#include "Tree.h"

Tree *createTree(int data) {
  Tree *newNode = new Tree();
  newNode->data = data;
  newNode->left = nullptr;
  newNode->right = nullptr;
  newNode->parent = nullptr;
  return newNode;
}

void insertLeftChild(Tree *root, int data) {
  Tree *newNode = createTree(data);
  newNode->parent = root;
  root->left = newNode;
}

void insertRightChild(Tree *root, int data) {
  Tree *newNode = createTree(data);
  newNode->parent = root;
  root->right = newNode;
}

void preOrderTraversal(Tree *root) {
  if (root == nullptr) {
    return;
  }
  std::cout << root->data << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

void inOrderTraversal(Tree *root) {
  if (root == nullptr) {
    return;
  }
  inOrderTraversal(root->left);
  std::cout << root->data << " ";
  inOrderTraversal(root->right);
}

void postOrderTraversal(Tree *root) {
  if (root == nullptr) {
    return;
  }
  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  std::cout << root->data << " ";
}
