template <typename T>
Tree<T>::Tree() : root(nullptr) {}

template <typename T>
Tree<T>::~Tree() {
    DestroyTree(root);
}

template <typename T>
TreeNode<T>* Tree<T>::InsertChild(TreeNode<T>* parent, const T& data) {
    TreeNode<T>* newNode = new TreeNode<T>(data);

    if (parent == nullptr) {
        // 如果 parent 为空，则作为根节点
        root = newNode;
    } else {
        // 将新节点作为 parent 的第一个孩子
        if (parent->firstChild) {
            newNode->nextSibling = parent->firstChild;
        }
        parent->firstChild = newNode;
    }

    return newNode;
}

template <typename T>
void Tree<T>::Traverse(TreeNode<T>* node, void (*visit)(const T&)) {
    if (node != nullptr) {
        visit(node->data);
        Traverse(node->firstChild, visit);
        Traverse(node->nextSibling, visit);
    }
}

template <typename T>
void Tree<T>::DestroyTree(TreeNode<T>* node) {
    if (node != nullptr) {
        DestroyTree(node->firstChild);
        DestroyTree(node->nextSibling);
        delete node;
    }
}
