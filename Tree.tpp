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
        // ��� parent Ϊ�գ�����Ϊ���ڵ�
        root = newNode;
    } else {
        // ���½ڵ���Ϊ parent �ĵ�һ������
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
