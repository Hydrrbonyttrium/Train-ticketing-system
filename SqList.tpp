// 构造函数
template <typename T>
SqList<T>::SqList() : elem(nullptr), length(0), listsize(LIST_INIT_SIZE) {
    elem = new T[listsize];
}

// 析构函数
template <typename T>
SqList<T>::~SqList() {
    delete[] elem;
}

// 初始化列表
template <typename T>
Status SqList<T>::InitList() {
    length = 0;
    listsize = LIST_INIT_SIZE;
    elem = new T[listsize];
    return OK;
}

// 销毁列表
template <typename T>
Status SqList<T>::DestroyList() {
    delete[] elem;
    elem = nullptr;
    length = 0;
    listsize = 0;
    return OK;
}

template <typename T>
int SqList<T>::GetLength() {
    return length;
}

// 查找元素
template <typename T>
int SqList<T>::LocateElem(const T& e, Status (*compare)(const T&, const T&)) const {
    for (int i = 0; i < length; ++i) {
        if (compare(elem[i], e)) {
            return i + 1;
        }
    }
    return 0;
}

// 获取元素
template <typename T>
Status SqList<T>::GetElem(int i, T& e) const {
    if (i < 1 || i > length) {
        return ERROR;
    }
    e = elem[i - 1];
    return OK;
}

// 插入元素
template <typename T>
Status SqList<T>::ListInsert(int i, const T& e) {
    if (i < 1 || i > length + 1) {
        return ERROR;
    }

    if (length >= listsize) {
        T* newbase = new T[listsize + LISTINCREMENT];
        if (!newbase) {
            return OVERFLOW;
        }

        for (int j = 0; j < length; ++j) {
            newbase[j] = elem[j];
        }
        delete[] elem;
        elem = newbase;
        listsize += LISTINCREMENT;
    }

    for (int j = length - 1; j >= i - 1; --j) {
        elem[j + 1] = elem[j];
    }

    elem[i - 1] = e;
    ++length;
    return OK;
}

// 删除元素
template <typename T>
Status SqList<T>::ListDelete(int i, T& e) {
    if (i < 1 || i > length) {
        return ERROR;
    }

    e = elem[i - 1];
    for (int j = i; j < length; ++j) {
        elem[j - 1] = elem[j];
    }
    --length;
    return OK;
}

// 打印元素
template <typename T>
void SqList<T>::print(const T& c) const {
    // 这个函数取决于 T 类型的具体结构
    // 例如，如果 T 是一个包含 'name' 和 'account' 的 User 类型，可以这样实现：
    std::cout << "账号: " << c.account << ", 姓名: " << c.name << std::endl;
}

// 遍历列表
template <typename T>
Status SqList<T>::ListTraverse(void (*visit)(const T&)) const {
    for (int i = 0; i < length; ++i) {
        visit(elem[i]);
    }
    return OK;
}

// 查找前驱元素
template <typename T>
Status SqList<T>::PriorElem(const T& cur_e, T& pre_e) const {
    for (int i = 1; i < length; ++i) {
        if (elem[i] == cur_e) {
            pre_e = elem[i - 1];
            return OK;
        }
    }
    return ERROR;
}

// 删除所有特定元素
template <typename T>
Status SqList<T>::DeleteAllX(const T& x) {
    int k = 0;
    for (int i = 0; i < length; ++i) {
        if (!(elem[i] == x)) {
            elem[k++] = elem[i];
        }
    }
    length = k;
    return OK;
}
