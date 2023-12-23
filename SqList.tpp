// ���캯��
template <typename T>
SqList<T>::SqList() : elem(nullptr), length(0), listsize(LIST_INIT_SIZE) {
    elem = new T[listsize];
}

// ��������
template <typename T>
SqList<T>::~SqList() {
    delete[] elem;
}

// ��ʼ���б�
template <typename T>
Status SqList<T>::InitList() {
    length = 0;
    listsize = LIST_INIT_SIZE;
    elem = new T[listsize];
    return OK;
}

// �����б�
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

// ����Ԫ��
template <typename T>
int SqList<T>::LocateElem(const T& e, Status (*compare)(const T&, const T&)) const {
    for (int i = 0; i < length; ++i) {
        if (compare(elem[i], e)) {
            return i + 1;
        }
    }
    return 0;
}

// ��ȡԪ��
template <typename T>
Status SqList<T>::GetElem(int i, T& e) const {
    if (i < 1 || i > length) {
        return ERROR;
    }
    e = elem[i - 1];
    return OK;
}

// ����Ԫ��
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

// ɾ��Ԫ��
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

// ��ӡԪ��
template <typename T>
void SqList<T>::print(const T& c) const {
    // �������ȡ���� T ���͵ľ���ṹ
    // ���磬��� T ��һ������ 'name' �� 'account' �� User ���ͣ���������ʵ�֣�
    std::cout << "�˺�: " << c.account << ", ����: " << c.name << std::endl;
}

// �����б�
template <typename T>
Status SqList<T>::ListTraverse(void (*visit)(const T&)) const {
    for (int i = 0; i < length; ++i) {
        visit(elem[i]);
    }
    return OK;
}

// ����ǰ��Ԫ��
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

// ɾ�������ض�Ԫ��
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
